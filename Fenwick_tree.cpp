/*
    For this question:
    Problem statement
You are given a N * M matrix GRID. You are also given Q queries. Your task is to Perform two types of query-

1) Find the sum of the rectangular submatrix defined by the upper left corner and lower right corner for each query. The position of the upper left and lower right corner is given.

2) Change the value of the element at a given position. Position and the new value of the cell are given. 

All indexes are 0 based.
For example:

GRID =[ [1, 2, 3],
        [4, 5, 6],
        [7, 8, 0] ]
Q = 2
Update element at (3,3) to 9 
left corner = (1, 1), right corner = (2, 2)
submatrix=[ [5, 6],
            [8, 9] ]   
Answer = 28
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N, M <= 1000 
1 <= Q <= 10 ^ 5
-10^4 <= GRID[i] <= 10^4

‘Q’ is the number of queries.
‘N’, ‘M’, GRID[i] is the number of rows, number of columns and cell value of GRID.

Time Limit: 1 sec
Sample Input 1:
2
1 4 3
7 5 3 2 
1 0 0 0 1
2 0 0 2
1 0 0 0 1
2 2 1
1 1 
1 1
1 0 0 1 1
Sample Output 1:
12 7
4
Explanation of Sample Input 1:
For the first test case, the first query submatrix is [[7, 5]]
After second query array becomes= [2, 5, 3, 2]
For third query submatrix is [[2, 5]]
For the second test case, first query submatrix is [[1, 1], [1, 1]] 
Sample Input 2:
2
2 2 3
-1 1
-1 -1
1 0 1 1 1
2 1 0 1 
1 1 0 1 1
1 1 1
0
1 0 0 0 0  
Sample Output 2:
0 0
0

*/

// Coding Implementation
#include <bits/stdc++.h>
using namespace std;

class Fenwick2D {
    int n, m;
    vector<vector<long long>> bit;
public:
    Fenwick2D(int n, int m) : n(n), m(m), bit(n+1, vector<long long>(m+1, 0)) {}

    void add(int x, int y, long long delta) {
        for (int i = x+1; i <= n; i += (i & -i)) {
            for (int j = y+1; j <= m; j += (j & -j)) {
                bit[i][j] += delta;
            }
        }
    }

    long long sum(int x, int y) {
        long long res = 0;
        for (int i = x+1; i > 0; i -= (i & -i)) {
            for (int j = y+1; j > 0; j -= (j & -j)) {
                res += bit[i][j];
            }
        }
        return res;
    }

    long long rangeSum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - (x1 > 0 ? sum(x1-1, y2) : 0)
                           - (y1 > 0 ? sum(x2, y1-1) : 0)
                           + (x1 > 0 && y1 > 0 ? sum(x1-1, y1-1) : 0);
    }
};

vector<int> matrixRangeSum(vector<vector<int>>& grid, vector<vector<int>>& queries) {
    int n = grid.size(), m = grid[0].size();
    Fenwick2D bit(n, m);

    // Build BIT
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bit.add(i, j, grid[i][j]);
        }
    }

    vector<int> result;
    for (auto &q : queries) {
        if (q[0] == 1) {
            // Query sum: q = {1, x1, y1, x2, y2}
            int x1 = q[1], y1 = q[2], x2 = q[3], y2 = q[4];
            result.push_back((int)bit.rangeSum(x1, y1, x2, y2));
        } else {
            // Update: q = {2, x, y, val}
            int x = q[1], y = q[2], val = q[3];
            int diff = val - grid[x][y];
            grid[x][y] = val;
            bit.add(x, y, diff);
        }
    }

    return result;
}
