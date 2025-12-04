/*

    You are given a set of distinct keys in sorted order, which is represent by keys[]. Each key ki represents a data record that is accessed during a seach operation. For all the keys, you are also given a frequency array freq[], which denotes how many times key ki is searched for.
    The cost of accessing a key in a binary search tree is calculated by multiplying its access frequency by the level at which it appears in the tree. Therefore different arrangements of keys in the BST gives different total search costs.

    Your task is to calculate the minimum total search cost required to construct a binary search tree containing all the keys.

    Note: Consider the root of the BST is at level 1.

*/
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int> &keys, vector<int> &freq) {
        
    int n = keys.size();
    vector<int> prefixSum(n, 0);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    prefixSum[0] = freq[0];
    for(int i = 1; i < n; i++)
        prefixSum[i] = (prefixSum[i - 1] + freq[i]);
    
        // Base case: single key
    for(int i = 0; i < n; i++)
        dp[i][i] = freq[i];
    
    
    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            
            int j = i + len - 1;

            int ans = INT_MAX;
            int weight = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

            // Try every key as root
            for(int k = i; k <= j; k++){
                int cost =
                    (k > i ? dp[i][k - 1] : 0) +
                    (k < j ? dp[k + 1][j] : 0) +
                    weight;

                ans = min(ans, cost);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n - 1];
}


//? Cost[i][j] = min{Cost[i][k - 1] + Cost[k + 1][j]} + weight(i,j);
//? k = i -> j

//?  Weight(i,j) = ∑ f(p) (p = (i -> j));