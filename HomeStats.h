#pragma once
/*
HomeStats.h
Written by:		Zach Nichols
Date:			2/16/2016
Version:		1.0
*/

#ifndef HOME_STATS_H
#define HOME_STATS_H
#include<string>
#include<iostream>
class HomeStats
{
public:

	HomeStats(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0); //AB,hits,singles,doubles,triples,HR

	double getAb();
	void setAb(double);
	double getHits();
	void setHits(double);
	double getSingles();
	void setSingles(double);
	double getDoubles();
	void setDoubles(double);
	double getTriples();
	void setTriples(double);
	double getHr();
	void setHr(double);
	double getRbi();
	void setRbi(double);
	void hStats();


private:
	double hits;
	double ab;
	double singles;
	double doubles;
	double triples;
	double hr;
	double rbi;
};
#endif HOME_TEAM_H
