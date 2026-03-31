#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main() {
    
    auto start = high_resolution_clock::now();

    // 🔹 Code block to measure
    for (int i = 0; i < 1000000; i++) {
        // some operation
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}