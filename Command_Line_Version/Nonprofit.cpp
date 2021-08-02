#include "Nonprofit.h"

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

Nonprofit::Nonprofit(){

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

std::string Nonprofit::getSubCat(){
    return this->subcategory;
}

// Prints nonprofit info
void Nonprofit::printNonprofit() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Street address: " << street << " " << state << " " << zip << std::endl;
    std::cout << std::endl;
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

// Last getter function
std::string Nonprofit::getName() {
    return name;
}

// Overwrites for comparisons
bool operator < (const Nonprofit& lhs, const Nonprofit& rhs) {
    return lhs.matchIndex < rhs.matchIndex;
}
bool operator > (const Nonprofit& lhs, const Nonprofit& rhs) {
    return lhs.matchIndex > rhs.matchIndex;

}

bool operator <= (const Nonprofit& lhs, const Nonprofit& rhs) {
    return lhs.matchIndex <= rhs.matchIndex;
}
