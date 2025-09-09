#include<bits/stdc++.h>
using namespace std;

int main(){

    int a, b, n, i;
    cin>>a >> b >> n >> i;

    // Swap two number without using third variables
    cout<<"************************** This is the swapping of two number ******************************" << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << b;
    cout<<endl;

    // Check if ith bit set or not
    cout<<"*************************** This is check if ith bit is set or not *****************************"<<endl;
    if((n & (1 << i)) != 0)
        cout<<"Set bit"<<endl;
    else
        cout<<"Not set bit"<<endl;
    
    cout<<"****************  Another Process  *********************"<<endl;
    if(((n >> i) & 1) == 1)
        cout<<"Set bit"<<endl;
    else
        cout<<"Not set bit"<<endl;

    // Set the ith bit
    cout<<"********************* Set the ith bit for the given number *******************" << endl;
    int ans = (n | (1 << i));
    cout << ans << endl;

    // Clear the ith bit
    cout<<"*********************  Clear the ith bit **************************" << endl;
    int res = (n & ~(1 << i));
    cout << res << endl;

    // Toggling the ith bit
    cout << "************************ Toggling the ith bit **************************" << endl;
    int ans2 = (n ^ (1 << i));
    cout << ans2 << endl;

    // Removing the last set bit (Right Most)
    cout << "************************ Removing last set bit(Rightmost) **************************" << endl;
    int ans3 = (n & (n - 1));
    cout << ans3 << endl;

    // Checking if the number is power of 2
    cout << "************************ Power of 2 **************************" << endl;
    if((n & (n - 1)) == 0)
        cout<< "Power of 2" << endl;
    else
        cout<< "Not power of 2" << endl;
    
    // Count the number of set bits
    cout << "************************ Count the number of set bits **************************" << endl;
    int count = 0;
    int num;
    cin>>num;
    while(num){
        num = (num & (num - 1));
        count++;
    }
    cout << count << endl;
    cout<<"****************  Another Process using STL *********************"<<endl;
    int ans4 = __builtin_popcount(n);
    cout<< ans4 << endl;

    return 0;
}



