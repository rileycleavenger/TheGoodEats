#include <string>
#include <iostream>

using namespace std;

class Restaurant{
private:

    // class variables
    string name;
    string state;
    string county;
    string foodType;
    string hours;
    float longitude;
    float latitude;

public:

    // getters
    string getName();
    string getState();
    string getCounty();
    string getFoodType();
    string getHours();
    float getLongitude();
    float getLatitude();

    // setters
    void setName(string name_);
    void setState(string state_);
    void setCounty(string county_);
    void setFoodType(string foodType_);
    void setHours(string hours_);
    void setLongitude(float longitude_);
    void setLatitude(float latitude_);

    // constructors
    Restaurant();
    Restaurant(string name_, string state_, string county_, string foodType_, string hours_, float longitude_, float latitude_);

    // other functions
    void printRestaurant();
};

