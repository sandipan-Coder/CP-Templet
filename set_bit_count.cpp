// This function will return no. of set bit in a given number.


int fun(int n) {

    int count = 0;

    while(n) {

        n &= (n - 1);
        count++;
    }

    return count;
}
