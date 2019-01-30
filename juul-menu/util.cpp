#include "util.h"
#include <ctime>

int Utils::GetTime()
{
	std::time_t t = std::time(0);
	return static_cast<int>(t);
}
