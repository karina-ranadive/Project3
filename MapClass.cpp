#include "MapClass.h"


MapClass::MapClass(string category){
    this->category = category;
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
int::MapClass::FindHighestMatchIndex(){
    int num = -1;
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.matchIndex > num){
            num = iter->second.matchIndex;
        }
    }
    return num;
}

void::MapClass::PrintPreferences(int region, string state, string street, int zipCode, string subcat){
    if(region != 0){
        SearchRegion(region);
    }
    if(state!=""){
        SearchState(state);
    }
    if(street != ""){
        SearchStreet(street);
    }
    if(zipCode!=0){
        SearchZip(zipCode);
    }
    if(subcat!=""){
        SearchSubCat(subcat);
    }

    map<int, Nonprofit> matches;
    map<int, Nonprofit>::reverse_iterator it;

    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.matchIndex!=0){
            matches[iter->second.matchIndex] = iter->second;
        }
    }
    int count = 0;
    for(it = matches.rbegin(); it!=matches.rend(); ++it){
        if(iter->second.flag == false){
            continue;
        }
        if(count = 101){
            break;
        }
        iter->second.printNonprofit();
        count++;
    }


}

void::MapClass::PrintbyName(string name){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->first == name){
            iter->second.printNonprofit();
            iter->second.flag = false;
            PrintPreferences(iter->second.getRegion(), iter->second.getState(), iter->second.getStreet(), iter->second.getZip(), iter->second.getSubCat());
        }
    }
}

void::MapClass::ResetNonProfitVars(){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        iter->second.flag = true;
        iter->second.matchIndex = false;
    }
}

