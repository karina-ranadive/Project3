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

void Tree::CalculateMatch(Nonprofit& comp) {
	int match = 0;
	if (target.getRegion() != -1 && target.getRegion() == comp.getRegion())
		match++;
	if (target.getState() != "" && target.getState() == comp.getState())
		match++;
	if (target.getStreet() != "" && target.getStreet() == comp.getStreet())
		match++;
	if (target.getZip() != -1 && target.getZip() == comp.getZip())
		match++;
	if (target.getSubCat() != "" && target.getSubCat() == comp.getSubCat())
		match++;
	comp.matchIndex = match;
}
