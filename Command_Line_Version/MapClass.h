#pragma once
#include <map>
#include "Nonprofit.h"
using namespace std;

class MapClass{
    map<string, Nonprofit> orgs; //this is the STL map that is stored in this map class that stores the names of noprofits as keys and the nonprofit objects as values
    map<string, Nonprofit>::iterator iter; //the class iterator for the map 
    string category;

public: //all the publlic methods and variables 
    MapClass(string category);
    MapClass();
    MapClass* ptr;
    int counter;
    void InsertIntoMap(string name, Nonprofit obj);
    void SearchRegion(int region);
    void SearchName(string name);
    bool FindName(string name);
    void SearchState(string state);
    void SearchZip(string zip);
    void SearchCause(string ntee);
    void SearchSubCat(int subcategory);
    int FindHighestMatchIndex();
    void PrintMatchIndex(int number);
    void Print();
    void CalculateMatches(int region, string state, string zipCode, int subcat);
    void PrintByName(string name);
    void ResetNonProfitVars();
    int getSize();
    map<string, Nonprofit>& GetMap();

};
