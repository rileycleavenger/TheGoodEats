//
// Created by Riley Cleavenger on 11/22/22.
//

#include "Restaurant.h"

// getters
string Restaurant::getName(){
    return name;
}
string Restaurant::getState(){
    retuen state;
}
string Restaurant::getCounty(){
    return county;
}
string Restaurant::getFoodType(){
    return foodType;
}
vector<string> Restaurant::getHours(){
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
void Restaurant::setHours(vector<string> hours_){
    hours = hours_;
}
void Restaurant::setLongitude(string longitude_){
    longitude = longitude_;
}
void Restaurant::setLatitude(string latitude_){
    latitude = latitude_;
}

// constructors
Restaurant::Restaurant(){
    name = "";
    state = "";
    county = "";
    foodType = "";
    hours = [""];
    longitude = 0.0f;
    latitude = 0.0f;
}
Restaurant::Restaurant(string name_, string state_, string county_, string foodType_, vector<string> hours_, string longitude_, string latitude_){
    name = name_;
    state = sate_;
    county = county_;
    foodType = foodType_;
    hours = hours_;
    longitude = longitude_;
    latitude = latitude_;
}

