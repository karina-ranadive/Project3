#include "MapClass.h"


MapClass::MapClass(string category){
    this->category = category;
    this->counter = 0;
    ptr = nullptr;
}

MapClass::MapClass(){

}

void MapClass::InsertIntoMap(string name, Nonprofit obj){
    orgs[name] = obj;
}

void MapClass::SearchRegion(int region){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getRegion() == region){
            iter->second.matchIndex++;
        }
    }
}

void MapClass::SearchName(string name){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->first == name){
            iter->second.matchIndex++;
        }
    }
}

bool MapClass::FindName(string name){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->first == name){
            return true;
        }
    }
    return false;
}

void MapClass::SearchState(string state){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getState() == state){
            iter->second.matchIndex++;
        }
    }
}

void MapClass::SearchStreet(string street){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getStreet() == street){
            iter->second.matchIndex++;
        }
    }
}

void MapClass::SearchZip(int zipCode){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getZip() == zipCode){
            iter->second.matchIndex++;
        }
    }
}

void MapClass::SearchCause(string ntee){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getNTEE() == ntee){
            iter->second.matchIndex++;
        }
    }
}

void MapClass::SearchSubCat(string subcategory){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getSubCat() == subcategory){
            iter->second.matchIndex++;
        }
    }
}

int MapClass::FindHighestMatchIndex(){
    int num = -1;
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.matchIndex > num){
            num = iter->second.matchIndex;
        }
    }
    return num;
}

int MapClass::getSize(){
    return orgs.size();
}

void MapClass::Print(){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        cout << iter->first << endl;
    }
}

void MapClass::PrintPreferences(int region, string state, int zipCode, string subcat){
    if(region != 0){
        SearchRegion(region);
    }
    if(state!=""){
        SearchState(state);
    }
    
    if(zipCode!=0){
        SearchZip(zipCode);
    }
    if(subcat!= ""){
        SearchSubCat(subcat);
    }

    PrintRemaining();


}

void MapClass::PrintMatchIndex(int number){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(counter == 100) {
            break;
        }
        if(iter->second.matchIndex == number){
            counter++;
            iter->second.printNonprofit();
        }
    }

}

void MapClass::PrintRemaining(){
    int highest = FindHighestMatchIndex();
        for(unsigned int i = highest; i > 0; i--){
            if(counter < 100)
                PrintMatchIndex(i);

        }


}

void MapClass::PrintByName(string name){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->first == name){
            PrintPreferences(iter->second.getRegion(), iter->second.getState(), iter->second.getZip(), iter->second.getSubCat());
        }
    }
}

void MapClass::ResetNonProfitVars(){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        iter->second.matchIndex = false;
    }
}

