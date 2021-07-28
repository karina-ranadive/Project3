#pragma once
#include <string>
#include <iostream>

class Nonprofit
{
    std::string name;
    std::string street;
    int zip;
    std::string state;
    int region;
    std::string NTEE;
    std::string subcategory;
    int subcatNum;


public:
    Nonprofit();
    Nonprofit(std::string name, std::string street, int zip, std::string state, int region, std::string NTEE);
    int matchIndex;
    std::string getStreet();
    int getZip();
    std::string getState();
    int getRegion();
    std::string getNTEE();
    std::string getSubCat();
    void printNonprofit();
    void setSubcat(std::string subcategory);
    void setSubcat(std::string subcategory, int subcatNum);
    void setSubcat(int subcatNum);
    std::string getName();

    friend bool operator < (const Nonprofit& lhs, const Nonprofit& rhs);
    friend bool operator > (const Nonprofit& lhs, const Nonprofit& rhs);
};
