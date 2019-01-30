#include "processutils.h"

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>

pid_t Utils::RunCommand(std::string cmd, int * infp, int * outfp)
{
	const char* command = cmd.c_str();
	int p_stdin[2];
	int p_stdout[2];
	pid_t pid;

	if (pipe(p_stdin) == -1)
		return -1;

	if (pipe(p_stdout) == -1) {
		close(p_stdin[0]);
		close(p_stdin[1]);
		return -1;
	}

	pid = fork();

	if (pid < 0) {
		close(p_stdin[0]);
		close(p_stdin[1]);
		close(p_stdout[0]);
		close(p_stdout[1]);
		return pid;
	}
	else if (pid == 0) {
		close(p_stdin[1]);
		dup2(p_stdin[0], 0);
		close(p_stdout[0]);
		dup2(p_stdout[1], 1);
		dup2(::open("/dev/null", O_RDONLY), 2);
		/// Close all other descriptors for the safety sake.
		for (int i = 3; i < 4096; ++i)
			::close(i);

		setsid();
		execl("/bin/sh", "sh", "-c", command, NULL);
		_exit(1);
	}

	close(p_stdin[0]);
	close(p_stdout[1]);

	if (infp == NULL) {
		close(p_stdin[1]);
	}
	else {
		*infp = p_stdin[1];
	}

	if (outfp == NULL) {
		close(p_stdout[0]);
	}
	else {
		*outfp = p_stdout[0];
	}

	return pid;
}

bool Utils::ProcessExists(int pid)
{
	return false;
}

void Utils::KillPid(int pid)
{
	kill(pid, SIGTERM);
}
