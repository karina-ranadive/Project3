#pragma once
#include <string>

class Nonprofit
{
	std::string street;
	int zip;
	std::string state;
	int region;
	std::string NTEE;
	std::string subcategory;
	
public:
	Nonprofit(std::string street, int zip, std::string state, int region, std::string NTEE);
	unsigned int matchIndex;
	std::string getStreet();
	int getZip();
	std::string getState();
	int getRegion();
	int getRevenue();
	std::string getNTEE();
	void printNonprofit();
	void setSubcat(std::string subcategory);
};

