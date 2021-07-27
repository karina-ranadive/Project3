//
// Created by Karina Ranadive on 7/26/21.
//

#ifndef PROJECT3TESTING_NONPROFIT_H
#define PROJECT3TESTING_NONPROFIT_H
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


public:
    Nonprofit();
    Nonprofit(std::string name, std::string street, int zip, std::string state, int region, std::string NTEE);
    int matchIndex;
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


#endif //PROJECT3TESTING_NONPROFIT_H
