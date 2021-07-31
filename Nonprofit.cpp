#include "Nonprofit.h"

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

void Nonprofit::printNonprofit() {
    std::cout << name  << " " << matchIndex << std::endl;
}

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

std::string Nonprofit::getName() {
    return name;
}

bool operator < (const Nonprofit& lhs, const Nonprofit& rhs) {
    return lhs.matchIndex < rhs.matchIndex;
}
bool operator > (const Nonprofit& lhs, const Nonprofit& rhs) {
    return lhs.matchIndex > rhs.matchIndex;

}

bool operator <= (const Nonprofit& lhs, const Nonprofit& rhs) {
    return lhs.matchIndex <= rhs.matchIndex;
}
