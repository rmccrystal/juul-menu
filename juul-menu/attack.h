#pragma once
#include <string>

namespace Attacks {
	struct AttackOptions {
		std::string *ipAddr;
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
		AttackOptions options;
		int attackPid;
		int startTime;
		int endTime;
		std::string command;
		std::string name;
	public:
		void StartAttack();
		void StopAttack();
		bool IsAttackRunning();
		AttackOptions GetAttackOptions();
		int GetTimeLeft();
		std::string GetAttackName();
		Attack(AttackOptions options, std::string commandTemplate, std::string attackName);
	};
}
