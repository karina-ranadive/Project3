#include <map>
#pragma once
#include <iostream>
#include "Nonprofit.h"
using namespace std;

class MapClass{
    map<string, Nonprofit> orgs;
    map<string, Nonprofit>::iterator iter;
    string category;

    public:
        MapClass(string category);
        void InsertIntoMap(string name, Nonprofit obj);
        void SearchRegion(int region);
        void SearchName(string name);
        void SearchState(string state);
        void SearchStreet(string street);
        void SearchZip(int zip);
        void SearchCause(string ntee);
        void SearchSubCat(string subcategory);
        int FindHighestMatchIndex();
        void PrintMatchIndex(int number);
        void PrintPreferences(int region, string state, string street, int zipCode, string subcat);
        void PrintbyName(string name);
        void ResetNonProfitVars();

};
