//
// Created by Riley Cleavenger on 12/3/22.
//

#include "CSVReader.h"

using namespace std;

// constructors
CSVReader::CSVReader(){
    vector<string> temp;
    temp.push_back("");
    filepaths = temp;
}
CSVReader::CSVReader(vector<string> filepaths_){
    filepaths = filepaths_;
}

// getters
vector<string> CSVReader::GetFilepaths(){
    return filepaths;
}
HashSet CSVReader::GetSet(){
    return restSet;
}
/*
HashMap CSVReader::GetMap(){
    return restMap
}
*/


// setters;
void CSVReader::SetFilepaths(vector<string> tempVec){
    filepaths = tempVec;
}
void CSVReader::SetSet(HashSet tempSet){
    restSet = tempSet;
}
/*
void CSVReader::SetMap(HashMap tempMap){
    restMap = tempMap;
}
 */


// other functions
void CSVReader::readInFiles(){

    //tempVars to read
    string tempName;
    string tempState;
    string tempCounty;
    string tempFoodType;
    string tempHours;
    string tempLong;
    string tempLat;
    string isChain = "-1";

    // for parsing over any data we don't need
    string trashVal;

    // go through all files in filepaths vector
    for (int i = 0; i < filepaths.size(); i++){

        // opens current file in vector
        ifstream file;
        file.open(filepaths[i]);

        // reads header line
        getline(file, trashVal);

        // reads data
        while (!file.eof()) {
            // takes in csv data
            getline(file, tempName, ',');
            getline(file, tempFoodType, ',');
            getline(file, tempHours, ',');
            getline(file, tempState, ',');
            getline(file, trashVal, ',');
            getline(file, tempCounty, ',');
            getline(file, trashVal, ',');
            getline(file, trashVal, ',');
            getline(file, trashVal, ',');
            getline(file, trashVal, ',');
            getline(file, tempLong, ',');
            getline(file, tempLat, ',');
            getline(file, trashVal, ',');
            getline(file, isChain);

            tempName.erase(remove(tempName.begin(),tempName.end(),'\"'),tempName.end());
            tempFoodType.erase(remove(tempFoodType.begin(),tempFoodType.end(),'\"'),tempFoodType.end());
            tempHours.erase(remove(tempHours.begin(),tempHours.end(),'\"'),tempHours.end());
            tempState.erase(remove(tempState.begin(),tempState.end(),'\"'),tempState.end());
            tempCounty.erase(remove(tempCounty.begin(),tempCounty.end(),'\"'),tempCounty.end());

            // if the restaurant is not a chain it adds it to the data structures
            if(stoi(isChain) == 0){
                Restaurant tempRest(tempName, tempState, tempCounty, tempFoodType, tempHours, stof(tempLong), stof(tempLat));
                //tempRest.printRestaurant(); //for testing
                restSet.insert(tempRest);
            }
        }
        file.close();
    }
}
