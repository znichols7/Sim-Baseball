#include "Season.h"
#include<string>
using namespace std;
Season::Season(string name, double wins, double losses, double rf, double ra)
{
	setTeam(name);
	setWins(wins);
	setLosses(losses);
	setRunsPerGame(rf);
	setRunsAgainstPerGame(ra);
}

void Season::setTeam(string name)
{
	this->name = name;
}
string Season::getTeam()
{
	return this->name;
}
void Season::setWins(double wins)
{
	this->Wins = wins;
}
double Season::getWins()
{
	return this->Wins;
}
void Season::setLosses(double losses)
{
	this->Losses = losses;
}
double Season::getLosses()
{
	return this->Losses;
}
void Season::setRunsPerGame(double rf)
{
	this->Runs = rf;
}
double Season::getRunsPerGame()
{
	return this->Runs;
}
void Season::setRunsAgainstPerGame(double ra)
{
	this->RunsAgainst = ra;
}
double Season::getRunsAgainstPerGame()
{
	return this->RunsAgainst;
}
void Season::teamPrint()
{

}
