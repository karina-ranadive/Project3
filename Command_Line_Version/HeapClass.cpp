#include "HeapClass.h"

//Constructor: creates and populates heap using an input map for specified category, organized by match to target parameters
HeapClass::HeapClass(Nonprofit _target, map<string, Nonprofit>& orgs) {
    //input map will be compatible with desired category
    end_index = -1;
    target = _target;
    //iterate through map to populate heap
    for (auto iter = orgs.begin(); iter != orgs.end(); iter++) {
        CalculateMatch(iter->second);
        //cout << iter->second.getName() << iter->second.matchIndex << endl;
        HeapifyUp(iter->second); //custom comparators in the nonprofit class allow direct comparisons of nonprofits
    }

}

//Algorithm Credit: Lecture Slides "Heaps" by Prof. Kapoor
//Insert into the heap, swapping until every ancestor of the added element is greater than or equal to itsel
void HeapClass::HeapifyUp(Nonprofit add) {
    end_index++;
    int curr_index = end_index;
    int parent_index = floor((end_index - 1) / 2);
    //insert new item into the bottom of the heap
    heap.push_back(add);
    while (parent_index >= 0 && heap.at(parent_index) <= heap.at(curr_index) && parent_index != curr_index) {
        //swap parent and child
        Nonprofit holder = heap.at(parent_index);
        heap.at(parent_index) = heap.at(curr_index);
        heap.at(curr_index) = holder;
        //update indicies
        curr_index = parent_index;
        parent_index = floor((curr_index - 1) / 2);
    }
}

//Algorithm Credit: Lecture Slides "Heaps" by Prof. Kapoor
//Extract from the heap, swapping the first and last element, pushing off the last element, and shifting until the max heap property is met
void HeapClass::HeapifyDown(int i) {
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int swap_index = -1;
    //determine approprite swap
    if (heap.size() > left && (heap.at(left) > heap.at(i)))
        swap_index = left;
    if (heap.size() > right && (heap.at(right) > heap.at(i)) && (heap.at(right) > heap.at(left)))
        swap_index = right;

    if (swap_index != -1) {
        //swap
        Nonprofit holder = heap.at(swap_index);
        heap.at(swap_index) = heap.at(i);
        heap.at(i) = holder;
        HeapifyDown(swap_index);
    }
}

//Extracts the maximum and calls HeapifyDown to balance
Nonprofit HeapClass::GetMax() {

    Nonprofit out_val = heap.at(0);
    out_val.printNonprofit();
    heap.at(0) = heap.at(end_index);
    heap.pop_back();
    end_index--;
    if (heap.size() >= 1)
        HeapifyDown(0);

    return out_val;
}

//Calculates match index - how closely a nonprofit matches the user's preferences
void HeapClass::CalculateMatch(Nonprofit& comp) {
    int match = 0;
    if (target.getRegion() != -1 && target.getRegion() == comp.getRegion())
        match++;
    if (target.getState() != "" && target.getState().compare(comp.getState()) == 0)
        match++;
    if (target.getZip().compare("-1") != 0 && target.getZip() == comp.getZip())
        match++;
    if (target.getSubCatInt() == comp.getSubCatInt())
        match++;
    comp.matchIndex = match;
}

//Accessor
bool HeapClass::IsEmpty() {
    if (heap.size() == 0)
        return true;
    return false;
}
