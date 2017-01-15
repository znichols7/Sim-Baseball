#pragma once
/*
Season.h
Written by:		Zach Nichols
Date:			5/23/2016
Version:		2.0
*/

#ifndef SEASON_H
#define SEASON_H
#include<string>
#include<iostream>
class Season
{
public:

	Season(std::string = "", double = 0, double = 0, double = 0, double = 0); //team name, wins,losses, runs for per game, runs against per game

	std::string getTeam();
	void setTeam(std::string);
	double getWins();
	void setWins(double);
	double getLosses();
	void setLosses(double);
	double getRunsPerGame();
	void setRunsPerGame(double);
	double getRunsAgainstPerGame();
	void setRunsAgainstPerGame(double);
	void teamPrint();



private:
	double Wins;
	double Losses;
	double Runs;
	double RunsAgainst;
	std::string name;

};
#endif SEASON_H
