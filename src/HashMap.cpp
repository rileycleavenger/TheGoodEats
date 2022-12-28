#include "HashMap.h"

// hash function
int HashMap::hashFunction(string key){
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
    for(int i = 0; i < getBucketList().size(); i++){
       for (int j = 0; j < getBucketList()[i].getRestaurants().size(); j++) {
           if (getBucketList()[i].getRestaurants()[j].second.getState() == state &&
               getBucketList()[i].getRestaurants()[j].second.getCounty() == county) {
               returnVector.push_back((getBucketList()[i].getRestaurants()[j].second));
           }
       }
   }
   return returnVector;
};
std::vector<Restaurant> HashMap::searchLongLat(float longitude, float latitude){
    // match to lat/long key values (no negatives)
    float ogLong = longitude;
    float ogLat = latitude;
    longitude += 180;
    latitude += 90;
    std::vector<Restaurant> returnVector;
    int minKey;
    int maxKey;

    if(latitude >= 180 && longitude >= 360)
        maxKey = (latitude) * (longitude);
    else if(latitude >= 180)
        maxKey = (latitude) * (longitude + 1);
    else if(longitude >= 360)
        maxKey = (latitude + 1) * (longitude);
    else
        maxKey = (latitude + 1) * (longitude + 1);

    if(latitude < 1 && longitude < 1)
        minKey = (latitude) * (longitude);
    else if(latitude < 1)
        minKey = (latitude) * (longitude - 1);
    else if(longitude < 1)
        minKey = (latitude - 1) * (longitude);
    else
        minKey = (latitude - 1) * (longitude - 1);

    for(int i = minKey; i <= maxKey; i++){
        for(int j = 0; j < getBucketList()[i].getRestaurants().size(); j++){
            if(getBucketList()[i].getRestaurants()[j].second.getLongitude() >= (ogLong - 1) && getBucketList()[i].getRestaurants()[j].second.getLongitude() <= (ogLong + 1) && getBucketList()[i].getRestaurants()[j].second.getLatitude() >= (ogLat - 1) && getBucketList()[i].getRestaurants()[j].second.getLatitude() <= (ogLat + 1))
                returnVector.push_back((getBucketList()[i].getRestaurants()[j].second));
        }
    }

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
std::vector<pair<string, Restaurant> > mapBucket::getRestaurants(){
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
