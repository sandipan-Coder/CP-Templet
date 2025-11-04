
//? **************************** For This question ❓ ************************************
/*
Given a string S and a pattern P of all lowercase characters. The task is to check if the pattern exists in the string or not.

Example 1:
Input:      S = aabaacaadaabaaba
            P = aaaab
Output: No

Explanation: Given pattern is not found
in the given string S.

Example 2:
Input:      S = aabaacaadaabaaba
            P = caada
Output: Yes

Explanation: Given pattern is found in
the given string S.
*/

//! *********************************** Solution ✔️ **************************************

// Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string pat, int M, int* lps) {
    
    lps[0] = 0;
    
    for(int i = 1; i < M; i++){
        
        int len = lps[i - 1];
        while(len > 0 && pat[i] != pat[len])
            len = lps[len - 1];
        
        if(pat[i] == pat[len])
            len++;
        
        lps[i] = len;
    }
    
    return;    
}

// Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) {
    
    int n = txt.size();
    int m = pat.size();
    int i = 0;
    int j = 0;
    int LPS[m] = {0};
    
    computeLPSArray(pat, m, LPS);
    
    while(i < n){
        
        if(txt[i] == pat[j]){
            i++;
            j++;
            
            if(j == m)
                return true;
        }
        else if(txt[i] != pat[j]){
            
            if(j != 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }
    
    return false;
}

//? **************************** Time & Space Complexity **********************************

/*

    Expected Time Complexity: O(N+M).
    Expected Auxiliary Space: O(M).
    Note: N = |S|, M = |P|.

*/