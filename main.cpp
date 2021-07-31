#include "MapClass.h"
#include "HeapClass.h"
#include "Tree.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

int main(){

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

			Nonprofit n(name, street, zipStr.substr(0,5), state, region, NTEE);
			 
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

	//--------------------------------------------MAP USER IMPLEMENTATION-----------------------------------------------

	
	/*
	THIS TEST WORKS
	y->PrintByName("BENEVOLENT & PROTECTIVE ORDER OF ELKS OF THE USA");
	for(int i = 0; i < maps.size(); i++){
		if(maps[i].first == 9){
			maps[i].second->PrintByName("BENEVOLENT & PROTECTIVE ORDER OF ELKS OF THE USA");
		}
	}
	*/
	
	
	int choice = -1;
	while (choice != 0) {
		cout << "Would you like to Search By Name(1) or by Preferences(2)? (0 to exit) ";
		string choiceString;
		cin >> choiceString;
		choice = stoi(choiceString);

		//Search By Name
		if (choice == 1) {
			cout << "What is the name of the nonprofit your are looking for? ";
			string temp;
			getline(cin, temp);
			string name;
			getline(cin, name);
			cout << endl << "Loading Results..." << endl;
			int count = 0;
			for (unsigned int i = 0; i < maps.size(); i++) {
				if (maps[i].second->FindName(name) == true) {
					maps[i].second->PrintByName(name);
					break;
				}
				count++;
			}
			if (count == 9) {
				cout << "The nonprofit you are looking for cannot be found in our database." << endl;
			}
			cout << endl;
		}
		//Search Solely by Preferences 
		else if (choice == 2) {
			cout << endl;
			cout << "Fill out preferences for nonprofits and if you do not have a preference, press enter on your keyboard" << endl;
			cout << "Based on your preferences, we will list out nonprofits related to your preferences!" << endl;

			cout << endl << "1. Arts, Culture & Humanities" << endl;
			cout << "2. Education" << endl;
			cout << "3. Environment and Animals" << endl;
			cout << "4. Health" << endl;
			cout << "5. Human Services" << endl;
			cout << "6. International, Foreign Affairs" << endl;
			cout << "7. Public, Societal Benefit" << endl;
			cout << "8. Religion Related" << endl;
			cout << "9. Mutual/Membership Benefit" << endl;
			cout << "-------------------------------------" << endl;
			cout << "Preference for Category (Please enter corresponding number): ";
			string temp;
			getline(cin, temp);
			string cat;
			getline(cin, cat);
			int category = stoi(cat);

			cout << endl;
			string subcat;
			int subcategory;
			if (category == 1 || category == 2 || category == 6 || category == 8 || category == 9) {
				subcategory = 1;
			}
			else {
				if (category == 3) {
					cout << "1. Environment" << endl;
					cout << "2. Animal-Related" << endl;
				}
				else if (category == 4) {
					cout << "1. Health Care" << endl;
					cout << "2. Mental Health & Crisis Intervention" << endl;
					cout << "3. Voluntary Health Associations & Medical Disciplines" << endl;
					cout << "4. Medical Research" << endl;
				}
				else if (category == 5) {
					cout << "1. Crime & Legal-Related" << endl;
					cout << "2. Employment" << endl;
					cout << "3. Food, Agriculture & Nutrition" << endl;
					cout << "4. Housing & Shelter" << endl;
					cout << "5. Public Safety, Disaster Preparedness & Relief" << endl;
					cout << "6. Recreation & Sports" << endl;
					cout << "7. Youth Development" << endl;
					cout << "8. Human Services" << endl;
				}
				else if (category == 7) {
					cout << "1. Civil Rights, Social Action & Advocacy" << endl;
					cout << "2. Community Improvement & Capacity Building" << endl;
					cout << "3. Philanthropy, Voluntarism & Grantmaking Foundations" << endl;
					cout << "4. Science & Technology" << endl;
					cout << "5. Social Science" << endl;
					cout << "6. Public & Societal Benefit" << endl;
				}
				cout << "-------------------------------------" << endl;
				cout << "Preference for Sub-Category: ";
				getline(cin, subcat);
				subcategory = stoi(subcat);
				cout << endl;
			}

			cout << "0. New England" << endl;
			cout << "1. Mid-Atlantic" << endl;
			cout << "3. South Atlantic" << endl;
			cout << "4. East North Central" << endl;
			cout << "5. West North Central" << endl;
			cout << "6. East South Central" << endl;
			cout << "7. West South Central" << endl;
			cout << "8. Mountain" << endl;
			cout << "9. Pacific" << endl;
			cout << "-------------------------------------" << endl;
			cout << "Preference for region: ";
			string reg;
			getline(cin, reg);
			if(reg == "None")
				reg = "-1";
			int region = stoi(reg);

			cout << endl << "Preference for state: ";
			string state;
			getline(cin, state);

			cout << "Preference for Zip Code: ";
			string zipCode;
			getline(cin, zipCode);
			zipCode = zipCode.substr(0, 5);
			cout << endl;

			cout << "Method Choice:" << endl;
			cout << "1. Map" << endl;
			cout << "2. Heap" << endl;
			cout << "3. Tree" << endl;
			string choice_str;
			getline(cin, choice_str);
			int choice = stoi(choice_str);

			if (choice == 1) {
				for (unsigned int i = 0; i < maps.size(); i++) {
					if (category == maps[i].first) {
						maps[i].second->PrintPreferences(region, state, zipCode, subcategory);
					}
				}
			}
			else {
				Nonprofit target("", "", zipCode, state, region, cat);
				target.setSubcatNum(subcategory);
				cout << subcategory << endl;
				cout << target.getSubCatInt() << endl;;

				for (unsigned int i = 0; i < maps.size(); i++) {
					if (category == maps[i].first) {
						if (choice == 2) {
							//map<string, Nonprofit>& source = maps[i].second->GetMap;
							HeapClass heap = HeapClass(target, maps[i].second->GetMap());
							int count = 0; //place to choose how many results to see
							while (!heap.IsEmpty() && count < 100) {
								heap.GetMax();
								count++;
							}
						}
						else if (choice == 3) {
							Tree(target, maps[i].second->GetMap());
						}
					}
				}
			}
		}

	
		for (unsigned int i = 0; i < maps.size(); i++) {
			maps[i].second->ResetNonProfitVars();
		}
	}
}

