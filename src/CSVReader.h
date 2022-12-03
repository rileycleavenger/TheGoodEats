#include "Restaurant.h"
#inlcude "HashMap.h"
#inlcude "HashSet.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <assert.h>

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
    void SetFilepaths(vector<string> tempVec);
    void SetMap(HashMap tempMap);
    void SetSet(HashSet tempSet);

    // other functions
    void readInFiles();

};