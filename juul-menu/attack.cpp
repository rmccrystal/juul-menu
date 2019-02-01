#include "attack.h"
#include "processutils.h"
#include "util.h"
#include <algorithm>
#include <iostream>

void Attacks::Attack::StartAttack()
{
	this->startTime = Utils::GetTime();
	this->endTime = this->startTime + this->GetAttackOptions().time;
	this->attackPid = Utils::RunCommand(this->command);
	Utils::RunCommand("sleep " + std::to_string(this->options.time) + " && pkill -P " + std::to_string(this->attackPid));
}

void Attacks::Attack::StopAttack()
{
	std::cout << "stopping attack" << std::endl;
	Utils::KillPid(this->attackPid);
}

bool Attacks::Attack::IsAttackRunning() const
{
	return Utils::ProcessExists(this->attackPid);
}

Attacks::AttackOptions Attacks::Attack::GetAttackOptions() const
{
	return this->options;
}

int Attacks::Attack::GetTimeLeft() const
{
	return this->endTime - this->startTime;
}

int Attacks::Attack::GetAttackPid() const
{
	return this->attackPid;
}

Attacks::AttackType Attacks::Attack::GetAttackType() const
{
	return this->attackType;
}

std::string Attacks::Attack::GetAttackName() const
{
	return this->name;
}

Attacks::Attack::Attack(const AttackOptions options, const std::string commandTemplate, const std::string attackName)
	: options(options), name(attackName), commandTemplate(commandTemplate)
{
	this->attackType = { attackName, commandTemplate };
	this->command = GenerateAttackCommand(options, commandTemplate);
}
Attacks::Attack::Attack(const AttackOptions options, const AttackType attackType)
	: Attack(options, attackType.commandTemplate, attackType.attackName)
{
	
}
Attacks::Attack::~Attack()
{
	StopAttack();
}
/*
* CommandTemplate syntax:
* {{ip}} - ip
* {{port}} - port
* {{time}} - time
*/
std::string Attacks::GenerateAttackCommand(Attacks::AttackOptions attackOptions, std::string commandTemplate)
{
	Utils::StringReplace(commandTemplate, "{{ip}}", attackOptions.ipAddr);
	Utils::StringReplace(commandTemplate, "{{port}}", std::to_string(attackOptions.port));
	Utils::StringReplace(commandTemplate, "{{time}}", std::to_string(attackOptions.time));
	return commandTemplate;
}
