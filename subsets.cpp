//? This is for create all the subsets of a given array.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> res;
    
    // Loop through all possible subsets
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set 
            if ((i & (1 << j)) != 0) {
                subset.push_back(arr[j]);
            }
        }
        
        // Push the subset into result
        res.push_back(subset);
    }