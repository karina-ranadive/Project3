#include "Nonprofit.h"

Nonprofit::Nonprofit(std::string street, int zip, std::string state, int regeion, int revenue, std::string NTEE) {
	this->street = street;
	this->zip = zip;
	this->state = state;
	this->region = region;
	this->revenue = revenue;
	this->NTEE = NTEE;
	matchIndex = 0;
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

int Nonprofit::getRevenue() {
	return revenue;
}

std::string Nonprofit::getNTEE() {
	return NTEE;
}

void Nonprofit::printNonprofit() {
	// determine print format when design is determined
}