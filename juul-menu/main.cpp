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
	if(argc == 1)
	{
		return Menu::StartMenu();
	}
	else {
		return Menu::StartAttackFromArgs(argc, argv);
	}
}