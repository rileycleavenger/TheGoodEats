#include "HashMap.h"

// hash function
int HashMap::hashFunction(string state){
    string states[50] = {"AK","AL","AR","AZ","CA","CO","CT","DE","FL","GA","HI","IA","ID","IL","IN","KS","KY","LA","MA","MD","ME","MI","MN","MO","MS","MT","NC","ND","NE","NH","NJ","NM","NV","NY","OH","OK","OR","PA","RI","SC","SD","TN","TX","UT","VA","VT","WA","WI","WV","WY"};
    for(int i = 0; i < 50; i++){
        if(state == states[i]){
            return i;
        }
    }
    return -1;
}

// hash map getters
std::vector<Restaurant> HashMap::find(string state, string county){
    std::vector<Restaurant> returnVector; // vector of all restaurants in county/state (initially empty)
    std::vector<Restaurant> temp; //array of all restaurants in specified state
    int index = hashFunction(state);
    temp = temp = bucketList[index].getRestaurants();
    for(int j = 0; j < temp.size(); j++){
        if(temp[j].getCounty() == county){
            returnVector.push_back(temp[j]);
        }
    }
    return returnVector;
};

// hash map setters
void HashMap::insert(Restaurant R){
    int code = hashFunction(R.getState());
    bucketList[code].addRestaurant(R);   
    return;
};

// hash map constructors
HashMap::HashMap(){
    for(int i = 0; i < 50; i++){
        bucketList[i] = bucket(i);
    }
    return;
};

// hash map destructors
HashMap::~HashMap(){
/*
    std::vector<Restaurant> temp;
    for(int i = 0; i < 64800; i++){
        temp = bucketList[i].getRestaurants();
        for(int j = 0; j < temp.size(); j++){
            
        }
    }
*/
    return;
};

// bucket getters
int bucket::getHashCode(){
    return hashCode;
};
std::vector<Restaurant> bucket::getRestaurants(){
    // returns vector of chained restaurants with the same code
    return chainList;
};

// bucket setters
void bucket::addRestaurant(Restaurant R){
    chainList.push_back(R);
    return;
};
void bucket::setHashCode(int code){
    hashCode = code;
    return;
};

// bucket constructors
bucket::bucket(int code){
    setHashCode(code);
};