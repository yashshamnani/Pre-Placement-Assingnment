// **Question 7**

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// **Example 1:**
// **Input:** n = 3
// **Output:** [[1,2,3],[8,9,4],[7,6,5]]


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n*n)
// Space Complexity : O(n*n)
vector<vector<int>> generateSpiralMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (num <= n * n) {
        // Traverse right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Traverse down
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Traverse left
        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = num++;
        }
        bottom--;

        // Traverse up
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = num++;
        }
        left++;
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    vector<vector<int>> spiralMatrix = generateSpiralMatrix(n);
    printMatrix(spiralMatrix);
    return 0;
}
