#include "HomeStats.h"
#include<string>
#include <iomanip> 

using namespace std;

HomeStats::HomeStats(double ab, double hits, double singles, double doubles, double triples, double hr, double rbi)
{
	setAb(ab);
	setHits(hits);
	setSingles(singles);
	setDoubles(doubles);
	setTriples(triples);
	setHr(hr);
	setRbi(rbi);
}

void HomeStats::setAb(double AB)
{
	this->ab = AB;
}
double HomeStats::getAb()
{
	return this->ab;
}
void HomeStats::setHits(double Hits)
{
	this->hits = Hits;
}
double HomeStats::getHits()
{
	return this->hits;
}
void HomeStats::setSingles(double Singles)
{
	this->singles = Singles;
}
double HomeStats::getSingles()
{
	return this->singles;
}
void HomeStats::setDoubles(double Doubles)
{
	this->doubles = Doubles;
}
double HomeStats::getDoubles()
{
	return this->doubles;
}
void HomeStats::setTriples(double Triples)
{
	this->triples = Triples;
}
double HomeStats::getTriples()
{
	return this->triples;
}
void HomeStats::setHr(double HR)
{
	this->hr = HR;
}
double HomeStats::getHr()
{
	return this->hr;
}
void HomeStats::setRbi(double RBI)
{
	this->rbi = RBI;
}
double HomeStats::getRbi()
{
	return this->rbi;
}

void HomeStats::hStats()
{
	cout << setprecision(3) << (getHits() / getAb()) << "\t" << getHits() << "\t" << getHr() << "\t" << getRbi() << endl;
}
