#include "Tree.h"
#include "Nonprofit.h"

Nonprofit* Tree::Insert(Nonprofit* root, Nonprofit *obj){

    if(root == nullptr)
        return obj;
    else if(obj->matchIndex < root->matchIndex)
        root->left = Insert(root->left, obj);
    else if(obj->matchIndex > root->matchIndex)
        root->right = Insert(root->right, obj);
    return root;
}
