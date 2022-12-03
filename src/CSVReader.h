//
// Created by Riley Cleavenger on 12/3/22.
//

#ifndef PROJECT3_CSVREADER_H
#define PROJECT3_CSVREADER_H
#include "Restaurant.h"
#include <string>
#include <vector>

using namespace std;

class CSVReader{
private:
    // variables
    vector<string> filepaths;
    HashMap<Restaurant> restMap;
    HashSet<Restaurant> restSet;

public:
    // constructors
    CSVReader();
    CSVReader(vector<string> filepaths_);

    // getters
    vector<string> GetFilepaths();
    HashMap<Restaurant> GetMap();
    HashSet<Restaurant> GetSet();

    // setters;
    vector<string> SetFilepaths(vector<string> tempVec);
    HashMap<Restaurant> SetMap(HashMap tempMap);
    HashSet<Restaurant> SetSet(HashSet tempSet);

    // other functions
    void readInFiles();

};

#endif //PROJECT3_CSVREADER_H
