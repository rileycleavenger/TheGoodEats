//
// Created by Riley Cleavenger on 12/3/22.
//

#ifndef PROJECT3_CSVREADER_H
#define PROJECT3_CSVREADER_H
#include "Restaurant.h"
#include <string>

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
    CSVReader(vector<string> filepaths);

    // getters
    vector<string> GetFilepaths();
    HashMap<Restaurant> GetMap();
    HashSet<Restaurant> GetSet();

    // setters;
    vector<string> SetFilepaths();
    HashMap<Restaurant> SetMap();
    HashSet<Restaurant> SetSet();

    // other functions
    void readInFiles();

};

#endif //PROJECT3_CSVREADER_H
