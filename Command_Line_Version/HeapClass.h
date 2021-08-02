#pragma once
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
#include "Nonprofit.h"
using namespace std;

class HeapClass {
    //class member variables
    vector<Nonprofit> heap;
    Nonprofit target;
    int end_index;
public:
    //constructor
    HeapClass(Nonprofit target, map<string, Nonprofit>& orgs);
    //Heap methods
    void HeapifyUp(Nonprofit add);
    void HeapifyDown(int i);
    Nonprofit GetMax();
    void CalculateMatch(Nonprofit& comp);
    bool IsEmpty();
};
