#include "MapClass.h"
#include "Nonprofit.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

	vector<pair <int, MapClass> > maps;
	MapClass a = MapClass("Arts, Culture & Humanities");
	maps.push_back(make_pair(1, a));
	MapClass b = MapClass("Education");
	maps.push_back(make_pair(2, b));
	MapClass cd = MapClass("Environment and Animals");
	maps.push_back(make_pair(3, cd));
	MapClass eh = MapClass("Health");
	maps.push_back(make_pair(4, eh));
	MapClass ip = MapClass("Human Services");
	maps.push_back(make_pair(5, ip));
	MapClass q = MapClass("International, Foreign Affairs");
	maps.push_back(make_pair(6, q));
	MapClass rw = MapClass("Public, Societal Benefit");
	maps.push_back(make_pair(7, rw));
	MapClass x = MapClass("Religion Related");
	maps.push_back(make_pair(8, x));
	MapClass y = MapClass("Mutual/Membership Benefit");
	maps.push_back(make_pair(9, y));

	ifstream inFile("NPOMasterFileFinal.csv");

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
			int zip;
			int region;
			int revenue;

			getline(stream, name, ',');
			getline(stream, street, ',');
			getline(stream, zipStr, ',');
			getline(stream, state, ',');
			getline(stream, regionStr, ',');
			getline(stream, NTEE);

			zip = stoi(zipStr);
			region = stoi(regionStr);

			Nonprofit n(name, street, zip, state, region, NTEE);
			 
			if (NTEE.substr(0, 1).compare("A") == 0) {
				n.setSubcat("Arts, Culture & Humanties");
				a.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("B") == 0) {
				n.setSubcat("Education");
				b.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("C") == 0) {
				n.setSubcat("Environment");
				cd.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("D") == 0) {
				n.setSubcat("Animal-Related");
				cd.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("E") == 0) {
				n.setSubcat("Health Care");
				eh.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("F") == 0) {
				n.setSubcat("Mental Health & Crisis Intervention");
				eh.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("G") == 0) {
				n.setSubcat("Voluntary Health Associations & Medical Discipliness");
				eh.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("H") == 0) {
				n.setSubcat("Medical Research");
				eh.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("I") == 0) {
				n.setSubcat("Crime & Legal-Related");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("J") == 0) {
				n.setSubcat("Employment");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("K") == 0) {
				n.setSubcat("Food, Agriculture & Nutrition");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("L") == 0) {
				n.setSubcat("Housing & Shelter");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("M") == 0) {
				n.setSubcat("Public Safety, Disaster Preparedness & Relief");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("N") == 0) {
				n.setSubcat("Recreation & Sports");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("O") == 0) {
				n.setSubcat("Youth Development");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("P") == 0) {
				n.setSubcat("Human Services");
				ip.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("Q") == 0) {
				n.setSubcat("International, Foreign Affairs & National Security");
				q.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("R") == 0) {
				n.setSubcat("Civil Rights, Social Action & Advocacy");
				rw.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("S") == 0) {
				n.setSubcat("Community Improvement & Capacity Building");
				rw.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("T") == 0) {
				n.setSubcat("Philanthropy, Voluntarism & Grantmaking Foundations");
				rw.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("U") == 0) {
				n.setSubcat("Science & Technology");
				rw.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("V") == 0) {
				n.setSubcat("Social Science");
				rw.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("W") == 0) {
				n.setSubcat("Public & Societal Benefit");
				rw.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("X") == 0) {
				n.setSubcat("Religion-Related");
				x.InsertIntoMap(name, n);
			}
			else if (NTEE.substr(0, 1).compare("Y") == 0) {
				n.setSubcat("Mutual & Membership Benefit");
				y.InsertIntoMap(name, n);
			}
		}
	} 

	//--------------------------------------------MAP USER IMPLEMENTATION-----------------------------------------------

	cout << "Would you like to Search By Name or by Preferences?" << endl;
	string choice;
	cin >> choice;

	//Search By Name
	if(choice == "Name"){
		cout << "What is the name of the nonprofit your are looking for?" << endl;
		string name;
		cin >> name;
		cout << "Loading Results..." << endl;
		int count = 0;
		for(unsigned int i = 0; i < maps.size(); i++){
			if(maps[i].second.FindName(name) == true){
				maps[i].second.PrintbyName(name);
				break;
			}
			count++;
		}
		if(count == 9){
			cout << "The nonprofit you are looking for cannot be found in our database." << endl;
		}

	
	}
	
	//Search Solely by Preferences 
	else{
		cout << "Fill out preferences for nonprofits and if you do not have a preference, press enter on your keyboard" << endl;
		cout << "Based on your preferences, we will list out nonprofits related to your preferences!" << endl;
		cout << "Preference for Category: " << endl;
		string cat;
		getline(cin, cat);
		int category = stoi(cat);
		cout << "Preference for region: " << endl;
		string reg;
		getline(cin, reg);
		int region = stoi(reg);
		cout << endl;
		cout << "Preference for state: " << endl;
		string state;
		getline(cin, state);
		cout << endl;
		cout << "Preference for Street Address: " << endl;
		string street;
		getline(cin, street);
		cout << endl;
		cout << "Preference for Zip Code: " << endl;
		string zipCode;
		getline(cin, zipCode);
		int zip = stoi(zipCode);
		cout << endl;
		cout << "Preference for Sub-Category: " << endl;
		string subcat;
		getline(cin, subcat);
		cout << endl;
	
		for(unsigned int i = 0; i < maps.size(); i++){
			if(category == maps[i].first){
				maps[i].second.PrintPreferences(region, state, street, zip, subcat);
			}
		}

	}
	

	for(unsigned int i = 0; i < maps.size(); i++){
		maps[i].second.ResetNonProfitVars();
	}
	
	
	
	



}