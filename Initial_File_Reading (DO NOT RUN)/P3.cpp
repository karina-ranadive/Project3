// P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;



class NPO {
public:
    string zip;
    int region;
    string name;
    string category;
    string street;
    string state;
    int donations;
    NPO(string _zip, int _region, string _name, string _category, string _street, string _state);
    /*bool operator < (const NPO& other) const {
        return (region < other.getRegion() || region == other.getRegion() || region > other.getRegion());
    }*/
    int getRegion() const{
        return region;
    }
    string getInfo() const{
        return "Name: " + name + " Region: " + to_string(region) + " ZipCode: " + zip + " NTEE: " + category + " Street:" + street + " State: " + state;
    }
};

NPO::NPO(string _zip, int _region, string _name, string _category, string _street, string _state) {
    zip = _zip;
    region = _region;
    name = _name;
    category = _category;
    street = _street;
    state = _state;
}



//globals
unordered_map<string, int> regions;


void PopulateRegions() {
    fstream in;
    in.open("regions.csv", ios::in);
    string line, state, region, temp = "";
    int index = 0;
    bool first = true;

    while (getline(in, line, '\n')) {
        //handle UTC header
        if (first)
            line = line.substr(3);
        first = false;
        //read file
        stringstream str(line);
        index = 0;
        state, region = "";
        while (getline(str, temp, ',')) {
            if (index == 0)
                state = temp;
            else
                region = temp;
            index++;
        }
        //add state to map, loosely based on zip codes
        int regionCode = -1;
        if (region == "New England")
            regionCode = 0;
        else if (region == "Mid-Atlantic")
            regionCode = 1;
        else if (region == "East North Central")
            regionCode = 4;
        else if (region == "West North Central")
            regionCode = 5;
        else if (region == "South Atlantic")
            regionCode = 3;
        else if (region == "East South Central")
            regionCode = 6;
        else if (region == "West South Central")
            regionCode = 7;
        else if (region == "Mountain")
            regionCode = 8;
        else if (region == "Pacific")
            regionCode = 9;

        //add to map
        regions[state] = regionCode;
        //cout << state << " " << regions[state] << endl;
    }
}

void PopulateCharities(vector<NPO>& charities, unordered_map<int, string>& categories) {
    fstream in;
    in.open("BusinessMasterFileEdit.csv", ios::in);
    string line, temp, name, street, state, NTEE, act1, act2, act3, zip;
    NTEE = "";
    int region = -1;
    int index = 0;
    getline(in, line, '\n');    //handle header
    
    while (getline(in, line, '\n')) {
        stringstream str(line);
        index = 0;
        NTEE = "";
        while (getline(str, temp, ',')) {
            //cout << index << " " << temp << endl;
            if (index == 1)
                name = temp;
            else if (index == 3)
                street = temp;
            else if (index == 5) {
                //temp = temp.substr(1, 2);   //FIX THE QUOTESSS
                region = regions[temp];
                //ut << temp << " " << regions[temp] << endl;
                state = temp;
            }
            else if (index == 6)
                zip = temp;  
            else if (index == 26) {
                NTEE = temp;
                //cout << NTEE << endl;
            }
                
            else if (index == 30)
                act1 = temp;
            else if (index == 31)
                act2 = temp;
            else if (index == 32)
                act3 = temp;
            index++;
        }

        
        if (NTEE == "") {
            if (act1 != "" && categories.find(stoi(act1)) != categories.end())
                NTEE = categories.find(stoi(act1))->second;
            else if (act2 != "" && categories.find(stoi(act2)) != categories.end())
                NTEE = categories.find(stoi(act2))->second;
            else if (act3 != "" && categories.find(stoi(act3)) != categories.end())
                NTEE = categories.find(stoi(act3))->second;
            else
                NTEE = "Z99";
        }

        charities.push_back(NPO(zip, region, name, NTEE, street, state));
       
    }
    /*
    //print everything in set
    for (auto iter = charities.begin(); iter != charities.end(); iter++) {
        cout << iter->getInfo() << endl;
    }*/

}

void PopulateCategories(unordered_map<int, string>& categories) {
    //read categories file
    fstream in;
    in.open("categories.csv", ios::in);
    string line, temp, NTEE;
    int index = 0;
    int act = -1;
    bool first = true;
    //no header
    while (getline(in, line, '\n')) {
        //handle utc header
        if (first)
            line = line.substr(3);
        first = false;
        index = 0;
        stringstream str(line);
        while (getline(str, temp, ',')) {
            if (index == 0)
                act = stoi(temp);
            else if (index == 1)
                NTEE = temp;
            index++;
        }
        categories[act] = NTEE;
        //cout << act << " " << categories[act] << endl;
    }

}

void WriteFile(vector<NPO>& charities, unordered_map<int, string>& categories) {
    fstream out;
    out.open("NPOMasterFileFinal.csv", ios::out | ios::app);
    out << "NAME,STREET,ZIP,STATE,REGION,NTEE" << "\n";
    for (auto iter = charities.begin(); iter != charities.end(); iter++) {
        if (iter->category != "Z99" && !isdigit(iter->category[0])) {
            out << iter->name << ",";
            out << iter->street << ",";
            out << iter->zip << ",";
            out << iter->state << ",";
            out << iter->region << ",";
            if (iter->category[iter->category.size() - 1] == 'Z')
                iter->category = (iter->category).substr(0, 3);
            if (iter->category[0] == ' ') 
                iter->category = (iter->category).substr(1);
            out << iter->category << "\n";
        }  
    }
}

int main()
{
    vector<NPO> charities;
    unordered_map<int, string> categories;
    PopulateRegions();
    //maps activity codes to updated NTEE codes for consistency
    PopulateCategories(categories);
    cout << "categories created" << endl;
    PopulateCharities(charities, categories);
    cout << "done reading" << endl;
    WriteFile(charities, categories);
    cout << "done writing" << endl;
    
}
