#pragma once
#include <map>
#include <string>
#include <iostream>
#include "Nonprofit.h"
using namespace std;

class Tree {
    Nonprofit* root;
    Nonprofit target;
public:
    Tree(Nonprofit target, map<string, Nonprofit>& orgs);
    Nonprofit* Insert(Nonprofit* root, Nonprofit *obj);
    void InOrder(Nonprofit* root);
    void CalculateMatch(Nonprofit& comp);
    bool IsEmpty();
};