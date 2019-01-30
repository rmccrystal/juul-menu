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
}

void Attacks::Attack::StopAttack()
{
	Utils::KillPid(this->attackPid);
}

bool Attacks::Attack::IsAttackRunning()
{
	return Utils::ProcessExists(this->attackPid);
}

Attacks::AttackOptions Attacks::Attack::GetAttackOptions()
{
	return this->options;
}

int Attacks::Attack::GetTimeLeft()
{
	return this->endTime - this->startTime;
}

int Attacks::Attack::GetAttackPid()
{
	return this->attackPid;
}

std::string Attacks::Attack::GetAttackName()
{
	return this->name;
}

Attacks::Attack::Attack(AttackOptions options, std::string commandTemplate, std::string attackName)
	: commandTemplate(commandTemplate), options(options), name(attackName)
{
	this->command = GenerateAttackCommand(options, commandTemplate);
}
Attacks::Attack::Attack(AttackOptions options, AttackType attackType)
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
