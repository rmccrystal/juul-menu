#pragma once

#include <string>
#include "attacktype.h"

namespace Attacks {
	struct AttackOptions {
		std::string ipAddr;
		int port;		// If port is 0 then the port will be randomized
		int time;
	};

	/*
	* CommandTemplate syntax:
	* {{ip}} - ip
	* {{port}} - port
	* {{time}} - time
	*/
	std::string GenerateAttackCommand(AttackOptions attackOptions, std::string commandTemplate);

	class Attack {
	protected:
		AttackOptions options{};
		int attackPid{};
		int startTime{};
		int endTime{};
		std::string command{};
		std::string name{};
		std::string commandTemplate{};
		AttackType attackType{};
	public:
		void StartAttack();
		void StopAttack();
		bool IsAttackRunning() const;
		AttackOptions GetAttackOptions() const;
		int GetTimeLeft() const;
		int GetAttackPid() const;
		AttackType GetAttackType() const;
		std::string GetAttackName() const;
		Attack(AttackOptions options, std::string commandTemplate, std::string attackName);
		Attack(AttackOptions options, AttackType attackType);
		~Attack();
	};
}
