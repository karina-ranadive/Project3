#include "Tree.h"

Tree::Tree(Nonprofit _target, map<string, Nonprofit>& orgs) {
    target = _target;

    for (auto iter = orgs.begin(); iter != orgs.end(); iter++) {
        CalculateMatch(iter->second);
        root = Insert(root, &iter->second);
    }
    traverse(root);
}

Nonprofit* Tree::Insert(Nonprofit* root, Nonprofit* obj) {
    if (root == nullptr)
        return obj;
    else if(obj->matchIndex < root->matchIndex)
        root->left = Insert(root->left, obj);
    else if(obj->matchIndex > root->matchIndex)
        root->right = Insert(root->right, obj);
    else if(obj->matchIndex = root->matchIndex) 
        root->left = Insert(root->left, obj);
    return root;
}

void Tree::traverse(Nonprofit* root) {
    if (root != nullptr) {
        traverse(root->right);
        if (count != 0) {
            root->printNonprofit();
            count--;
            traverse(root->left);
        }
    }
}

void Tree::CalculateMatch(Nonprofit &comp) {
    int match = 0;
    if (target.getRegion() == comp.getRegion())
        match++;
    if (target.getState().compare(comp.getState()) == 0)
        match++;
    if (target.getZip().compare(comp.getZip()) == 0)
        match++;
    if (target.getSubCatInt() == comp.getSubCatInt())
        match++;
    comp.matchIndex = match;
}