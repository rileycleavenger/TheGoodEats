#include <list>
#include "Restaurant.h"
#include <vector>

class HashMap{
    private:
        // class variables
        bucket bucketList[64800]; // array of buckets (each bucket hashcode is it's index in the array)
    public:
        // getters
        std::vector<Restaurant> find(string state, string county); // returns a vector of restuarants in the specified state/county

        // setters
        void insert(Restaurant R); // inserts a new restaurant into the hashmap

        // constructors
        HashMap();

        // destructors
        ~HashMap();
        
        // hash function
        int hashFunction(float longitude, float latitude);
};

class bucket{
    private:
        // class variables
        int hashCode; // hashcode identifying the bucket
        std::vector<Restaurant> chainList; // vector of restaurant "chained" in this bucket
    public:
        // getters
        int getHashCode(); // returns hashcode integer
        std::vector<Restaurant> getRestaurants(); // returns vector of "chained" restaurants stored in bucket

        // setters
        void addRestaurant(Restaurant R); // adds a restuarant to bucket
        void setHashCode(int code); // sets the hashcode for bucket

        // constructors
        bucket();
        bucket(int code);
};