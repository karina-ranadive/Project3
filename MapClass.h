#include <map>
#pragma once
#include <iostream>
#include "Nonprofit.h"
using namespace std;

class MapClass{
    map<string, Nonprofit> orgs;
    map<string, Nonprofit>::iterator iter;

    public:
        MapClass();
        void InsertIntoMap(string name, Nonprofit obj);
        void SearchRegion(int region);
        void SearchName(string name);
        void SearchCause(string ntee);
        int FindHighestMatchIndex();
        void PrintMatchIndex(int number);
        void Print();

};
