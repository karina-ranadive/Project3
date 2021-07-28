#pragma once
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
#include "Nonprofit.h"
using namespace std;

class HeapClass {
    vector<Nonprofit> heap;
    Nonprofit target;
    int end_index;
public:
    HeapClass(Nonprofit target, map<string, Nonprofit>& orgs);
    void HeapifyUp(Nonprofit add);
    void HeapifyDown(int i);
    Nonprofit GetMax();
    void CalculateMatch(Nonprofit& comp);
    bool IsEmpty();
};