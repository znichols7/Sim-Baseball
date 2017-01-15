#include "AwayTeam.h"
#include<string>
using namespace std;
AwayTeam::AwayTeam(string name, double FC, double OC, double FP, double OP)
{
	setName(name);
	setFContact(FC);
	setOContact(OC);
	setFPower(FP);
	setOPower(OP);
}

void AwayTeam::setName(string name)
{
	this->name = name;
}
string AwayTeam::getName()
{
	return this->name;
}
void AwayTeam::setFContact(double FC)
{
	this->FContact = FC;
}
double AwayTeam::getFContact()
{
	return this->FContact;
}
void AwayTeam::setOContact(double OC)
{
	this->OContact = OC;
}
double AwayTeam::getOContact()
{
	return this->OContact;
}
void AwayTeam::setFPower(double FC)
{
	this->FPower = FC;
}
double AwayTeam::getFPower()
{
	return this->FPower;
}
void AwayTeam::setOPower(double OP)
{
	this->OPower = OP;
}
double AwayTeam::getOPower()
{
	return this->OPower;
}
void AwayTeam::aLineup()
{
	cout << getName() << "\t \t \t \t";
}
