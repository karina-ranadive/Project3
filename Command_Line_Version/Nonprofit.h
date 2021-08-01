#pragma once
#include <string>
#include <iostream>
#include <vector>

class Nonprofit
{
    std::string name;
    std::string street;
    std::string zip;
    std::string state;
    int region;
    std::string NTEE;
    std::string subcategory;
    int subcatNum;

public:
    Nonprofit();
    Nonprofit(std::string name, std::string street, std::string zip, std::string state, int region, std::string NTEE);
    int matchIndex;
    int height;
    std::vector<Nonprofit*> sameIndex;
    Nonprofit* left;
    Nonprofit* right;

    std::string getStreet();
    std::string getZip();
    std::string getState();
    int getRegion();
    std::string getNTEE();
    int getSubCatInt();
    std::string getSubCat();
    void printNonprofit();
    void setSubcat(std::string subcategory);
    void setSubcat(std::string subcategory, int subcatNum);
    void setSubcatNum(int subcatNum);
    std::string getName();

    friend bool operator < (const Nonprofit& lhs, const Nonprofit& rhs);
    friend bool operator > (const Nonprofit& lhs, const Nonprofit& rhs);
    friend bool operator <= (const Nonprofit& lhs, const Nonprofit& rhs);
};
