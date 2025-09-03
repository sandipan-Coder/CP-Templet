// Brute force
vector<int> sieve(int n){

    vector<bool> isPrime(n+1, true);
    
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i <= n; i++){

        if(isPrime[i]){  // T.C :- O(N loglog(N))

            for(int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

// Optimal
vector<int> sieve(int n){

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