/*
    You are given an integer array arr[] of size n. The array elements represent n coins of values v1, v2, ....vn.
    You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value.
    You need to determine the maximum possible amount of money you can win if you go first.
    Note: Both the players are playing optimally.

    Input: arr[] = [5, 3, 7, 10]
    Output: 15
    Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.

    Input: arr[] = [8, 15, 3, 7]
    Output: 22
    Explanation: The user collects the maximum value as 22(7 + 15). It is guaranteed that we cannot get more than 22 by any possible moves.
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive Solution
int solve(int i, int j, vector<int> &arr){
    
    // Base Case
    if(i > j)
        return 0;
    
    
    int takeFirst = arr[i] + min(solve(i+1, j-1, arr), solve(i+2, j, arr));
    
    int takeLast = arr[j] + min(solve(i, j-2, arr), solve(i+1, j-1, arr));
    
    return max(takeFirst, takeLast);
}

// Recursive + Memoization
int solveMem(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    
    // Base case
    if(i > j)
        return 0;
        
    if(dp[i][j] != -1)
        return dp[i][j];
    // Option 1: Take the first element arr[i], and then
    //we have two choices:
    // - Skip arr[i+1] and solve the problem for range [i+2, j]
    // - Take arr[i+1] and arr[j-1] (we solve the problem for range [i+1, j-1])    
    int takeFirst = arr[i] + min(solveMem(i+1, j-1, arr, dp), 
                                solveMem(i+2, j, arr, dp));
    
    
    // Option 2: Take the last element arr[j], and then we have
    //two choices:
    // - Skip arr[j-1] and solve the problem for range [i, j-2]
    // - Take arr[i+1] and arr[j-1] (we solve the problem for range [i+1, j-1])
    int takeLast = arr[j] + min(solveMem(i, j-2, arr, dp), 
                                solveMem(i+1, j-1, arr, dp));
    
    return dp[i][j] = max(takeFirst, takeLast);
}

// Bottom-Up approach
int solveBottomUp(vector<int> &arr) {
    
    int n = arr.size();
    
    int dp[n][n] = {0};
    
    // If there have only one Coin then player must choose this one
    /*
    for(int i = 0; i < n; i++)
        dp[i][i] = arr[i];
    
    // If there have 2 coins then the player must choose max of this 2.    
    for(int i = 0; i < n-1; i++)
        dp[i][i+1] = max(arr[i], arr[i+1]);
    */
    
    
    // Fill table using above recursive formula. 
    // Note that the table is filled in diagonal fashion,
    // from diagonal elements to table[0][n-1] which is the result.
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {

            // Here x is value of F(i+2, j),
            // y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive formula
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
    
}


//? Main function
int maximumAmount(vector<int> &arr) {
        
    int n = arr.size();
    
    // Recursive Solution
    /*
    int ans = solve(0, n-1, arr);
    return ans;
    */
    
    // Recursive + Memoization
    /*
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = solveMem(0, n-1, arr, dp);
    
    return ans;
    */
    
    // Bottom-Up approach
    int ans = solveBottomUp(arr);
    
    return ans;
}

//! Problem Link :- https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
//? Document Link :- https://www.geeksforgeeks.org/dsa/optimal-strategy-for-a-game-dp-31/