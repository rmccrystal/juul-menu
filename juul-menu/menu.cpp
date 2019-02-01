#include "menu.h"
#include "dictionary.h"
#include <iostream>
#include "attack.h"
#include "util.h"
#include "attacktype.h"
#include <thread>

namespace Attacks {
	struct AttackType;
	struct AttackOptions;
}

using namespace std;

int Menu::StartMenu()
{
	std::cout << FIRST_START_MESSAGE << std::endl;
	return 0;
}

int Menu::StartAttackFromArgs(const int argc, char* argv[])
{
	Attacks::AttackOptions options;

	if(argc != 5)
	{
		std::cout << "Invalid argument count." << std::endl;
		std::cout << HELP_SYNTAX << std::endl;
		return 1;
	}

	if (Utils::IsValidIP(argv[1])) {
		options.ipAddr = argv[1];
	}
	else {
		std::cout << "Invalid IP";
		return 1;
	}

	options.port = std::atoi(argv[2]);
	options.time = std::atoi(argv[3]);
	const auto type = Attacks::GetAttackType(argv[4]);

	auto attack = Attacks::Attack(options, type);
	attack.StartAttack();
	std::cout << attack.GetAttackType().attackName << " Attack started to " << attack.GetAttackOptions().ipAddr <<
		(attack.GetAttackOptions().port == 0 ? " to a random port" : ":" + std::to_string(attack.GetAttackOptions().port))
		<< " for " << attack.GetAttackOptions().time << " seconds." << std::endl;
	std::cout << "Attack pid: " << attack.GetAttackPid() << std::endl;
	std::cout << "Press enter to stop attack" << std::endl;
	while (attack.IsAttackRunning())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	attack.StopAttack();
	return 0;
}
