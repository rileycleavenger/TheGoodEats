#include "HashMap.h"

// hash function
int HashMap::hashFunction(string key){
    /*
    string states[50] = {"AK","AL","AR","AZ","CA","CO","CT","DE","FL","GA","HI","IA","ID","IL","IN","KS","KY","LA","MA","MD","ME","MI","MN","MO","MS","MT","NC","ND","NE","NH","NJ","NM","NV","NY","OH","OK","OR","PA","RI","SC","SD","TN","TX","UT","VA","VT","WA","WI","WV","WY"};
    for(int i = 0; i < 50; i++){
        if(state == states[i]){
            return i;
        }
    }
    return -1;
    */
   string lat = "";
   string longi = "";
   bool firstHalf = true;
   for(int i = 0; i < key.length(); i++){
        if(key[i] == '_'){
            firstHalf = false;
            continue;
        }
        if(firstHalf){
            lat += key[i];
        } else {
            longi += key[i];
        }
   }
    int hashVal = stof(lat) * stof(longi);
    return hashVal;
}

// hash Map getters
std::vector<Restaurant> HashMap::find(string state, string county){
    std::vector<Restaurant> returnVector;
    /*
    std::vector<Restaurant> returnVector; // vector of all restaurants in county/state (initially empty)
    std::vector<pair<string,Restaurant>> temp; //array of all restaurants in specified state
    int index = hashFunction(state);
    temp = bucketList[index].getRestaurants();
    for(int j = 0; j < temp.size(); j++){
        if(temp[j].second.getCounty() == county){
            returnVector.push_back(temp[j].second);
        }
    }
    return returnVector;
    */
   for(int i = 0; i < getBucketList().size(); i++){
        for(int j = 0; j < getBucketList()[i].getRestaurants().size(); j++){
            if(getBucketList()[i].getRestaurants()[j].second.getState() == state && getBucketList()[i].getRestaurants()[j].second.getCounty() == county){
                returnVector.push_back((getBucketList()[i].getRestaurants()[j].second));
            }
        }
    }
};
std::vector<Restaurant> HashMap::searchLongLat(float longitude, float latitude){
    // match to lat/long key values (no negatives)
    longitude += 180;
    latitude += 90;
    std::vector<Restaurant> returnVector;
    int maxKey = (latitude + 1) * (longitude + 1);
    int minKey = (latitude - 1) * (longitude - 1);
    for(int i = minKey; i <= maxKey; i++){
        for(int j = 0; j < getBucketList()[i].getRestaurants().size(); j++){
            returnVector.push_back((getBucketList()[i].getRestaurants()[j].second));
        }
    }

    //std::vector<Restaurant> temp;
    /*
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < getBucketList(i).getRestaurants().size(); j++){
            if(getBucketList(i).getRestaurants()[j].getLatitude() > latitude - 1 && getBucketList(i).getRestaurants()[j].getLatitude() < latitude + 1 && getBucketList(i).getRestaurants()[j].getLongitude() > longitude - 1 && getBucketList(i).getRestaurants()[j].getLongitude() < longitude + 1){
                returnVector.push_back(getBucketList(i).getRestaurants()[j]);
            }
        }
    }
    */

    return returnVector;
}
vector<mapBucket> HashMap::getBucketList(){
    return bucketList;
}

// hash Map setters
void HashMap::insert(string key, Restaurant R){
    int code = hashFunction(key);
    bucketList[code].addRestaurant(key, R);   
    return;
};

// hash Map constructors
HashMap::HashMap(){
    for(int i = 0; i <= 64800; i++){
        //bucketList[i] = bucket(i);
        bucketList.push_back(mapBucket(i));
    }
    return;
};

// hash Map destructors
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
int mapBucket::getHashCode(){
    return hashCode;
};
std::vector<pair<string, Restaurant>> mapBucket::getRestaurants(){
    // returns vector of chained restaurants with the same code
    return chainList;
};

// bucket setters
void mapBucket::addRestaurant(string key, Restaurant R){
    chainList.push_back(make_pair(key, R));
    return;
};
void mapBucket::setHashCode(int code){
    hashCode = code;
    return;
};

// bucket constructors

mapBucket::mapBucket(int code){
    setHashCode(code);
};

mapBucket::mapBucket(){
    setHashCode(-1);
}
