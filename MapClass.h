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
    MapClass* ptr;
    int counter;
    MapClass();
    int getSize();
    void InsertIntoMap(string name, Nonprofit obj);
    void SearchRegion(int region);
    void SearchName(string name);
    bool FindName(string name);
    void SearchState(string state);
    void SearchStreet(string street);
    void SearchZip(string zip);
    void SearchCause(string ntee);
    void SearchSubCat(int subcategory);
    int FindHighestMatchIndex();
    void PrintMatchIndex(int number);
    void Print();
    void PrintRemaining();
    void PrintPreferences(int region, string state, string zipCode, int subcat);
    void PrintByName(string name);
    void ResetNonProfitVars();
    map<string, Nonprofit>& GetMap();

};
