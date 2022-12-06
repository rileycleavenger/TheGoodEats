//
// Created by Riley Cleavenger on 12/3/22.
//
#include "CSVReader.h"
#include <chrono>

using namespace std;

int main(){


    // data set is in 3 files, so have to store it accordingly
    vector<string> dataSets;
    dataSets.push_back("CSV/chainness_point_2021_part1.csv");
    dataSets.push_back("CSV/chainness_point_2021_part2.csv");
    dataSets.push_back("CSV/chainness_point_2021_part3.csv");

    // create reader object and take in data, storing them in Hash Sets and Hash Sets
    CSVReader mainData(dataSets);
    mainData.readInFiles();




    // hash Set = mainData.GetSet()
    // hash set = mainData.GetSet()

    // declare timing variables
    chrono::time_point<chrono::system_clock> startTime, endTime;

    // timing functions
    startTime = chrono::system_clock::now();
    vector<Restaurant> testVec = mainData.GetMap().searchLongLat(-74, 40.7);
    endTime = chrono::system_clock::now();
    chrono::duration<double> totalTime = endTime - startTime;
    cout << "Time to search hashMap with long/lat: " << totalTime.count() << " seconds" << endl;

    startTime = chrono::system_clock::now();
    vector<Restaurant> testVec2 = mainData.GetMap().find("HI", "Hawaii");
    endTime = chrono::system_clock::now();
    chrono::duration<double> totalTime2 = endTime - startTime;
    cout << "Time to search hashMap with State and County: " << totalTime2.count() << " seconds" << endl;

    startTime = chrono::system_clock::now();
    vector<Restaurant> testVec3 = mainData.GetSet().searchLongLat(-165.40257, 64.49702);
    endTime = chrono::system_clock::now();
    chrono::duration<double> totalTime3 = endTime - startTime;
    cout << "Time to search hashSet with long/lat: " << totalTime3.count() << " seconds" << endl;

    startTime = chrono::system_clock::now();
    vector<Restaurant> testVec4 = mainData.GetSet().find("AL", "Lee");
    endTime = chrono::system_clock::now();
    chrono::duration<double> totalTime4 = endTime - startTime;
    cout << "Time to search hashSet with State and County: " << totalTime4.count() << " seconds" << endl;

    return 0;
}
