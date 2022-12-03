#include "HashMap.h"

// hash function
int HashMap::hashFunction(float longitude, float latitude){
    int product = (longitude + 180) * (latitude + 90);
    return product;
}

// hash map getters
std::vector<Restaurant> HashMap::find(string state, string county){
    // traverse through hashmap checking restuarant state/county
    std::vector<Restaurant> returnVector; // vector of all restaurants in county/state (initially empty)
    // iterate through all buckets
    std::vector<Restaurant> temp;
    for(int i = 0; i < 64800; i++){
        temp = bucketList[i].getRestaurants();
        for(int j = 0; j < temp.size(); j++){
            if(temp[j].getCounty() == county && temp[j].getState() = state){
                returnVector.push_back(temp[j]);
            }
        }
    }
    return returnVector;
};

// hash map setters
void HashMap::insert(Restaurant R){
    int code = hashFunction(R.getLongitude(), R.getLatitude());
    bucketList[code].addRestaurant(R);    
    return;
};

// hash map constructors
HashMap::HashMap(){
    for(int i = 0; i < 64800; i++){
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