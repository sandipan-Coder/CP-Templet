#include<bits/stdc++.h>
using namespace std;

//*************************** For 90 Degree Clockwise rotation **************************

//? --------------------- Transpose -> Reverse each row -------------------------------
void rotate90Clock(vector<vector<int>> &mat){ 
  	int n = mat.size();
  	
    // Perform Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
} 

// ******************* Rotate Matrix by 90 Degrees Counterclockwise **********************

//? ----------------------- Reverse each row -> Transpose -------------------------

void rotate90AntiClock(vector<vector<int>> &mat){ 
  	int n = mat.size();
  	
  	// Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

    // Performing Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

int main() {
    
    cout << "***************** ClockWise *****************************" << endl;
    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotate90Clock(mat1);
    for (auto& row : mat1) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    cout << "***************** Anti ClockWise *****************************" << endl;
    vector<vector<int>> mat2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotate90AntiClock(mat2);
    for (auto& row : mat2) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }
    
    return 0;
}