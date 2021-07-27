#include "Nonprofit.h"

Nonprofit::Nonprofit(std::string name, std::string street, int zip, std::string state, int region, std::string NTEE) {
    this->name = name;
    this->street = street;
    this->zip = zip;
    this->state = state;
    this->region = region;
    this->NTEE = NTEE;
    matchIndex = 0;
    

}
Nonprofit::Nonprofit(){

}

std::string Nonprofit::getStreet() {
    return street;
}

int Nonprofit::getZip() {
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

std::string Nonprofit::getSubCat() {
    return subcategory;
}

void Nonprofit::printNonprofit() {
    std::cout << name  << " " << matchIndex << std::endl;

}

void Nonprofit::setSubcat(std::string subcategory) {
    this->subcategory = subcategory;
}


