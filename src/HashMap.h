
//#ifndef PROJECT3_RESTAURANT_H
//#define PROJECT3_RESTAURANT_H
/*
class Restaurant{
private:

    // class varaibles
    string name;
    string state;
    string county;
    string foodType;
    vector<string> hours;
    float longitude;
    float latitude;

public:

    // getters
    string getName();
    string getState();
    string getCounty();
    string getFoodType();
    vector<string> getHours();
    float getLongitude();
    float getLatitude();

    // setters
    void setName(string name_);
    void setState(string state_);
    void setCounty(string county_);
    void setFoodType(string foodType_);
    void setHours(vector<string> hours_);
    void setLongitude(string longitude_);
    void setLatitude(string latitude_);

    // constructors
    Restaurant();
    Restaurant(string name_, string state_, string county_, string foodType_, vector<string> hours_, string longitude_, string latitude_);
};
*/
#include <list>
#include "Restaurant.h"

class HashMap{
    private:
        // class variables
        node(float K, Restaurant R) **table;
        F hashFunc;
    public:
        // getters
        bool find(float key1, float key2, Restaurant R);

        // setters
        void insert(float key1, float key2, Restuarant R);
        void removeNode(float key1, float key2);

        // constructors
        HashMap();

        // destructors
        ~HashMap();
        hashFunction(float key1, float key2);
};

class node{
    private:
        // class variables
        float hashCode;
        Restaurant rstrnt;
        node *nextNode;
    public:
        // getters
        float getHashCode();
        Restaurant getRestaurant();
        Node *getNextNode();

        // setters
        void setRestaurant(Restuarant R);
        void setHashCode(float code);
        void setNextNode(Node* next);

        // constructors
        HashNode(float K, const Restaurant R);
};
//#endif //PROJECT3_RESTAURANT_H