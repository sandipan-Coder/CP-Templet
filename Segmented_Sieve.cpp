// This is require for small range but long boundary perpous
#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){

    vector<bool> isPrime(n+1, true);
    
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i*i <= n; i++){

        if(isPrime[i]){  // T.C :- O(N loglog(√N))

            for(int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

vector<bool> getPrimeInRange(long long L, long long R){

    vector<bool> prime = sieve(sqrt(R));
    vector<bool> isPrime(R-L+1, true);

    for(long long i = 2; i*i <= R; i++){
        if(!prime[i])
            continue;
        
        for(long long j = max(i*i, (L+i-1) / i*i); j <= R; j += i)
            isPrime[j - L] = false;
    }

    if(L == 1)
        isPrime[0] = false;

    return isPrime;
}

// T.C :- O((R - L + 1)loglog(R) + √Rloglog(√R))

int main() {

        int L, R;
        cin >> L >> R;

        vector<bool> ans = getPrimeInRange(L, R);

        for(int i = 0; i < ans.size(); i++){
            if(ans[i])
                cout << L + i << " ";
        }
        cout<< endl;

    return 0;
}