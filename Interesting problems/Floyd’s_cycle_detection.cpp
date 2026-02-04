// ************************** Floyd’s cycle detection  ***********************

//? Problem :- Given a read-only array of N + 1 integers between 1 and N, find one number that repeats in linear time using 
// less than O(N) space and traversing the stream sequentially O(1) times. If there are multiple possible answers 
// ( like in the sample case ), output any one, if there is no duplicate, 
//! (output -1) :- This is invalid for this constraints


#include<bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {
   
   if(A.size() <= 1)
        return -1;
    
    int slow = A[0];
    int fast = A[0];
    
    do {
        slow = A[slow];
        fast = A[A[fast]];
    } while(slow != fast);
    
    slow = A[0];
    while(slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    
    return slow;
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for(int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = repeatedNumber(arr);
  cout << ans << endl;

  return 0;
}

// INPUT-1 :- 3, 4, 1, 4, 2          OUTPUT-1 :- 4
// INPUT-2 :- 1, 2, 3                OUTPUT-2 :- -1
// INPUT-3 :- 3, 4, 1, 4, 1          OUTPUT-3 :- 4 / 1



