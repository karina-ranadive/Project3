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
    std::string getStreet();
    int getZip();
    std::string getState();
    int getRegion();
    std::string getNTEE();
    std::string getSubCat();
    void printNonprofit();
    void setSubcat(std::string subcategory);
};
