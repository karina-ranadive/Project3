#include "MapClass.h"

//This is the map Class constructor with the category parameter, which is mandatory for the user to input
MapClass::MapClass(string category){
    this->category = category;
    this->counter = 0;
    ptr = nullptr;
}
//This is the default constructor for the Map Class
MapClass::MapClass(){

}

//Citation: Referenced Sets, Maps, & Hash Tables slides 
//This STL Map has the name of the nonprofit as keys of the organization & the actual Nonprofit object is the value mapped to it
void MapClass::InsertIntoMap(string name, Nonprofit obj){
    orgs[name] = obj; //this function inserts the value to the key
}


//This function searches if a region exists in the current map and if it is in its Nonprofit object, 1 is added to the object's match index 
void MapClass::SearchRegion(int region){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getRegion() == region){
            iter->second.matchIndex++;
        }
    }
}
//This function searches if a name exists in the current map and if it is in its Nonprofit object, 1 is added to the object's match index 
void MapClass::SearchName(string name){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->first == name){
            iter->second.matchIndex++;
        }
    }
}
//This function searches if a name exists in the current map and if it is in its Nonprofit object, true is returned
bool MapClass::FindName(string name){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->first == name){
            return true;
        }
    }
    return false;
}
//This function searches if a state exists in the object of the value of the current map and if it is in its Nonprofit object, 1 is added to the object's match index 
void MapClass::SearchState(string state){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getState() == state){
            iter->second.matchIndex++;
        }
    }
}

//This function searches if a zipCode exists in the current map and if it is in its Nonprofit object, 1 is added to the object's match index 
void MapClass::SearchZip(string zipCode){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getZip().compare(zipCode) == 0){
            iter->second.matchIndex++;
        }
    }
}
//This function searches if a cause exists in the current map and if it is in its Nonprofit object, 1 is added to the object's match index 
void MapClass::SearchCause(string ntee){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getNTEE() == ntee){
            iter->second.matchIndex++;
        }
    }
}
//This function searches if a subcat exists in the current map and if it is in its Nonprofit object, 1 is added to the object's match index 
void MapClass::SearchSubCat(int subcategory){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getSubCatInt() == subcategory){
            iter->second.matchIndex++;
        }
    }
}
//This function iterates through the map and finds the highest match index that has been calculated and returns that
int MapClass::FindHighestMatchIndex(){
    int num = -1;
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.matchIndex > num){
            num = iter->second.matchIndex;
        }
    }
    return num;
}

//returns size of map 
int MapClass::getSize(){
    return orgs.size();
}

//This function calculates the match index of these parameters as long as they are valid 
void MapClass::CalculateMatches(int region, string state, string zipCode, int subcat){
    if(region != -1){
        SearchRegion(region); //for region 
    }
    if(state!=""){
        SearchState(state); //for state
    }

    if(zipCode.compare("-1") != 0){
        SearchZip(zipCode); //for zip Code
    }
    if(subcat!= -1){
        SearchSubCat(subcat); //for subcategory 
    }



}
//This function prints the nonprofit object based on the match index passed in
void MapClass::PrintMatchIndex(int number){
    map<string, Nonprofit>::iterator i;
    for(i = orgs.begin(); i!=orgs.end(); ++i){
        if(counter == 100) { //this process is done for the top 100
            break;
        }
        if(i->second.matchIndex == number){ //if the match index of the object equals the number passed in, the nonprofit is printed 
            counter++;
            i->second.printNonprofit();
        }
    }

}
//This function finds the highest match index and passes it in the from the highest to lowest to PrintMatchIndex so the nonprofits can be printed from highest matches to lowest
void MapClass::Print(){
    int highest = FindHighestMatchIndex();
    for(unsigned int i = highest; i > 0; i--){
        if(counter < 100)
            PrintMatchIndex(i);

    }

}
//This function represents the print by name feature in the main and for the name passed in, calculate matches passes in that nonprofit object's features ad based on that, similar nonprofits are printed 
void MapClass::PrintByName(string name){
    map<string, Nonprofit>::iterator it;
    for(it = orgs.begin(); it!=orgs.end(); ++it){
        if(it->first == name){
            CalculateMatches(it->second.getRegion(), it->second.getState(), it->second.getZip(), it->second.getSubCatInt());
            Print();
        }
    }
}
//This resets the match index variable to 0 and the counter, which is necessary for the while loop
void MapClass::ResetNonProfitVars(){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        iter->second.matchIndex = 0;
    }
    counter = 0;
}
//This function returns the map 
map<string, Nonprofit>& MapClass::GetMap() {
    return orgs;
}

