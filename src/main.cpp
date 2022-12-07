//
// Created by Riley Cleavenger on 12/3/22.
//
#include "CSVReader.h"
#include <chrono>

using namespace std;

int main(){

    cout << endl << "Reading in data..." << endl;
    // data set is in 3 files, so have to store it accordingly
    vector<string> dataSets;
    dataSets.push_back("CSV/chainness_point_2021_part1.csv");
    dataSets.push_back("CSV/chainness_point_2021_part2.csv");
    dataSets.push_back("CSV/chainness_point_2021_part3.csv");

    // create reader object and take in data, storing them in Hash Sets and Hash Sets
    CSVReader mainData(dataSets);
    mainData.readInFiles();

    // hash Set = mainData.GetSet()
    // hash Map = mainData.GetMap()

    // create timer objects to record time it will take for each algorithm to run
    chrono::time_point <chrono::system_clock> startTime, endTime;
    chrono::duration<double> totalTime3;
    chrono::duration<double> totalTime4;
    chrono::duration<double> totalTime5;
    chrono::duration<double> totalTime6;
    bool optionThreeRan, optionFourRan, optionFiveRan, optionSixRan = false;

    bool running = true;

    while(running){
        //default choice value to display the menu
        int choice = 0;

        //displays menu by default
        if(choice == 0){
            // display menu options
            cout << endl;
            cout << "1. Display all restaurants from the hashset" << endl;
            cout << "2. Display all restaurants from the hashmap" << endl;
            cout << "3. Search by longitude/latitude from the hashset" << endl;
            cout << "4. Search by state/county from the hashset" << endl;
            cout << "5. Search by longitude/latitude from the hashmap" << endl;
            cout << "6. Search by state/county from the hashmap" << endl;
            cout << "7. Compare ALL search operations in both data structures and display the times for each to complete!" << endl;
            cout << "8. Quit" << endl << endl;
            cout << "Type your menu choice: ";
            cin >> choice;
        }

        if(choice == 1){
            //display all from hashset
            for(int i = 0; i < 50; i++){
                for(int j = 0; j < mainData.GetSet().getBucketList(i).getRestaurants().size(); j++){
                    mainData.GetSet().getBucketList(i).getRestaurants()[j].printRestaurant();
                    cout << endl;
                }
            }
        }
        else if(choice == 2){
            //display all from hashmap
            for(int i = 0; i < mainData.GetMap().getBucketList().size(); i++){
                for (int j = 0; j < mainData.GetMap().getBucketList()[i].getRestaurants().size(); j++) {
                    mainData.GetMap().getBucketList()[i].getRestaurants()[j].second.printRestaurant();
                    cout << endl;
                }
            }
        }
        else if(choice == 3){
            //search hashset long/lat
            float userLong, userLat;
            cout << "Insert a longitude: ";
            cin >> userLong;
            cout << "Insert a latitude: ";
            cin >> userLat;
            cout << endl << "Searching..." << endl << endl;
            startTime = chrono::system_clock::now();
            vector <Restaurant> resultVec = mainData.GetSet().searchLongLat(userLong, userLat);
            endTime = chrono::system_clock::now();
            totalTime3 = endTime - startTime;
            optionThreeRan = true;
            for(int i = 0; i < resultVec.size(); i++){
                if(i == 0)
                    cout << "Search Results: " << endl << endl;
                resultVec[i].printRestaurant();
                cout << endl;
            }
        }
        else if(choice == 4){
            //search hashset state/county
            string userState, userCounty;
            cout << "Insert a state: ";
            cin >> userState;
            cout << "Insert a county: ";
            cin >> userCounty;
            cout << endl << "Searching..." << endl << endl;
            startTime = chrono::system_clock::now();
            vector <Restaurant> resultVec = mainData.GetSet().find(userState, userCounty);
            endTime = chrono::system_clock::now();
            totalTime4 = endTime - startTime;
            optionFourRan = true;
            for(int i = 0; i < resultVec.size(); i++){
                if(i == 0)
                    cout << "Search Results: " << endl << endl;
                resultVec[i].printRestaurant();
                cout << endl;
            }
        }
        else if(choice == 5){
            //search hashMap long/lat
            float userLong, userLat;
            cout << "Insert a longitude: ";
            cin >> userLong;
            cout << "Insert a latitude: ";
            cin >> userLat;
            cout << endl << "Searching..." << endl << endl;
            startTime = chrono::system_clock::now();
            vector <Restaurant> resultVec = mainData.GetMap().searchLongLat(userLong, userLat);
            endTime = chrono::system_clock::now();
            totalTime5 = endTime - startTime;
            optionFiveRan = true;
            for(int i = 0; i < resultVec.size(); i++){
                if(i == 0)
                    cout << "Search Results: " << endl << endl;
                resultVec[i].printRestaurant();
                cout << endl;
            }
        }
        else if(choice == 6){
            //search hashMap state/county
            string userState, userCounty;
            cout << "Insert a state: ";
            cin >> userState;
            cout << "Insert a county: ";
            cin >> userCounty;
            cout << endl << "Searching..." << endl << endl;
            startTime = chrono::system_clock::now();
            vector <Restaurant> resultVec = mainData.GetSet().find(userState, userCounty);
            endTime = chrono::system_clock::now();
            totalTime6 = endTime - startTime;
            optionSixRan = true;
            for(int i = 0; i < resultVec.size(); i++){
                if(i == 0)
                    cout << "Search Results: " << endl << endl;
                resultVec[i].printRestaurant();
                cout << endl;
            }
        }
        else if(choice == 7)
        {
            //display times to search each algorithm
            if(optionThreeRan)
                cout << "Time to search hashMap with long/lat: " << totalTime3.count() << " seconds" << endl;
            if(optionFourRan)
                cout << "Time to search hashMap with State and County: " << totalTime4.count() << " seconds" << endl;
            if(optionFiveRan)
                cout << "Time to search hashSet with long/lat: " << totalTime5.count() << " seconds" << endl;
            if(optionSixRan)
                cout << "Time to search hashSet with State and County: " << totalTime6.count() << " seconds" << endl;
        }
        else if(choice == 8){
            //quit
            running = false;
            cout << "Thanks for using our program!" << endl;
        }
        else if(choice > 8){
            cout << "Invalid input, try again!" << endl;
        }
    }

    return 0;
}
