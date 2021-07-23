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

void MapClass::SearchCause(string ntee){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.getNTEE() == ntee){
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
void::MapClass::PrintMatchIndex(int number){
    for(iter = orgs.begin(); iter!=orgs.end(); ++iter){
        if(iter->second.matchIndex == number){
            iter->second.printNonprofit();
        }
    }
}

void::MapClass::Print(){
    int highest = FindHighestMatchIndex();
    for(unsigned int i = highest; i > 0; i++){
        PrintMatchIndex(i);
    }

}

