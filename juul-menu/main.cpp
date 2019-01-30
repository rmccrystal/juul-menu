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
	options.time = 30;
	Attack attack = Attack(options, "sleep 5 && echo ''test'' | nc {{ip}} {{port}}", "ping");
	attack.StartAttack();
	std::cout << attack.GetAttackPid() << std::endl;
	sleep(1);
	attack.StopAttack();
	std::cout << "attack end" << std::endl;
	std::cin.get();
    return 0;
}