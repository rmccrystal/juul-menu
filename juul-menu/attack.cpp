#include "attack.h"
#include "processutils.h"
#include "util.h"

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
	return true;		// TODO: Get this to work
}

Attacks::AttackOptions Attacks::Attack::GetAttackOptions()
{
	return this->options;
}

int Attacks::Attack::GetTimeLeft()
{
	return this->endTime - this->startTime;
}

std::string Attacks::Attack::GetAttackName()
{
	return this->name;
}

Attacks::Attack::Attack(AttackOptions options, std::string commandTemplate, std::string attackName)
{
	this->command = commandTemplate;
	this->options = options;
	this->name = attackName;
}
/*
* CommandTemplate syntax:
* {{ip}} - ip
* {{port}} - port
* {{time}} - time
*/
std::string Attacks::GenerateAttackCommand(Attacks::AttackOptions attackOptions, std::string commandTemplate)
{
	attackOptions.ipAddr;
	return std::string();
}
