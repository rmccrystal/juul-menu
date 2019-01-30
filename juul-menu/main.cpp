#include <cstdio>
#include <iostream>
#include "processutils.h"
#include "attack.h"
#include <unistd.h>

using namespace Attacks;

int main()
{
	std::cout << "Start" << std::endl;
	AttackOptions options;
	options.ipAddr = "127.0.0.1";
	options.port = 420;
	options.time = 5;
	Attack attack = Attack(options, "echo ''test'' | nc {{ip}} {{port}}", "nc");
	attack.StartAttack();
	sleep(100);
	attack.StopAttack();
	std::cout << "attack end" << std::endl;
	std::cin.get();
    return 0;
}