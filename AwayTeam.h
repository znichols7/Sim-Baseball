#pragma once
/*
AwayTeam.h
Written by:		Zach Nichols
Date:			2/16/2016
Version:		1.0
*/

#ifndef AWAY_TEAM_H
#define AWAY_TEAM_H
#include<string>
#include<iostream>

class AwayTeam
{
public:

	AwayTeam(std::string = "", double = 0, double = 0, double = 0, double = 0); //name,contact offspeed, contact fastball,power offspeed, power fastball

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
	void aLineup();



private:
	double OPower;
	double OContact;
	double FPower;
	double FContact;
	std::string name;

};
#endif AWAY_TEAM_H
