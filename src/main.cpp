//
// Created by Riley Cleavenger on 12/3/22.
//
#include "CSVReader.h"

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

    vector<Restaurant> testVec = mainData.GetSet().find("FL", "Monroe");

    for(int i = 0; i < testVec.size(); i++) {
        testVec[i].printRestaurant();
    }


    return 0;
}