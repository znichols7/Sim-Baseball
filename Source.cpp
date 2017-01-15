#include<iostream>
#include<string>
#include"HomeTeam.h"
#include"AwayTeam.h"
#include"HomeStats.h"
#include"AwayStats.h"
#include"Season.h"
#include<cstdlib>
#include<fstream>
#include "Source.h"
#include <stdlib.h> 
#include <ctime>
#include <iomanip> 
using namespace std;


void open(const string & homeFileName)
{
	int num;
	//open score.txt file and grade.txt file
	fstream inFile(homeFileName.c_str(), ios::in);
	if (inFile.fail())
	{
		cerr << "File could not be opened" << endl;
		cout << homeFileName << endl;
		cin >> num;
		exit(EXIT_FAILURE);
	}
}
void close(const string & homeFileName)
{
	fstream inFile(homeFileName.c_str(), ios::in);
	inFile.close();
}

string hFile()
{
	string home;
	cout << "Who is the home team?" << endl;
	cin >> home;
	return home;
}
string aFile()
{
	string away;
	cout << "Who is the away team?" << endl;
	cin >> away;
	return away;
}

void lineups(HomeTeam homeTeam[],int ht,AwayTeam awayTeam[],int at)
{
	cout << "\t \t" << "Home Team Lineup" << endl;
	cout << "Name" << "\t" << "Contact" << "\t" << "Power" << endl;
	for (int i = 0; i < ht; i++)
	{
		homeTeam[i].hLineup();
	}
	for (int j = 0; j < at; j++)
	{
		awayTeam[j].aLineup();
	};
}
int extraBase() // 40/60 chance runner advances scores from a certain base
{
	int extra = rand() % 100 + 1;
	if (extra>70)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int htHitType(HomeTeam ht) //if the home team gets a hit, this determines what type of hit
{
	int pitchType = rand() % 100 + 1;
	int hit = rand() % 100 + 1;
	double FP = ht.getFPower();
	double OP = ht.getOPower();
	if (pitchType > .5)
	{
		if (hit < .3*FP)
		{
			return 4;
		}
		else if (hit < .4*FP)
		{
			return 3;
		}
		else if (hit < .8*FP)
		{
			return 2;
		}
		else
		{
			return 1;
		}

	}
	else
	{
		if (hit < .3*OP)
		{
			return 4;
		}
		else if (hit < .4*OP)
		{
			return 3;
		}
		else if (hit < .8*OP)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
}

int htHit(HomeTeam ht) //determines the home team outcome of hit or not
{
	int pitchType = rand() % 100 + 1;
	int hit = rand() % 100 + 1;
	double FC = (ht.getFContact())*.300; //formula for rating 1-100; ex. 80 overall BA=.290
	double OC = (ht.getOContact())*.300;
	int result;

	if (pitchType > .5) //fastball
	{
		if (FC>hit) //hit
		{
			result = 1;
		}
		else //out
		{
			result = 0;
		}
	}
	else //offspeed
	{
		if (OC>hit) //hit
		{
			result = 1; 
		}
		else //out
		{
			result = 0;
		}
	}
	return result;
}

int atHitType(AwayTeam at) //if the away team gets a hit, this determines what type of hit
{
	int pitchType = rand() % 100 + 1;
	int hit = rand() % 100 + 1;
	double FP = at.getFPower();
	double OP = at.getOPower();
	if (pitchType > .5)
	{
		if (hit < .3*FP)
		{
			return 4;
		}
		else if (hit < .4*FP)
		{
			return 3;
		}
		else if (hit < .8*FP)
		{
			return 2;
		}
		else
		{
			return 1;
		}

	}
	else
	{
		if (hit < .3*OP)
		{
			return 4;
		}
		else if (hit < .4*OP)
		{
			return 3;
		}
		else if (hit < .8*OP)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
}

int atHit(AwayTeam at) //determines the home team outcome of hit or not
{
	int pitchType = rand() % 100 + 1;
	int hit = rand() % 100 + 1;
	double FC = (at.getFContact()) * .300; //formula for rating 1-100; ex. 80 overall BA=.290
	double OC = (at.getOContact()) * .300;
	int result;
	if (pitchType > .5) //fastball
	{
		
		if (FC>hit) //hit
		{
			result = 1;
		}
		else //out
		{
			result = 0;
		}
	}
	else //offspeed
	{
		
		if (OC>hit) //hit
		{
			result = 1;
		}
		else //out
		{
			result = 0;
		}
	}

	return result;
}

void game()
{
	////////////////////////////////////////
	//game setup
	string quit, homeFileName = "Brewers.txt" , awayFileName = "Cubs.txt", awayTeams, homeTeams;
	const int ht = 9;
	const int at = 9;
	HomeTeam homeTeam[ht];
	AwayTeam awayTeam[at];
	HomeStats homeStats[ht];
	AwayStats awayStats[at];
	int outs = 0, aBatter = 0, hBatter = 0, hitType, extra, first = 0, second = 0, third = 0, count = 0, hHit = 0, aHit = 0;
	double hRuns = 0, aRuns = 0, innings = 0, homeHit = 0, homeSingle = 0, homeDouble = 0, homeTriple = 0, homeHr = 0, homeAb = 0, homeRbi = 0, awayHit = 0, awaySingle = 0, awayDouble = 0, awayTriple = 0, awayHr = 0, awayRbi = 0, awayAb = 0;
	//srand(time(NULL));

	cout << "Home Team: " << endl;
	cin >> homeTeams;
	cout << "Away Team: " << endl;
	cin >> awayTeams;
	homeFileName = homeTeams + ".txt";
	awayFileName = awayTeams + ".txt";

	open(homeFileName);

	fstream inFile(homeFileName.c_str(), ios::in);
		string name = "",name1="";
		double FC = 0, OC = 0, FP = 0, OP = 0;
		//read data from score.txt
		int i = 0;
		while (i<ht)
		{
			inFile >> name1;
			inFile >> name;
			inFile >> FC;
			inFile >> OC;
			inFile >> FP;
			inFile >> OP;
			inFile.ignore();
			name = name1 + " " + name;
			homeTeam[i] = { name, FC, OC, FP, OP };
			i++;
		}
		
	close(homeFileName);

	open(awayFileName);

	fstream in2File(awayFileName.c_str(), ios::in);
	name = "";
	FC = 0, OC = 0, FP = 0, OP = 0;
	//read data from score.txt
	i = 0;
	while (i<at)
	{
		in2File>>name1>>name >> FC >> OC >> FP >> OP;
		name = name1 + " " + name;
		in2File.ignore();
		awayTeam[i] = { name, FC, OC, FP, OP };
		i++;
	}

	close(awayFileName);


	//////////////////////////////////////// 
	//gameplay
	while (innings < 9 || hRuns==aRuns)
	{
		//-------------Away-Team-Now-Bats----------------------/
		while (outs < 3)
		{
			if (atHit(awayTeam[aBatter]) == 1)
			{
				aHit++;
				hitType = atHitType(awayTeam[aBatter]); //single,double,triple,HR
				awayAb = awayStats[aBatter].getAb();
				awayStats[aBatter].setAb(awayAb + 1);
				awayHit = awayStats[aBatter].getHits();
				awayStats[aBatter].setHits(awayHit + 1);

				if (hitType == 1)
				{
					awaySingle = awayStats[aBatter].getSingles();
					awayStats[aBatter].setSingles(awaySingle + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second, he might score or go to third
					{
						extra = extraBase();
						if (extra == 1)
						{
							second = 0;
							aRuns++;
							awayRbi = awayStats[aBatter].getRbi();
							awayStats[aBatter].setRbi(awayRbi + 1);
						}
						else
						{
							second = 0;
							third = 1;
						}
					}
					if (first == 1)//guy on first goes to second
					{
						second = 1;
						first = 0;
					}
					first = 1;
				}

				else if (hitType == 2)
				{
					awayDouble = awayStats[aBatter].getDoubles();
					awayStats[aBatter].setDoubles(awayDouble + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						aRuns++;
						second = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (first == 1)//guy on first goes to third or home
					{
						extra = extraBase();
						if (extra == 1)
						{
							first = 0;
							aRuns++;
							awayRbi = awayStats[aBatter].getRbi();
							awayStats[aBatter].setRbi(awayRbi + 1);
						}
						else
						{
							first = 0;
							third = 1;
						}
					}
					second = 1;
				}

				else if (hitType == 3)
				{
					awayTriple = awayStats[aBatter].getTriples();
					awayStats[aBatter].setTriples(awayTriple + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						aRuns++;
						second = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						aRuns++;
						first = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					third = 1;
				}
				else if (hitType == 4)
				{
					awayHr = awayStats[aBatter].getHr();
					awayStats[aBatter].setHr(awayHr + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						aRuns++;
						second = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						aRuns++;
						first = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					aRuns++;
					awayRbi = awayStats[aBatter].getRbi();
					awayStats[aBatter].setRbi(awayRbi + 1);
				}

			}
			else
			{
				awayAb = awayStats[aBatter].getAb();
				awayStats[aBatter].setAb(awayAb + 1);
				outs++;
			}

			aBatter++;
			if (aBatter >= at)
			{
				aBatter = 0;
			}
		}
		outs = 0;
		innings = innings + .5;
		first = 0;
		second = 0;
		third = 0;
		//-------------Home-Team-Now-Bats----------------------/
		while (outs < 3)
		{
			if (htHit(homeTeam[hBatter]) == 1)
			{
				hHit++;
				hitType = htHitType(homeTeam[hBatter]); //single,double,triple,HR
				homeAb = homeStats[hBatter].getAb();
				homeStats[hBatter].setAb(homeAb + 1);
				homeHit = homeStats[hBatter].getHits();
				homeStats[hBatter].setHits(homeHit + 1);

				if (hitType == 1)
				{
					homeSingle = homeStats[hBatter].getSingles();
					homeStats[hBatter].setSingles(homeSingle + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
						hRuns++;
						third = 0;
					}
					if (second == 1)//if there is a guy on second, he might score or go to third
					{
						extra = extraBase();
						if (extra == 1)
						{
							second = 0;
							hRuns++;
							homeRbi = homeStats[hBatter].getRbi();
							homeStats[hBatter].setRbi(homeRbi + 1);
						}
						else
						{
							second = 0;
							third = 1;
						}
					}
					if (first == 1)//guy on first goes to second
					{
						second = 1;
						first = 0;
					}
					first = 1;
				}

				else if (hitType == 2)
				{
					homeDouble = homeStats[hBatter].getDoubles();
					homeStats[hBatter].setDoubles(homeDouble + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						hRuns++;
						third = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						hRuns++;
						second = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (first == 1)//guy on first goes to third or home
					{
						extra = extraBase();
						if (extra == 1)
						{
							first = 0;
							hRuns++;
							homeRbi = homeStats[hBatter].getRbi();
							homeStats[hBatter].setRbi(homeRbi + 1);
						}
						else
						{
							first = 0;
							third = 1;
						}
					}
					second = 1;
				}

				else if (hitType == 3)
				{
					homeTriple = homeStats[hBatter].getTriples();
					homeStats[hBatter].setTriples(homeTriple + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						hRuns++;
						third = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						hRuns++;
						second = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						hRuns++;
						first = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					third = 1;
				}
				else if (hitType == 4)
				{
					homeHr = homeStats[hBatter].getHr();
					homeStats[hBatter].setHr(homeHr + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						hRuns++;
						third = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						hRuns++;
						second = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						hRuns++;
						first = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					hRuns++;
					homeRbi = homeStats[hBatter].getRbi();
					homeStats[hBatter].setRbi(homeRbi + 1);
				}

			}
			else
			{
				homeAb = homeStats[hBatter].getAb();
				homeStats[hBatter].setAb(homeAb + 1);
				outs++;
			}

			hBatter++;
			if (hBatter >= ht)
			{
				hBatter = 0;
			}
			count++;
		}
		first = 0;
		second = 0;
		third = 0;
		outs = 0;
		innings = innings + .5;

	}


	////////////////////////////////////////
	//prints lineup, closes game
	cout << "\t \t" << "Home Team Lineup" << endl;
	cout << "Name" << "\t \t \t \t \t" << "Average" << "\t" << "Hits" << "\t" << "HR" << "\t" << "RBI" << endl;

	for (int i = 0; i < ht; i++)
	{
		homeTeam[i].hLineup();
		homeStats[i].hStats();
	}
	cout << "\t \t" << "Away Team Lineup" << endl;
	cout << "Name" << "\t \t \t \t \t" << "Average" << "\t" << "Hits" << "\t" << "HR" << "\t" << "RBI" << endl;
	for (int j = 0; j < at; j++)
	{
		awayTeam[j].aLineup();
		awayStats[j].aStats();
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << setw(10) <<  "\t\tR H" << endl;
	cout << setw(10) <<  homeTeams << ":\t" << hRuns << " " << hHit << endl;
	cout << setw(10) <<  awayTeams << ":\t" << aRuns << " " << aHit << endl;
	//cout << "Press any key to continue....." << endl;
	//cin >> quit;
} 
Season seasonMode(string homeFileName,string awayFileName)
{
	////////////////////////////////////////
	//game setup
	string quit, awayTeams, homeTeams;
	const int ht = 9;
	const int at = 9;
	HomeTeam homeTeam[ht];
	AwayTeam awayTeam[at];
	HomeStats homeStats[ht];
	AwayStats awayStats[at];
	int outs = 0, aBatter = 0, hBatter = 0, hitType, extra, first = 0, second = 0, third = 0, count = 0, hHit = 0, aHit = 0;
	double hRuns = 0, aRuns = 0, innings = 0, homeHit = 0, homeSingle = 0, homeDouble = 0, homeTriple = 0, homeHr = 0, homeAb = 0, homeRbi = 0, awayHit = 0, awaySingle = 0, awayDouble = 0, awayTriple = 0, awayHr = 0, awayRbi = 0, awayAb = 0;
	//srand(time(NULL));

	
	homeFileName = homeFileName + ".txt";
	awayFileName = awayFileName + ".txt";

	open(homeFileName);

	fstream inFile(homeFileName.c_str(), ios::in);
	string name = "", name1 = "";
	double FC = 0, OC = 0, FP = 0, OP = 0;
	//read data from score.txt
	int i = 0;
	while (i<ht)
	{
		inFile >> name1;
		inFile >> name;
		inFile >> FC;
		inFile >> OC;
		inFile >> FP;
		inFile >> OP;
		inFile.ignore();
		name = name1 + " " + name;
		homeTeam[i] = { name, FC, OC, FP, OP };
		i++;
	}

	close(homeFileName);

	open(awayFileName);

	fstream in2File(awayFileName.c_str(), ios::in);
	name = "";
	FC = 0, OC = 0, FP = 0, OP = 0;
	//read data from score.txt
	i = 0;
	while (i<at)
	{
		in2File >> name1 >> name >> FC >> OC >> FP >> OP;
		name = name1 + " " + name;
		in2File.ignore();
		awayTeam[i] = { name, FC, OC, FP, OP };
		i++;
	}

	close(awayFileName);


	//////////////////////////////////////// 
	//gameplay
	while (innings < 9 || hRuns == aRuns)
	{
		//-------------Away-Team-Now-Bats----------------------/
		while (outs < 3)
		{
			if (atHit(awayTeam[aBatter]) == 1)
			{
				aHit++;
				hitType = atHitType(awayTeam[aBatter]); //single,double,triple,HR
				awayAb = awayStats[aBatter].getAb();
				awayStats[aBatter].setAb(awayAb + 1);
				awayHit = awayStats[aBatter].getHits();
				awayStats[aBatter].setHits(awayHit + 1);

				if (hitType == 1)
				{
					awaySingle = awayStats[aBatter].getSingles();
					awayStats[aBatter].setSingles(awaySingle + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second, he might score or go to third
					{
						extra = extraBase();
						if (extra == 1)
						{
							second = 0;
							aRuns++;
							awayRbi = awayStats[aBatter].getRbi();
							awayStats[aBatter].setRbi(awayRbi + 1);
						}
						else
						{
							second = 0;
							third = 1;
						}
					}
					if (first == 1)//guy on first goes to second
					{
						second = 1;
						first = 0;
					}
					first = 1;
				}

				else if (hitType == 2)
				{
					awayDouble = awayStats[aBatter].getDoubles();
					awayStats[aBatter].setDoubles(awayDouble + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						aRuns++;
						second = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (first == 1)//guy on first goes to third or home
					{
						extra = extraBase();
						if (extra == 1)
						{
							first = 0;
							aRuns++;
							awayRbi = awayStats[aBatter].getRbi();
							awayStats[aBatter].setRbi(awayRbi + 1);
						}
						else
						{
							first = 0;
							third = 1;
						}
					}
					second = 1;
				}

				else if (hitType == 3)
				{
					awayTriple = awayStats[aBatter].getTriples();
					awayStats[aBatter].setTriples(awayTriple + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						aRuns++;
						second = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						aRuns++;
						first = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					third = 1;
				}
				else if (hitType == 4)
				{
					awayHr = awayStats[aBatter].getHr();
					awayStats[aBatter].setHr(awayHr + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						aRuns++;
						third = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						aRuns++;
						second = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						aRuns++;
						first = 0;
						awayRbi = awayStats[aBatter].getRbi();
						awayStats[aBatter].setRbi(awayRbi + 1);
					}
					aRuns++;
					awayRbi = awayStats[aBatter].getRbi();
					awayStats[aBatter].setRbi(awayRbi + 1);
				}

			}
			else
			{
				awayAb = awayStats[aBatter].getAb();
				awayStats[aBatter].setAb(awayAb + 1);
				outs++;
			}

			aBatter++;
			if (aBatter >= at)
			{
				aBatter = 0;
			}
		}
		outs = 0;
		innings = innings + .5;
		first = 0;
		second = 0;
		third = 0;
		//-------------Home-Team-Now-Bats----------------------/
		while (outs < 3)
		{
			if (htHit(homeTeam[hBatter]) == 1)
			{
				hHit++;
				hitType = htHitType(homeTeam[hBatter]); //single,double,triple,HR
				homeAb = homeStats[hBatter].getAb();
				homeStats[hBatter].setAb(homeAb + 1);
				homeHit = homeStats[hBatter].getHits();
				homeStats[hBatter].setHits(homeHit + 1);

				if (hitType == 1)
				{
					homeSingle = homeStats[hBatter].getSingles();
					homeStats[hBatter].setSingles(homeSingle + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
						hRuns++;
						third = 0;
					}
					if (second == 1)//if there is a guy on second, he might score or go to third
					{
						extra = extraBase();
						if (extra == 1)
						{
							second = 0;
							hRuns++;
							homeRbi = homeStats[hBatter].getRbi();
							homeStats[hBatter].setRbi(homeRbi + 1);
						}
						else
						{
							second = 0;
							third = 1;
						}
					}
					if (first == 1)//guy on first goes to second
					{
						second = 1;
						first = 0;
					}
					first = 1;
				}

				else if (hitType == 2)
				{
					homeDouble = homeStats[hBatter].getDoubles();
					homeStats[hBatter].setDoubles(homeDouble + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						hRuns++;
						third = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						hRuns++;
						second = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (first == 1)//guy on first goes to third or home
					{
						extra = extraBase();
						if (extra == 1)
						{
							first = 0;
							hRuns++;
							homeRbi = homeStats[hBatter].getRbi();
							homeStats[hBatter].setRbi(homeRbi + 1);
						}
						else
						{
							first = 0;
							third = 1;
						}
					}
					second = 1;
				}

				else if (hitType == 3)
				{
					homeTriple = homeStats[hBatter].getTriples();
					homeStats[hBatter].setTriples(homeTriple + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						hRuns++;
						third = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						hRuns++;
						second = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						hRuns++;
						first = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					third = 1;
				}
				else if (hitType == 4)
				{
					homeHr = homeStats[hBatter].getHr();
					homeStats[hBatter].setHr(homeHr + 1);
					if (third == 1)//if there is a guy on third he scores
					{
						hRuns++;
						third = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (second == 1)//if there is a guy on second he scores
					{
						hRuns++;
						second = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					if (first == 1)//guy on first he scores
					{
						hRuns++;
						first = 0;
						homeRbi = homeStats[hBatter].getRbi();
						homeStats[hBatter].setRbi(homeRbi + 1);
					}
					hRuns++;
					homeRbi = homeStats[hBatter].getRbi();
					homeStats[hBatter].setRbi(homeRbi + 1);
				}

			}
			else
			{
				homeAb = homeStats[hBatter].getAb();
				homeStats[hBatter].setAb(homeAb + 1);
				outs++;
			}

			hBatter++;
			if (hBatter >= ht)
			{
				hBatter = 0;
			}
			count++;
		}
		first = 0;
		second = 0;
		third = 0;
		outs = 0;
		innings = innings + .5;

	}


	////////////////////////////////////////
	//prints lineup, closes game
	double wins=0, losses=0;
	if (hRuns > aRuns)
	{
		wins = 1;
	}
	else
	{
		losses = 1;
	}
	Season season(homeFileName, wins, losses, hRuns, aRuns);
	return season;

}
string pickTeam()
{
	string name;
	int team = rand() % 4 + 1;
	if (team == 1)
	{
		name = "Cubs";
	}
	else if (team == 2)
	{
		name = "Pirates";
	}
	else if (team == 3)
	{
		name = "Reds";
	}
	else
	{
		name = "Cardinals";
	}
	return name;

}
int main()
{
	srand(time(NULL));
	string yourTeam;
	int options=0;
	while (options != 3)
	{
		cout << "1. Play Game" << endl;
		cout << "2. Season Mode" << endl;
		cout << "3. exit" << endl;
		cin >> options;
		if (options == 1)
		{
			game();
		}
		if (options == 2)
		{
			double wins = 0, losses = 0, runs = 0, runsAgainst = 0;
			cout << "Your Team: " << endl;
			cin >> yourTeam;
			Season season[162];
			for (int i = 0; i < 162; i++)
			{
				season[i] = { seasonMode(yourTeam,pickTeam()) };
				wins = wins + season[i].getWins();
				losses = losses + season[i].getLosses();
				runs = runs + season[i].getRunsPerGame();
				runsAgainst = runsAgainst + season[i].getRunsAgainstPerGame();
			}
			runs = runs / 162;
			runsAgainst = runsAgainst / 162;
			cout << "Season for the " << yourTeam << endl;
			cout << "Wins - Losses: " << setprecision(3) << wins << " - " << setprecision(3) << losses << endl;
			cout << "Runs per Game: " << setprecision(3) << runs << " Runs Against per Game: " << setprecision(3) << runsAgainst << endl;
		}
	}
}