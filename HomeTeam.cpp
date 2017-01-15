#include "HomeTeam.h"
#include<string>
using namespace std;
HomeTeam::HomeTeam(string name,double FC,double OC,double FP,double OP)
{
	setName(name);
	setFContact(FC);
	setOContact(OC);
	setFPower(FP);
	setOPower(OP);
}

void HomeTeam::setName(string name)
{
	this->name = name;
}
string HomeTeam::getName()
{
	return this->name;
}
void HomeTeam::setFContact(double FC)
{
	this->FContact = FC;
}
double HomeTeam::getFContact()
{
	return this->FContact;
}
void HomeTeam::setOContact(double OC)
{
	this->OContact = OC;
}
double HomeTeam::getOContact()
{
	return this->OContact;
}
void HomeTeam::setFPower(double FC)
{
	this->FPower = FC;
}
double HomeTeam::getFPower()
{
	return this->FPower;
}
void HomeTeam::setOPower(double OP)
{
	this->OPower = OP;
}
double HomeTeam::getOPower()
{
	return this->OPower;
}
void HomeTeam::hLineup()
{
	cout << getName() << "\t \t \t \t";
}
