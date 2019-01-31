#pragma once

#include <string>

namespace Utils {
	int GetTime();
	void StringReplace(std::string & str, std::string oldStr, std::string newStr);
	bool IsValidIP(std::string ipAddr);
}