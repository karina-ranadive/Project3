#include "Tree.h"

Tree::Tree(Nonprofit _target, map<string, Nonprofit>& orgs) {
    target = _target;

    int test = -1;
    // Runs through orgs to calculate match index and insert into tree
    for (auto iter = orgs.begin(); iter != orgs.end(); iter++) {
        CalculateMatch(iter->second);
        root = Insert(root, &iter->second);
        test--;
        if (test == 0) {
            break;
        }
    }
    // Traverses tree
    traverse(root);
}

//Citation: Referenced Balanced Tree Module Slides
// Rotates left in respect to given node
Nonprofit* Tree::rotateLeft(Nonprofit* root) {
    Nonprofit* b = root->right;
    Nonprofit* c = b->right;
    Nonprofit* x = b->left;

    root->right = x;
    b->left = root;

    root->height = getHeight(root);
    b->height = getHeight(b);

    return b;
}

//Citation: Referenced Balanced Tree Module Slides
// Rotates right in respect to given node
Nonprofit* Tree::rotateRight(Nonprofit* root) {
    Nonprofit* b = root->left;
    Nonprofit* a = b->left;
    Nonprofit* y = b->right;

    root->left = y;
    b->right = root;

    root->height = getHeight(root);
    b->height = getHeight(b);

    return b;
}

//Citation: Referenced Balanced Tree Module Slides
// Caculates given node's height
int Tree::getHeight(Nonprofit* root) {
    int heightL;
    int heightR;

    if (root != nullptr) {
        heightL = getHeight(root->left);
        heightR = getHeight(root->right);
        return std::max(heightL, heightR) + 1;
    }
    return 0;
}

//Citation: Referenced Balanced Tree Module Slides
// Calculates balance factor for given node
int Tree::balanceFactor(Nonprofit* root) {
    if (root != nullptr) {
        return getHeight(root->left) - getHeight(root->right);
    }
    return 0;
}

//Citation: Lecture Slides: Trees 1 "Binary Search Tree: C++ Insert"
Nonprofit* Tree::Insert(Nonprofit* root, Nonprofit* obj) {
    // Recursively inserts node into tree
    if (root == nullptr)
        return obj;
    else if (obj->matchIndex < root->matchIndex)
        root->left = Insert(root->left, obj);
    else if (obj->matchIndex > root->matchIndex)
        root->right = Insert(root->right, obj);
    else if (obj->matchIndex == root->matchIndex)
        root->sameIndex.push_back(obj);

    root->height = getHeight(root);

    int factor = balanceFactor(root);

    // Rebalances tree through required rotations
    if (factor < -1 && obj->matchIndex > root->right->matchIndex)
        return rotateLeft(root);
    if (factor > 1 && obj->matchIndex < root->left->matchIndex)
        return rotateRight(root);
    if (factor > 1 && obj->matchIndex > root->left->matchIndex)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (factor < -1 && obj->matchIndex < root->right->matchIndex)
    {
        root->right = rotateLeft(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Traverse tree through backwards inorder
void Tree::traverse(Nonprofit* root) {
    if (root != nullptr) {
        traverse(root->right);
        if (count != 0) {
            root->printNonprofit();
            count--;
            for (int i = 0; i < root->sameIndex.size(); i++) {
                root->sameIndex.at(i)->printNonprofit();
                count--;
                if (count == 0)
                    break;
            }
            if (count != 0)
                traverse(root->left);
        }
    }
}

// Calculates match based on user preferences
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
