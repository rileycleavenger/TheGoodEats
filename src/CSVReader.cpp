//
// Created by Riley Cleavenger on 12/3/22.
//

#include "CSVReader.h"

// constructors
CSVReader::CSVReader(){
    filepaths = vector<string> { "" };
}
CSVReader::CSVReader(vector<string> filepaths_){
    filepaths = filepaths_;
}

// getters
vector<string> CSVReader::GetFilepaths(){
    return filepaths;
}
HashMap<Restaurant> CSVReader::GetMap(){
    return restMap;
}
HashSet<Restaurant> CSVReader::GetSet(){
    return restSet
}

// setters;
vector<string> CSVReader::SetFilepaths(vector<string> tempVec){
    filepaths = tempVec;
}
HashMap<Restaurant> CSVReader::SetMap(HashMap tempMap){
    restMap = tempMap;
}
HashSet<Restaurant> CSVReader::SetSet(HashSet tempSet){
    restSet = tempSet;
}

// other functions
void CSVReader::readInFiles(){

}
