#include "util.h"
#include <ctime>

int Utils::GetTime()
{
	std::time_t t = std::time(0);
	return static_cast<int>(t);
}

void Utils::StringReplace(std::string & str, std::string oldStr, std::string newStr)
{
	std::string::size_type pos = 0u;
	while ((pos = str.find(oldStr, pos)) != std::string::npos) {
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
}
