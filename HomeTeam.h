#pragma once
/*
HomeTeam.h
Written by:		Zach Nichols
Date:			2/16/2016
Version:		1.0
*/

#ifndef HOME_TEAM_H
#define HOME_TEAM_H
#include<string>
#include<iostream>
class HomeTeam
{
public:

	HomeTeam(std::string="",double=0,double=0,double=0,double=0); //name,contact offspeed, contact fastball,power offspeed, power fastball

	std::string getName();
	void setName(std::string);
	double getOContact();
	void setOContact(double);
	double getFContact();
	void setFContact(double);
	double getOPower();
	void setOPower(double);
	double getFPower();
	void setFPower(double);
	void hLineup();

		
	
private:
	double OPower;
	double OContact;
	double FPower;
	double FContact;
	std::string name;

};
#endif HOME_TEAM_H
