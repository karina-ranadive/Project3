#include "HeapClass.h"

HeapClass::HeapClass(Nonprofit _target, map<string, Nonprofit>& orgs) {
	//input map will be compatible with desired category
	end_index = -1;
	target = _target;
	//possibly iterate backwards for alphabetical order
	for (auto iter = orgs.begin(); iter != orgs.end(); iter++) {
		CalculateMatch(iter->second);
		//cout << iter->second.getName() << iter->second.matchIndex << endl;
		HeapifyUp(iter->second);
	}

}

//Algorithm Credit: Lecture Slides "Heaps" by Prof. Kapoor
void HeapClass::HeapifyUp(Nonprofit add) {
	end_index++;
	int curr_index = end_index;
	int parent_index = floor((end_index - 1) / 2);
	//insert new item into the bottom of the heap
	heap.push_back(add);
	while (parent_index >= 0 && heap.at(parent_index) < heap.at(curr_index)) {
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
void HeapClass::HeapifyDown(int i) {
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	int swap_index = -1;
	//determine approprite swap
	if (heap.size() > left && (heap.at(left) > heap.at(i)))
		swap_index = left;
	if (heap.size() > right && (heap.at(right) > heap.at(i)))
		swap_index = right;

	if (swap_index != -1) {
		//swap
		Nonprofit holder = heap.at(swap_index);
		heap.at(swap_index) = heap.at(i);
		heap.at(i) = holder;
		HeapifyDown(swap_index);
	}
}

Nonprofit HeapClass::GetMax() {
	Nonprofit out_val = heap.at(0);
	cout << out_val.getName() << " " << out_val.matchIndex << endl;
	heap.at(0) = heap.at(end_index);
	heap.pop_back();
	end_index--;
	if (heap.size() >= 1)
		HeapifyDown(0);
	return out_val;
}


void HeapClass::CalculateMatch(Nonprofit& comp) {
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

bool HeapClass::IsEmpty() {
	if (heap.size() == 0)
		return true;
	return false;
}