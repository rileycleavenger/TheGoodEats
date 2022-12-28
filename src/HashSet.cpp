#include "HashSet.h"

// hash function
int HashSet::hashFunction(string state){
    string states[50] = {"AK","AL","AR","AZ","CA","CO","CT","DE","FL","GA","HI","IA","ID","IL","IN","KS","KY","LA","MA","MD","ME","MI","MN","MO","MS","MT","NC","ND","NE","NH","NJ","NM","NV","NY","OH","OK","OR","PA","RI","SC","SD","TN","TX","UT","VA","VT","WA","WI","WV","WY"};
    for(int i = 0; i < 50; i++){
        if(state == states[i]){
            return i;
        }
    }
    return -1;
}

// hash Set getters
std::vector<Restaurant> HashSet::find(string state, string county){
    std::vector<Restaurant> returnVector; // vector of all restaurants in county/state (initially empty)
    std::vector<Restaurant> temp; //array of all restaurants in specified state
    int index = hashFunction(state);
    temp = bucketList[index].getRestaurants();
    for(int j = 0; j < temp.size(); j++){
        if(temp[j].getCounty() == county){
            returnVector.push_back(temp[j]);
        }
    }
    return returnVector;
};
std::vector<Restaurant> HashSet::searchLongLat(float longitude, float latitude){
    std::vector<Restaurant> returnVector;
    //std::vector<Restaurant> temp;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < getBucketList(i).getRestaurants().size(); j++){
            if(getBucketList(i).getRestaurants()[j].getLatitude() > latitude - 1 && getBucketList(i).getRestaurants()[j].getLatitude() < latitude + 1 && getBucketList(i).getRestaurants()[j].getLongitude() > longitude - 1 && getBucketList(i).getRestaurants()[j].getLongitude() < longitude + 1){
                returnVector.push_back(getBucketList(i).getRestaurants()[j]);
            }
        }
    }
    return returnVector;
}
bucket HashSet::getBucketList(int index){
    return bucketList[index];
}

// hash Set setters
void HashSet::insert(Restaurant R){
    int code = hashFunction(R.getState());
    bucketList[code].addRestaurant(R);   
    return;
};

// hash Set constructors
HashSet::HashSet(){
    for(int i = 0; i < 50; i++){
        bucketList[i] = bucket(i);
    }
    return;
};

// hash Set destructors
HashSet::~HashSet(){
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
bucket::bucket(){
    setHashCode(-1);
}