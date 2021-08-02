
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <chrono>
#include <time.h>
#include <vector>
using namespace std;
//CLASSES


//NONPROFIT CLASS
class Nonprofit
{
	// Private class variables
	std::string name;
	std::string street;
	std::string zip;
	std::string state;
	int region;
	std::string NTEE;
	std::string subcategory;
	int subcatNum;
public:
	// Constructors
	Nonprofit();
	Nonprofit(std::string name, std::string street, std::string zip, std::string state, int region, std::string NTEE);
	
	// Public class variables
	int matchIndex;
	int height;
	std::vector<Nonprofit*> sameIndex;
	Nonprofit* left;
	Nonprofit* right;
	
	// Getters and Setters
	std::string getStreet();
	std::string getZip();
	std::string getState();
	int getRegion();
	std::string getNTEE();
	int getSubCatInt();
	std::string getSubCat();
	void printNonprofit();
	void setSubcat(std::string subcategory);
	void setSubcat(std::string subcategory, int subcatNum);
	void setSubcatNum(int subcatNum);
	std::string getName();
	std::string getInfo();
	std::string getFileInfo();

	// Comparisons
	friend bool operator < (const Nonprofit& lhs, const Nonprofit& rhs);
	friend bool operator > (const Nonprofit& lhs, const Nonprofit& rhs);
};


// Constructor to assign all necessary class variables
Nonprofit::Nonprofit(std::string name, std::string street, std::string zip, std::string state, int region, std::string NTEE) {
	this->name = name;
	this->street = street;
	this->zip = zip;
	this->state = state;
	this->region = region;
	this->NTEE = NTEE;
	matchIndex = 0;
	left = nullptr;
	right = nullptr;
	subcatNum = 0;
}

Nonprofit::Nonprofit() {

}

// Getter functions
std::string Nonprofit::getStreet() {
	return street;
}

std::string Nonprofit::getZip() {
	return zip;
}

std::string Nonprofit::getState() {
	return state;
}

int Nonprofit::getRegion() {
	return region;
}

std::string Nonprofit::getNTEE() {
	return NTEE;
}

int Nonprofit::getSubCatInt() {
	return subcatNum;
}

std::string Nonprofit::getSubCat() {
	return this->subcategory;
}

// Prints nonprofit info
void Nonprofit::printNonprofit() {
	std::cout << name << " " << matchIndex << std::endl;
}

// Setter functions
void Nonprofit::setSubcat(std::string subcategory) {
	this->subcategory = subcategory;
}

void Nonprofit::setSubcat(std::string subcategory, int subcatNum) {
	this->subcategory = subcategory;
	subcatNum = subcatNum;
}

void Nonprofit::setSubcatNum(int subcatNum) {
	this->subcatNum = subcatNum;    //create a map for subcat nums -> subcat names
}

// Getter functions
std::string Nonprofit::getName() {
	return name;
}

std::string Nonprofit::getInfo() {
	return name + "\n" + street + ", " + state + "," + zip + "\n--------------------------------------------------\n";
}

std::string Nonprofit::getFileInfo() {
	return name + "," + street + "," + state + "," + zip + "\n";
}

// Comparisons
bool operator < (const Nonprofit& lhs, const Nonprofit& rhs) {
	return lhs.matchIndex < rhs.matchIndex;
}
bool operator > (const Nonprofit& lhs, const Nonprofit& rhs) {
	return lhs.matchIndex > rhs.matchIndex;

}

bool operator <= (const Nonprofit& lhs, const Nonprofit& rhs) {
	return lhs.matchIndex <= rhs.matchIndex;
}


//MAP CLASS

class MapClass {
	map<string, Nonprofit> orgs;
	map<string, Nonprofit>::iterator iter;
	string category;

public:
	MapClass(string category);
	MapClass* ptr;
	int counter;
	MapClass();
	int getSize();
	void InsertIntoMap(string name, Nonprofit obj);
	void SearchRegion(int region);
	void SearchName(string name);
	bool FindName(string name);
	void SearchState(string state);
	void SearchStreet(string street);
	void SearchZip(string zip);
	void SearchCause(string ntee);
	void SearchSubCat(int subcategory);
	int FindHighestMatchIndex();
	string PrintMatchIndex(int number);
	string PrintRemaining();
	string PrintPreferences(int region, string state, string zipCode, int subcat);
	string PrintByName(string name);
	void ResetNonProfitVars();
	void CalculateMatches(int region, string state, string zipCode, int subcat);
	string Print();
	map<string, Nonprofit>& GetMap();

};

MapClass::MapClass(string category) {
	this->category = category;
	this->counter = 0;
	ptr = nullptr;
}

MapClass::MapClass() {

}

void MapClass::InsertIntoMap(string name, Nonprofit obj) {
	orgs[name] = obj;
}

void MapClass::SearchRegion(int region) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.getRegion() == region) {
			iter->second.matchIndex++;
		}
	}
}

void MapClass::SearchName(string name) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->first == name) {
			iter->second.matchIndex++;
		}
	}
}

bool MapClass::FindName(string name) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->first == name) {
			return true;
		}
	}
	return false;
}

void MapClass::SearchState(string state) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.getState() == state) {
			iter->second.matchIndex++;
		}
	}
}

void MapClass::SearchStreet(string street) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.getStreet() == street) {
			iter->second.matchIndex++;
		}
	}
}

void MapClass::SearchZip(string zipCode) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.getZip().compare(zipCode) == 0) {
			iter->second.matchIndex++;
		}
	}
}

void MapClass::SearchCause(string ntee) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.getNTEE() == ntee) {
			iter->second.matchIndex++;
		}
	}
}

void MapClass::SearchSubCat(int subcategory) {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.getSubCatInt() == subcategory) {
			iter->second.matchIndex++;
		}
	}
}

int MapClass::FindHighestMatchIndex() {
	int num = -1;
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (iter->second.matchIndex > num) {
			num = iter->second.matchIndex;
		}
	}
	return num;
}

int MapClass::getSize() {
	return orgs.size();
}


string MapClass::PrintPreferences(int region, string state, string zipCode, int subcat) {
	if (region != -1) {
		SearchRegion(region);
	}
	if (state != "") {
		SearchState(state);
	}

	if (zipCode.compare("-1") != 0) {
		SearchZip(zipCode);
	}
	if (subcat != -1) {
		SearchSubCat(subcat);
	}

	return PrintRemaining();


}



string MapClass::PrintMatchIndex(int number) {
	string out_string = "";
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		if (counter == 100) {
			break;
		}
		if (iter->second.matchIndex == number) {
			counter++;
			out_string += to_string(counter) + ". " + iter->second.getInfo();
		}
	}
	return out_string;
}

string MapClass::PrintRemaining() {
	string out_string = "";
	int highest = FindHighestMatchIndex();
	for (unsigned int i = highest; i > 0; i--) {
		if (counter < 100)
			out_string += PrintMatchIndex(i);

	}
	return out_string;

}

string MapClass::PrintByName(string name) {
	string out_string = "";
	map<string, Nonprofit>::iterator it;
	for (it = orgs.begin(); it != orgs.end(); ++it) {
		if (it->first == name) {
			CalculateMatches(it->second.getRegion(), it->second.getState(), it->second.getZip(), it->second.getSubCatInt());
			out_string += Print();
		}
	}
	return out_string;
}

void MapClass::CalculateMatches(int region, string state, string zipCode, int subcat) {
	if (region != -1) {
		SearchRegion(region);
	}
	if (state != "") {
		SearchState(state);
	}

	if (zipCode.compare("-1") != 0) {
		SearchZip(zipCode);
	}
	if (subcat != -1) {
		SearchSubCat(subcat);
	}
}

string MapClass::Print() {
	string out_string = "";
	int highest = FindHighestMatchIndex();
	for (unsigned int i = highest; i > 0; i--) {
		if (counter < 100)
			out_string += PrintMatchIndex(i);

	}
	return out_string;
}

void MapClass::ResetNonProfitVars() {
	for (iter = orgs.begin(); iter != orgs.end(); ++iter) {
		iter->second.matchIndex = false;
	}
}

map<string, Nonprofit>& MapClass::GetMap() {
	return orgs;
}

//HEAP CLASS
class HeapClass {
	vector<Nonprofit> heap;
	Nonprofit target;
	int end_index;
public:
	HeapClass(Nonprofit target, map<string, Nonprofit>& orgs);
	void HeapifyUp(Nonprofit add);
	void HeapifyDown(int i);
	Nonprofit GetMax();
	void CalculateMatch(Nonprofit& comp);
	bool IsEmpty();
};

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

Nonprofit HeapClass::GetMax() {

	Nonprofit out_val = heap.at(0);
	//cout << out_val.getInfo() << " " << out_val.matchIndex << endl;
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
	if (target.getState() != "" && target.getState().compare(comp.getState()) == 0)
		match++;
	if (target.getZip().compare("-1") != 0 && target.getZip() == comp.getZip())
		match++;
	if (target.getSubCatInt() == comp.getSubCatInt())
		match++;
	comp.matchIndex = match;
}

bool HeapClass::IsEmpty() {
	if (heap.size() == 0)
		return true;
	return false;
}



//TREE CLASS
class Tree {
	// Private class variables
	Nonprofit* root = nullptr;
	Nonprofit target;
	int count = 100;
public:
	// AVL tree functions
	Tree(Nonprofit _target, map<string, Nonprofit>& orgs, string& output, string& file_output);
	Nonprofit* rotateLeft(Nonprofit* root);
	Nonprofit* rotateRight(Nonprofit* root);
	int getHeight(Nonprofit* root);
	int balanceFactor(Nonprofit* root);
	Nonprofit* Insert(Nonprofit* root, Nonprofit* obj);
	string traverse(Nonprofit* root);
	void CalculateMatch(Nonprofit& comp);
};

Tree::Tree(Nonprofit _target, map<string, Nonprofit>& orgs, string& output, string& file_output) {
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
	file_output = traverse(root);
	stringstream ss(file_output);
	string line = "";
	output = "";
	int line_count = 0;
	//cout << "output" << output << endl;
	while (getline(ss, line, '\n') && line_count < 27) {
		output += line + '\n';
		line_count++;
	}
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
string Tree::traverse(Nonprofit* root) {
	string out_string = "";
	if (root != nullptr) {
		out_string += traverse(root->right);
		if (count != 0) {
			out_string += root->getInfo();
			count--;
			for (int i = 0; i < root->sameIndex.size(); i++) {
				out_string += root->sameIndex.at(i)->getInfo();
				count--;
				if (count == 0)
					break;
			}
			if (count != 0)
				out_string += traverse(root->left);
		}
	}
	//cout << "string in traverse:" << out_string << endl;
	return out_string;
}

// Calculates match based on user preferences
void Tree::CalculateMatch(Nonprofit& comp) {
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


//-----MENU NUMBERING SYSTEM-----/
/*
0 - welcome screen
1 - search by pref input screen - cat
2 - search by pref input screen - subcat, different jpg for each category (21, 22, 23) (if applicable)
3 - search by pref input screen - state, zip, region & heap/map/tree selection
4 - search by pref results screen (background with text from program)

11 - search by name input screen
12 - search by name results screen (background with text from program)
*/





int main()
{
    int screen_num = 0;
    sf::RenderWindow window(sf::VideoMode(700.f,900.f), "Nonprofit Generator");
	sf::Font courier;
	if (!courier.loadFromFile("cour.ttf"))
		return EXIT_FAILURE;

	//0 - welcome screen setup
    sf::Texture background_text;
    if(!background_text.loadFromFile("background.jpg"))
		return EXIT_FAILURE;
    sf::Sprite background(background_text);
    //background.setPosition(sf::Vector2f(0.f, 0.f));

	//1 - search by pref input screen - cat
    sf::Texture cat_menu_text;
    if(!cat_menu_text.loadFromFile("cat_menu.jpg"))
		return EXIT_FAILURE;
	int cat_choice = -1;
	int subcat_choice = -1;
    //sf::Sprite cat_menu(cat_menu_text);

	//2 - search by pref input screen - subcat, different jpg for each category(21, 22, 23) (if applicable)
	sf::Texture subcat_menu3;
	sf::Texture subcat_menu4;
	sf::Texture subcat_menu5;
	sf::Texture subcat_menu7;
	if (!subcat_menu3.loadFromFile("subcat_menu3.jpg") || !subcat_menu4.loadFromFile("subcat_menu4.jpg") || !subcat_menu5.loadFromFile("subcat_menu5.jpg") || !subcat_menu7.loadFromFile("subcat_menu7.jpg"))
		return EXIT_FAILURE;

	//3 - preference menus
	sf::Texture pref_menu;
	if (!pref_menu.loadFromFile("pref_menu.jpg"))
		return EXIT_FAILURE;
	std::string region_str = "";
	std::string state = "";
	std::string zip_str = "";
	std::string* curr_input = &region_str;

	sf::Text region_input;
	region_input.setFont(courier);
	region_input.setFillColor(sf::Color::Black);
	region_input.setString(region_str);
	region_input.setPosition(sf::Vector2f(355.f, 450.f));

	sf::Text state_input;
	state_input.setFont(courier);
	state_input.setFillColor(sf::Color::Black);
	state_input.setString(state);
	state_input.setPosition(sf::Vector2f(255.f, 490.f));

	sf::Text zip_input;
	zip_input.setFont(courier);
	zip_input.setFillColor(sf::Color::Black);
	zip_input.setString(zip_str);
	zip_input.setPosition(sf::Vector2f(370.f, 535.f));

	//4 - preference results
	sf::Texture pref_results;
	if (!pref_results.loadFromFile("pref_results.jpg"))
		return EXIT_FAILURE;

	sf::Text cat_display;
	cat_display.setFont(courier);
	cat_display.setFillColor(sf::Color::Black);
	cat_display.setPosition(sf::Vector2f(145.f, 125.f));

	sf::Text subcat_display;
	subcat_display.setFont(courier);
	subcat_display.setFillColor(sf::Color::Black);
	subcat_display.setPosition(sf::Vector2f(370.f, 125.f));

	sf::Text zip_display;
	zip_display.setFont(courier);
	zip_display.setFillColor(sf::Color::Black);
	zip_display.setPosition(sf::Vector2f(450.f, 170.f));

	sf::Text region_display;
	region_display.setFont(courier);
	region_display.setFillColor(sf::Color::Black);
	region_display.setPosition(sf::Vector2f(130.f, 170.f));

	sf::Text state_display;
	state_display.setFont(courier);
	state_display.setFillColor(sf::Color::Black);
	state_display.setPosition(sf::Vector2f(240.f, 170.f));

	sf::Text output_display;
	output_display.setFont(courier);
	output_display.setFillColor(sf::Color::Black);
	output_display.setPosition(sf::Vector2f(65.f, 260.f));
	output_display.setCharacterSize(18);
	string output = "";

	string file_output = "";

	//11 - search by name input screen setup
	sf::Texture name_menu_text;
	if (!name_menu_text.loadFromFile("name_menu.jpg"))
		return EXIT_FAILURE;
	std::string input = "";
	
	sf::Text name_input;
	name_input.setFont(courier);
	name_input.setFillColor(sf::Color::Black);
	name_input.setString(input);
	name_input.setPosition(sf::Vector2f(50.f, 570.f));

	//12 - search by name results screen setup
	sf::Texture name_results_text;
	if (!name_results_text.loadFromFile("name_results.jpg"))
		return EXIT_FAILURE;
	sf::Text name_target;
	name_target.setFont(courier);
	name_target.setFillColor(sf::Color::Black);
	name_target.setPosition(sf::Vector2f(295.f, 170.f));


	//clock setup
	sf::Text time_display;
	time_display.setFont(courier);
	time_display.setFillColor(sf::Color::White);
	time_display.setPosition(sf::Vector2f(20.f, 50.f));
	time_display.setCharacterSize(20);


	//Populate maps - use MapClass and file reading
	// Creates maps for each main category of nonprofits
	vector<pair <int, MapClass*> > maps;
	MapClass* a = new MapClass("Arts, Culture & Humanities");
	maps.push_back(make_pair(1, a));
	MapClass* b = new MapClass("Education");
	maps.push_back(make_pair(2, b));
	MapClass* cd = new MapClass("Environment and Animals");
	maps.push_back(make_pair(3, cd));
	MapClass* eh = new MapClass("Health");
	maps.push_back(make_pair(4, eh));
	MapClass* ip = new MapClass("Human Services");
	maps.push_back(make_pair(5, ip));
	MapClass* q = new MapClass("International, Foreign Affairs");
	maps.push_back(make_pair(6, q));
	MapClass* rw = new MapClass("Public, Societal Benefit");
	maps.push_back(make_pair(7, rw));
	MapClass* x = new MapClass("Religion Related");
	maps.push_back(make_pair(8, x));
	MapClass* y = new MapClass("Mutual/Membership Benefit");
	maps.push_back(make_pair(9, y));

	ifstream inFile("NPOMasterFileFinal.csv");

	// Reads in data from csv file
	if (inFile.is_open()) {
		string lineFromFile;
		getline(inFile, lineFromFile);

		while (getline(inFile, lineFromFile)) {
			istringstream stream(lineFromFile);

			string name;
			string street;
			string zipStr;
			string state;
			string regionStr;
			string NTEE;
			int region;
			int revenue;

			getline(stream, name, ',');
			getline(stream, street, ',');
			getline(stream, zipStr, ',');
			getline(stream, state, ',');
			getline(stream, regionStr, ',');
			getline(stream, NTEE);

			region = stoi(regionStr);

			// Creates nonprofit object from data
			Nonprofit n(name, street, zipStr.substr(0, 5), state, region, NTEE);

			// Assigns subcategory and inserts into category map
			if (NTEE.substr(0, 1).compare("A") == 0) {
				n.setSubcat("Arts, Culture & Humanties");
				n.setSubcatNum(1);
				a->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("B") == 0) {
				n.setSubcat("Education");
				n.setSubcatNum(1);
				b->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("C") == 0) {
				n.setSubcat("Environment", 1);
				n.setSubcatNum(1);
				cd->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("D") == 0) {
				n.setSubcat("Animal-Related", 2);
				n.setSubcatNum(2);
				cd->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("E") == 0) {
				n.setSubcat("Health Care", 1);
				n.setSubcatNum(1);
				eh->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("F") == 0) {
				n.setSubcat("Mental Health & Crisis Intervention", 2);
				n.setSubcatNum(2);
				eh->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("G") == 0) {
				n.setSubcat("Voluntary Health Associations & Medical Discipliness", 3);
				n.setSubcatNum(3);
				eh->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("H") == 0) {
				n.setSubcat("Medical Research", 4);
				n.setSubcatNum(4);
				eh->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("I") == 0) {
				n.setSubcat("Crime & Legal-Related", 1);
				n.setSubcatNum(1);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("J") == 0) {
				n.setSubcat("Employment", 2);
				n.setSubcatNum(2);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("K") == 0) {
				n.setSubcat("Food, Agriculture & Nutrition", 3);
				n.setSubcatNum(3);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("L") == 0) {
				n.setSubcat("Housing & Shelter", 4);
				n.setSubcatNum(4);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("M") == 0) {
				n.setSubcat("Public Safety, Disaster Preparedness & Relief", 5);
				n.setSubcatNum(5);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("N") == 0) {
				n.setSubcat("Recreation & Sports", 6);
				n.setSubcatNum(6);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("O") == 0) {
				n.setSubcat("Youth Development", 7);
				n.setSubcatNum(7);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("P") == 0) {
				n.setSubcat("Human Services", 8);
				n.setSubcatNum(8);
				ip->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("Q") == 0) {
				n.setSubcat("International, Foreign Affairs");
				n.setSubcatNum(1);
				q->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("R") == 0) {
				n.setSubcat("Civil Rights, Social Action & Advocacy", 1);
				n.setSubcatNum(1);
				rw->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("S") == 0) {
				n.setSubcat("Community Improvement & Capacity Building", 2);
				n.setSubcatNum(2);
				rw->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("T") == 0) {
				n.setSubcat("Philanthropy, Voluntarism & Grantmaking Foundations", 3);
				n.setSubcatNum(3);
				rw->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("U") == 0) {
				n.setSubcat("Science & Technology", 4);
				n.setSubcatNum(4);
				rw->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("V") == 0) {
				n.setSubcat("Social Science", 5);
				n.setSubcatNum(5);
				rw->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("W") == 0) {
				n.setSubcat("Public & Societal Benefit", 6);
				n.setSubcatNum(6);
				rw->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("X") == 0) {
				n.setSubcat("Religion Related");
				n.setSubcatNum(1);
				x->InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("Y") == 0) {
				n.setSubcat("Mutual/Membership Benefit");
				n.setSubcatNum(1);
				y->InsertIntoMap(name, n);
			}
		}
	}
	cout << "loaded" << endl;

    
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (screen_num == 0)
				background.setTexture(background_text);
			else if (screen_num == 1)
				background.setTexture(cat_menu_text);
			else if (screen_num == 3)
				background.setTexture(pref_menu);
			else if (screen_num == 4)
				background.setTexture(pref_results);
			else if (screen_num == 11)
				background.setTexture(name_menu_text);
			else if (screen_num == 12)
				background.setTexture(name_results_text);
			else if (screen_num == 21 || screen_num == 22 || screen_num == 26 || screen_num == 28 || screen_num == 29)
				screen_num = 3;
			else if (screen_num == 23)
				background.setTexture(subcat_menu3);
			else if (screen_num == 24)
				background.setTexture(subcat_menu4);
			else if (screen_num == 25)
				background.setTexture(subcat_menu5);
			else if (screen_num == 27)
				background.setTexture(subcat_menu7);


			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i position = sf::Mouse::getPosition(window); //include param to return local coords
				if (screen_num == 0) {
					if (position.x > 130 && position.x < 580) {
						if (position.y > 412 && position.y < 490)
							screen_num = 1;
						else if (position.y > 505 && position.y < 590)
							screen_num = 11;
					}
				}
				else if (screen_num == 1) {
					for (int i = 0; i < 9; i++) {
						if (position.x > 92 && position.x < 606 && position.y >(240 + (60 * i)) && position.y < (280 + (60 * i))) {
							cat_choice = i + 1;
							screen_num = 20 + cat_choice;
						}
					}
				}
				else if (screen_num == 3) {
					if (position.y > 456 && position.y < 492 && position.x > 350 && position.x < 402)
						curr_input = &region_str;
					else if (position.y > 500 && position.y < 535 && position.x > 247 && position.x < 555)
						curr_input = &state;
					else if (position.y > 542 && position.y < 577 && position.x > 364 && position.x < 508)
						curr_input = &zip_str;
					if (position.y > 640 && position.y < 710) {
						if (position.x > 34 && position.x < 222) {
							//map search button
							output = "";
							file_output = "";
							auto begin = chrono::high_resolution_clock::now();
							for (unsigned int i = 0; i < maps.size(); i++) {
								if (cat_choice == maps[i].first)
									file_output += maps[i].second->PrintPreferences(stoi(region_str), state, zip_str, subcat_choice);
							}


							stringstream ss(file_output);
							string line = "";
							int line_count = 0;
							//cout << "output" << output << endl;
							while (getline(ss, line, '\n') && line_count < 27) {
								output += line + '\n';
								line_count++;
							}

							output_display.setString(output);
							cat_display.setString(to_string(cat_choice));
							subcat_display.setString(to_string(subcat_choice));
							region_display.setString(region_str);
							state_display.setString(state);
							zip_display.setString(zip_str);
							auto last = chrono::high_resolution_clock::now();
							chrono::duration<double> num = last - begin;
							time_display.setString("Time: " + to_string(num.count()));
							screen_num = 4;
						}
						else if (position.x > 256 && position.x < 442) {
							//heap search button
							Nonprofit target("", "", zip_str, state, stoi(region_str), to_string(cat_choice));
							if ((cat_choice != 1 && cat_choice != 2 && cat_choice != 6 && cat_choice != 8 && cat_choice != 9)) {
								target.setSubcatNum(subcat_choice);
							}
							auto begin = chrono::high_resolution_clock::now();
							for (unsigned int i = 0; i < maps.size(); i++) {
								if (cat_choice == maps[i].first) {
									//map<string, Nonprofit>& source = maps[i].second->GetMap;
									HeapClass heap = HeapClass(target, maps[i].second->GetMap());
									int count = 0; //place to choose how many results to see
									output = "";
									string info = "";
									while (!heap.IsEmpty() && count < 100) {
										Nonprofit curr = heap.GetMax();
										info = curr.getInfo();
										if (count < 9) {
											output += (to_string(count + 1) + ". ");
											output += info;
											count++;
										}
										file_output += info;
										
									}
								}
							}
							auto last = chrono::high_resolution_clock::now();
							chrono::duration<double> num = last - begin;
							time_display.setString("Time: " + to_string(num.count()));
							output_display.setString(output);
							cat_display.setString(to_string(cat_choice));
							subcat_display.setString(to_string(subcat_choice));
							region_display.setString(region_str);
							state_display.setString(state);
							zip_display.setString(zip_str);
							screen_num = 4;
						}
						else if (position.x > 478 && position.x < 665) {
							//tree search button
							Nonprofit target("", "", zip_str, state, stoi(region_str), to_string(cat_choice));
							if ((cat_choice != 1 && cat_choice != 2 && cat_choice != 6 && cat_choice != 8 && cat_choice != 9)) {
								target.setSubcatNum(subcat_choice);
							}
							auto begin = chrono::high_resolution_clock::now();
							file_output = "";
							string out_string = "";
							for (unsigned int i = 0; i < maps.size(); i++) {
								if (cat_choice == maps[i].first) {
									Tree(target, maps[i].second->GetMap(), out_string, file_output);
								}
							}
							
							auto last = chrono::high_resolution_clock::now();
							chrono::duration<double> num = last - begin;
							output_display.setString(out_string);
							time_display.setString("Time: " + to_string(num.count()));
							cat_display.setString(to_string(cat_choice));
							subcat_display.setString(to_string(subcat_choice));
							region_display.setString(region_str);
							state_display.setString(state);
							zip_display.setString(zip_str);
							screen_num = 4;
						}
					}
				}
				else if (screen_num == 4) {
					if (position.x > 505 && position.x < 690 && position.y > 10 && position.y < 55) {
						for (unsigned int i = 0; i < maps.size(); i++) {
							maps[i].second->ResetNonProfitVars();
						}

						input = "";
						region_str = "";
						state = "";
						zip_str = "";
						curr_input = &region_str;
						cat_choice = -1;
						subcat_choice = -1;
						file_output = "";
						output_display.setString("");
						state_input.setString(state);
						region_input.setString(region_str);
						zip_input.setString(zip_str);
						name_target.setString(input);

						screen_num = 0;
					}

					else if (position.x > 195 && position.x < 485 && position.y > 830 && position.y < 880) {
						//file writing
						cout << "file wrting" << endl;
						fstream out;
						out.open("Results.csv", ios::out | ios::app);
						out << "NAME,STREET,STATE,ZIP" << "\n";
						out << file_output;
						out.close();
					}
				}
				else if (screen_num == 23) {
					for (int i = 0; i < 2; i++) {
						if (position.x > 92 && position.x < 606 && position.y >(240 + (60 * i)) && position.y < (280 + (60 * i))) {
							subcat_choice = i + 1;
							std::cout << subcat_choice;
							screen_num = 3;
						}
					}
				}
				else if (screen_num == 24) {
					for (int i = 0; i < 4; i++) {
						if (position.x > 92 && position.x < 606 && position.y >(240 + (60 * i)) && position.y < (280 + (60 * i))) {
							subcat_choice = i + 1;
							std::cout << subcat_choice;
							screen_num = 3;
						}
					}
				}
				else if (screen_num == 25) {
					for (int i = 0; i < 8; i++) {
						if (position.x > 92 && position.x < 606 && position.y >(240 + (60 * i)) && position.y < (280 + (60 * i))) {
							subcat_choice = i + 1;
							std::cout << subcat_choice;
							screen_num = 3;
						}
					}
				}
				else if (screen_num == 27) {
					for (int i = 0; i < 6; i++) {
						if (position.x > 92 && position.x < 606 && position.y >(240 + (60 * i)) && position.y < (280 + (60 * i))) {
							subcat_choice = i + 1;
							std::cout << subcat_choice;
							screen_num = 3;
						}
					}
				}
				else if (screen_num == 11) {
					//check for intersection with enter buttons
					if (position.y > 640 && position.y < 710 && position.x > 256 && position.x < 442) {
						string out_string = "";
						//map search button - use input string here for search
						name_target.setString(input);
						auto begin = chrono::high_resolution_clock::now();
						int count = 0;
						for (unsigned int i = 0; i < maps.size(); i++) {
							if (maps[i].second->FindName(input) == true) {
								cout << "correct map found" << endl;
								out_string += maps[i].second->PrintByName(input);
								break;
							}
							count++;
						}
						if (count == 9) {
							out_string = "The nonprofit you are looking for cannot be found in our database.";
						}

						
						file_output = out_string;
						out_string = "";
						stringstream ss(file_output);
						string line = "";
						int line_count = 0;
						//cout << "output" << output << endl;
						while (getline(ss, line, '\n') && line_count < 27) {
							out_string += line + '\n';
							line_count++;
						}

						auto last = chrono::high_resolution_clock::now();
						chrono::duration<double> num = last - begin;
						time_display.setString("Time: " + to_string(num.count()));
						output_display.setString(out_string);
						//input = "";
						//continue to results - adjust screen_num
						screen_num = 12;

					}
					//grab the input string to use for name searching before reseting the input string
				}
				else if (screen_num == 12) {
					if (position.x > 505 && position.x < 690 && position.y > 10 && position.y < 55) {
						for (unsigned int i = 0; i < maps.size(); i++) {
							maps[i].second->ResetNonProfitVars();
						}
						input = "";
						region_str = "";
						state = "";
						zip_str = "";
						curr_input = &region_str;
						cat_choice = -1;
						subcat_choice = -1;
						file_output = "";
						output_display.setString("");
						state_input.setString(state);
						region_input.setString(region_str);
						zip_input.setString(zip_str);
						name_target.setString(input);
						name_input.setString(input);

						screen_num = 0;
					}

					else if (position.x > 195 && position.x < 485 && position.y > 830 && position.y < 880) {
						//file writing
						cout << "file wrting" << endl;
						fstream out;
						out.open("Results.csv", ios::out | ios::app);
						out << "NAME\nSTREET,STATE,ZIP" << "\n";
						out << file_output;
						out.close();
					}
				}

				//std::cout << " " << position.x << " " << position.y << std::endl;
			}
			else if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					if (screen_num == 11) {
						input += static_cast<char>(event.text.unicode);
						name_input.setString(input);
					}
					if (screen_num == 3) {
						*curr_input += static_cast<char>(event.text.unicode);
						state_input.setString(state);
						region_input.setString(region_str);
						zip_input.setString(zip_str);
						//std::cout << state << region_str << zip_str;
					}
				}
			}
		}

		window.clear(sf::Color::White);
		window.draw(background);
		if (screen_num == 11)
			window.draw(name_input);
		if (screen_num == 12) {
			window.draw(name_target);
			window.draw(output_display);
			window.draw(time_display);
		}
		if (screen_num == 3) {
			window.draw(zip_input);
			window.draw(region_input);
			window.draw(state_input);
		}
		if (screen_num == 4) {
			window.draw(cat_display);
			window.draw(subcat_display);
			window.draw(region_display);
			window.draw(state_display);
			window.draw(zip_display);
			window.draw(output_display);
			window.draw(time_display);
		}
		window.display();
	}

    return 0;
}
