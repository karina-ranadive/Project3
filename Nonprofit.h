#pragma once
#include <string>

class Nonprofit
{
	std::string name;
	std::string street;
	int zip;
	std::string state;
	int region;
	std::string NTEE;
	std::string subcategory;
	
	
public:
	Nonprofit(std::string name, std::string street, int zip, std::string state, int region, std::string NTEE);
	unsigned int matchIndex;
	bool flag;
	std::string getStreet();
	int getZip();
	std::string getState();
	int getRegion();
	int getRevenue();
	std::string getNTEE();
	std::string getSubCat();
	void printNonprofit();
	void setSubcat(std::string subcategory);
};

