#include "util.h"
#include <ctime>
#include <functional>

int Utils::GetTime()
{
	const std::time_t t = std::time(nullptr);
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

bool Utils::IsValidIP(std::string ipAddr)
{
	return true;
	// TODO: Make this func work with this regex:
	// ((25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[1-9][0-9]{0,1})\.){3}(25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[1-9][0-9]{0,1})
}

bool Utils::StringCompareCaseInsensitive(std::string const& a, std::string const& b)
{
	const auto icomparePred = [](unsigned const char char1, unsigned const char char2)
	{
		return std::tolower(char1) == std::tolower(char2);
	};
	if (a.length()==b.length()) {
        return std::equal(b.begin(), b.end(),
                           a.begin(), icomparePred);
    }
    else {
        return false;
    }

}
