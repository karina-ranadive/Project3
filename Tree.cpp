#include "Tree.h"
#include "Nonprofit.h"

Tree(Nonprofit target, map<string, Nonprofit>& orgs) {
    for (auto iter = orgs.begin(); iter != orgs.end(); iter++) {
        CalculateMatch(iter->second);
        Insert(iter->second);
    }
}

Nonprofit* Tree::Insert(Nonprofit* root, Nonprofit *obj) {
    if(root == nullptr)
        return obj;
    else if(obj->matchIndex < root->matchIndex)
        root->left = Insert(root->left, obj);
    else if(obj->matchIndex > root->matchIndex)
        root->right = Insert(root->right, obj);
    return root;
}

void Tree::traverse(Nonprofit* root) {
    if (root != nullptr) {
        traverse(root->right);
        root->printNonprofit;
        traverse(root->left);
    }
}

