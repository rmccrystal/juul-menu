#pragma once

#include "attack.h"
#include <vector>

namespace Attacks {
	struct AttackType {
		std::string attackName;
		std::string commandTemplate;
	};
	AttackType GetAttackType(const std::string name);
}