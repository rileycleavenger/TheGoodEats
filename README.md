# TheGoodEats

**Overview:**

This program was developed to encourage support of local restaurants, and to stay away from chains.

This application pulls from a data set of 700,000 restaurants in the US and returns only non-chain restaurants in your area based on either     latitude/longitude or state/country. This was implemented using both a hashmap and hashset, and the runtimes can be displayed in the program as well to compare performance.

Download the files and run ./app in Terminal to use the application.


**Time Complexity Analysis:**

Within both the hashset and hashmap we implemented a search function for county/state, a search function for longitude/latitude, and an insertion function. For the sake of our complexity analysis, n will be the number of objects in each bin for separately chained items, and k will be the total number of bins. Searching based on county and state within the hashset was done in O(n) time, as the hashing function is based on the state in which the restaurant is located, resulting in the ability to go straight to the desired bin and search through all of its chained elements. Searching based on longitude/latitude in the hashset is done in O(kn) time as the data is not organized in any way based on the longitude and latitude values, so therefore we must look through all of the bins, k, and all of the items within each bin. The insertion function in the hashset is O(1) as it finds the correct bin for the new Restaurant and sorts it accordingly. In the hashmap the function to search my state and country takes O(kn) time as the hashing function in the map isn’t based on state or county at all. Conversely, since the hash function is the product of longitude and latitude in the map, the search by longitude/latitude function takes O(n) time, as we search in a range of +/- 1 longitude and latitude, then their product. More specifically its O(cn) time where c is some coefficient equal to ((longitude + 1)*(latitude + 1)) - ((longitude - 1)*(latitude - 1)), but this coefficient is negligible compared to the total number of bins, so therefore simplifies down to O(n). Finally, similar to the hashset, the insertion function for the hashmap is also O(1) time complexity. We separately timed each of the different search functions (long/lat and state/county) using the hashmap and hashset to compare the time it took each to run. To search for restaurants by latitude and longitude from the hashmap it took 8.07 seconds. Searching for restaurants by state and county from the hashmap took 2466.29 seconds. To search for restaurants by latitude and longitude from the hashset it took 11.92 seconds. Searching for restaurants by state and county from the hashset took 0.007 seconds. 

