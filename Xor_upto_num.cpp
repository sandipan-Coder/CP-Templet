#include<bits/stdc++.h>
using namespace std;

int xorUptoNum(int n){

    if(n % 4 == 0)
        return n;
    else if(n % 4 == 1)
        return 1;
    else if(n % 4 == 2)
        return n+1;
    else
        return 0;
}

int main(){

    int num;
    cin >> num;

    cout << "Xor 1 to num is : " << xorUptoNum(num);

    return 0;
}