//
// Created by Riley Cleavenger on 11/22/22.
//

#include "Restaurant.h"

using namespace std;

// getters
string Restaurant::getName(){
    return name;
}
string Restaurant::getState(){
    return state;
}
string Restaurant::getCounty(){
    return county;
}
string Restaurant::getFoodType(){
    return foodType;
}
string Restaurant::getHours(){
    return hours;
}
float Restaurant::getLongitude(){
    return longitude;
}
float Restaurant::getLatitude(){
    return latitude;
}

// setters
void Restaurant::setName(string name_){
    name = name_;
}
void Restaurant::setState(string state_){
    state = state_;
}
void Restaurant::setCounty(string county_){
    county = county_;
}
void Restaurant::setFoodType(string foodType_){
    foodType = foodType_;
}
void Restaurant::setHours(string hours_){
    hours = hours_;
}
void Restaurant::setLongitude(float longitude_){
    longitude = longitude_;
}
void Restaurant::setLatitude(float latitude_){
    latitude = latitude_;
}

// constructors
Restaurant::Restaurant(){
    name = "";
    state = "";
    county = "";
    foodType = "";
    hours = "";
    longitude = 0.0f;
    latitude = 0.0f;
}
Restaurant::Restaurant(string name_, string state_, string county_, string foodType_, string hours_, float longitude_, float latitude_){
    name = name_;
    state = state_;
    county = county_;
    foodType = foodType_;
    hours = hours_;
    longitude = longitude_;
    latitude = latitude_;
}

// other functions
void Restaurant::printRestaurant(){
    cout << "name: " << name << endl;
    cout << "state: " << state << endl;
    cout << "county: " << county << endl;
    cout << "foodType: " << foodType << endl;
    cout << "hours: " << hours << endl;
    cout << "longitude: " << longitude << endl;
    cout << "latitude: " << latitude << endl;
}

