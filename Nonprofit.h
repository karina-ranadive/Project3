#pragma once
#include <string>

class Nonprofit
{
	std::string street;
	int zip;
	std::string state;
	int region;
	int revenue;
	std::string NTEE;
	int matchIndex;
public:
	Nonprofit(std::string street, int zip, std::string state, int regeion, int revenue, std::string NTEE);
	std::string getStreet();
	int getZip();
	std::string getState();
	int getRegion();
	int getRevenue();
	std::string getNTEE();
	int getMatchIndex();
	void setMatchIndex(int matchIndex);
	void printNonprofit();
};

