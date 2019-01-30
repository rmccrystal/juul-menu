#pragma once

#include <string>

namespace Utils {
	pid_t RunCommand(std::string cmd, int * infp = nullptr, int * outfp = nullptr);
	bool ProcessExists(int pid);
	void KillPid(int pid);
}