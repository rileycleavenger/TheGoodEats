#include "Restaurant.h"
#include "HashSet.h"
#include "HashMap.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <assert.h>
#pragma once

using namespace std;

class CSVReader{
private:
    // variables
    vector<string> filepaths;
    HashSet restSet;
    HashMap restMap;

public:
    // constructors
    CSVReader();
    CSVReader(vector<string> filepaths_);

    // getters
    vector<string> GetFilepaths();
    HashSet GetSet();
    HashMap GetMap();

    // setters;
    void SetFilepaths(vector<string> tempVec);
    void SetSet(HashSet tempSet);
    void SetMap(HashMap tempSet);

    // other functions
    void readInFiles();

};