// Generate Prime factors for a given number.
// Example1 :- 100 = 2^2 * 5^2
// Example2 :- 15 = 3^1 * 5^1

//? Brute Force
vector<pair<int, int>> generatePrimeFactors(int n){

    vector<pair<int, int>> ans;

    for(int i = 2; i <= n; i++){

        if(n % i == 0){

            int count = 0;      // T.C :- O(N logN)

            while(n % i == 0){
                count++;
                n /= i;
            }

            ans.push_back({i, count});
        }
    }

    return ans;
}


//? Optimal
vector<pair<int, int>> generatePrimeFactors(int n){

    vector<pair<int, int>> ans;

    for(int i = 2; i*i <= n; i++){

        if(n % i == 0){

            int count = 0;    // T.C :- O(√N logN)

            while(n % i == 0){
                count++;
                n /= i;
            }

            ans.push_back({i, count});
        }
    }

    if(n > 1)
        ans.push_back({n, 1});

    return ans;
}