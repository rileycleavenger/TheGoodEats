#include <list>
#include "Restaurant.h"
#include <vector>
#pragma once

class mapBucket{
    private:
        // class variables
        int hashCode; // hashcode identifying the bucket (the states name)
        std::vector<pair<string,Restaurant>> chainList; // vector of restaurant "chained" in this bucket
    public:
        // getters
        int getHashCode(); // returns hashcode integer
        std::vector<pair<string, Restaurant>> getRestaurants(); // returns vector of "chained" restaurants stored in bucket

        // setters
        void addRestaurant(string key, Restaurant R); // adds a restuarant to bucket
        void setHashCode(int code); // sets the hashcode for bucket

        // constructors
        mapBucket();
        mapBucket(int code);
};

class HashMap{
    private:
        // class variables
        vector<mapBucket> bucketList; // vector of buckets (each bucket hashcode is it's index in the array)
    public:
        // getters
        std::vector<Restaurant> find(string state, string county); // returns a vector of restuarants in the specified state/county
        std::vector<Restaurant> searchLongLat(float longitude, float latitude);
        // setters
        void insert(string key, Restaurant R); // inserts a new restaurant into the hashSet

        // getters
        vector<mapBucket> getBucketList();

        // constructors
        HashMap();

        // destructors
        ~HashMap();
        
        // hash function
        int hashFunction(string state);
};
