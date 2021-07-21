#include "Nonprofit.h"

Nonprofit::Nonprofit(std::string street, int zip, std::string state, int regeion, int revenue, std::string NTEE) {
	this->street = street;
	this->zip = zip;
	this->state = state;
	this->region = region;
	this->revenue = revenue;
	this->NTEE = NTEE;
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

int Nonprofit::getMatchIndex() {
	return matchIndex;
}

void Nonprofit::setMatchIndex(int matchIndex) {
	this->matchIndex = matchIndex;
}

void Nonprofit::printNonprofit() {
	// determine print format when design is determined
}