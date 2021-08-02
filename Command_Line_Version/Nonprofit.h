#pragma once
#include <string>
#include <iostream>
#include <vector>

class Nonprofit
{
    // Private class variables
    std::string name;
    std::string street;
    std::string zip;
    std::string state;
    int region;
    std::string NTEE;
    std::string subcategory;
    int subcatNum;

public:
    // Constructors
    Nonprofit();
    Nonprofit(std::string name, std::string street, std::string zip, std::string state, int region, std::string NTEE);
    
    // Public class variables
    int matchIndex;
    int height;
    std::vector<Nonprofit*> sameIndex;
    Nonprofit* left;
    Nonprofit* right;

    // Getters and Setters
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

    // Comparisons
    friend bool operator < (const Nonprofit& lhs, const Nonprofit& rhs);
    friend bool operator > (const Nonprofit& lhs, const Nonprofit& rhs);
    friend bool operator <= (const Nonprofit& lhs, const Nonprofit& rhs);
};
