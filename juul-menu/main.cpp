#include <cstdio>
#include <iostream>
#include "processutils.h"

int main()
{
    printf("hello from juul_menu!\n");
	std::cout << Utils::RunCommand("ls");
    return 0;
}