#pragma once
#include <map>
#include <string>
#include <iostream>
#include "Nonprofit.h"
#include "MapClass.h"
using namespace std;

class Tree {
    Nonprofit* root = nullptr;
    Nonprofit target;
    int count = 10;
public:
    Tree(Nonprofit _target, map<string, Nonprofit>& orgs);
    Nonprofit* Insert(Nonprofit* root, Nonprofit *obj);
    void traverse(Nonprofit* root);
    void CalculateMatch(Nonprofit& comp);
};