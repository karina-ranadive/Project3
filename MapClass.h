#pragma once
#include <map>
#include "Nonprofit.h"
using namespace std;

class MapClass{
    map<string, Nonprofit> orgs;
    map<string, Nonprofit>::iterator iter;
    string category;

public:
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
