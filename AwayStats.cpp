#include "AwayStats.h"
#include<string>
#include <iomanip> 
using namespace std;

AwayStats::AwayStats(double ab, double hits, double singles, double doubles, double triples, double hr, double rbi)
{
	setAb(ab);
	setHits(hits);
	setSingles(singles);
	setDoubles(doubles);
	setTriples(triples);
	setHr(hr);
	setRbi(rbi);
}

void AwayStats::setAb(double AB)
{
	this->ab = AB;
}
double AwayStats::getAb()
{
	return this->ab;
}
void AwayStats::setHits(double Hits)
{
	this->hits = Hits;
}
double AwayStats::getHits()
{
	return this->hits;
}
void AwayStats::setSingles(double Singles)
{
	this->singles = Singles;
}
double AwayStats::getSingles()
{
	return this->singles;
}
void AwayStats::setDoubles(double Doubles)
{
	this->doubles = Doubles;
}
double AwayStats::getDoubles()
{
	return this->doubles;
}
void AwayStats::setTriples(double Triples)
{
	this->triples = Triples;
}
double AwayStats::getTriples()
{
	return this->triples;
}
void AwayStats::setHr(double HR)
{
	this->hr = HR;
}
double AwayStats::getHr()
{
	return this->hr;
}
void AwayStats::setRbi(double RBI)
{
	this->rbi = RBI;
}
double AwayStats::getRbi()
{
	return this->rbi;
}

void AwayStats::aStats()
{
	cout << setprecision(3) << (getHits() / getAb()) << "\t" << getHits() << "\t" << getHr() << "\t" << getRbi() << endl;
}
