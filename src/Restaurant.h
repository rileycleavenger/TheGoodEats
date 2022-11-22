//
// Created by Riley Cleavenger on 11/22/22.
//

#ifndef PROJECT3_RESTAURANT_H
#define PROJECT3_RESTAURANT_H

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

#endif //PROJECT3_RESTAURANT_H
