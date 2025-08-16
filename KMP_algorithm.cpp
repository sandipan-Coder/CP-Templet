#include<bits/stdc++.h>

// This function return longest length of prefix suffix of a string not return the input string.
// Example :- "aabcdaabc" 
// Ans :- 4 ("aabc") this substring is part of prefix also part of suffix
int LongestPrefixSuffix(string &str){

    int n = str.length();
    vector<int> lps(n, 0);  // The lps => Longest Prefix Suffix
    int pre = 0;
    int suff = 1;

    while(suff < n){

        if(str[pre] == str[suff]){
            lps[suff] = pre + 1;
            pre++;
            suff++;
        }
        else {
            if(pre == 0){
                lps[suff] = 0;
                suff++;
            }
            else 
                pre = lps[pre - 1];
        }
    }

    return lps[n - 1];
}

// Another approach

int getLPSLength(string &str){

    int n = str.length();
    //int len = 0; 
    vector<int> lps(n, 0);

    for(int i = 1; i < n; i++){

        int len = lps[i - 1];
        while(len > 0 && str[len] != str[i])
            len = lps[len - 1];
        
        if(str[i] == str[len])
            len++;
        
        lps[i] = len;
    }

    return lps[n - 1];
}