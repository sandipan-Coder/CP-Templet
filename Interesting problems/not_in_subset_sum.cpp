/*

    Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

    Examples:

    Input: arr[] = [3, 1, 2]
    Output: 7
    Explanation: 7 is the smallest positive number for which no subset is there with sum 7.

    Input: arr[] = [3, 10, 9, 6, 20, 28]
    Output: 1
    Explanation: 1 is the smallest positive number for which no subset is there with sum 1.

    Constraints
        1 ≤ arr.size() ≤ 105
        1 ≤ arr[i] ≤ 103


*/

#include<bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> &arr) {
        
    int res = 1;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() && arr[i] <= res; i++) 
        res += arr[i];

    return res;
}

int main() {
	vector<int> arr = {1, 10, 3, 11, 6, 15};
	cout << findSmallest(arr);

	return 0;
}

// OUTPUT :- 2
// LINK :- https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1