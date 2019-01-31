#include <cstdio>
#include <iostream>
#include "processutils.h"
#include "attack.h"
#include <unistd.h>
#include "dictionary.h"
#include "menu.h"
#include "util.h"

using namespace Attacks;

int main(int argc, char *argv[])
{
	if (argc == 0) {
		Menu::StartMenu();
	}

	AttackOptions options;
	AttackType type;

	if (Utils::IsValidIP(argv[1])) {
		options.ipAddr = argv[1];
	}
	else {
		std::cout << "Invalid IP";
	}

	options.port = std::atoi(argv[2]);
	options.time = std::atoi(argv[3]);
	
	return 0;
}