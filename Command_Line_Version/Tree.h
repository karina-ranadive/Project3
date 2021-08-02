#pragma once
#include <map>
#include <string>
#include <iostream>
#include "Nonprofit.h"
#include "MapClass.h"
using namespace std;

class Tree {
    // Private class variables
    Nonprofit* root = nullptr;
    Nonprofit target;
    int count = 100;
public:
    // AVL tree functions
    Tree(Nonprofit _target, map<string, Nonprofit>& orgs);
    Nonprofit* rotateLeft(Nonprofit* root);
    Nonprofit* rotateRight(Nonprofit* root);
    int getHeight(Nonprofit* root);
    int balanceFactor(Nonprofit* root);
    Nonprofit* Insert(Nonprofit* root, Nonprofit *obj);
    void traverse(Nonprofit* root);
    void CalculateMatch(Nonprofit& comp);
};
