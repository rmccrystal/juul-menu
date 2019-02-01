#pragma once

#include <string>

namespace Utils {
	int GetTime();
	void StringReplace(std::string & str, std::string oldStr, std::string newStr);
	bool IsValidIP(std::string ipAddr);
	bool StringCompareCaseInsensitive(std::string const& a, std::string const& b);
}