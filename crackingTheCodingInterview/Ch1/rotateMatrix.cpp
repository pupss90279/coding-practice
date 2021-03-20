#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;


void printMatrix(vector<vector<int>> matrix) {

	for(int i=0; i<matrix.size(); ++i) {

		for(int j=0; j<matrix[0].size(); ++j) {

			cout<<matrix[i][j]<<" ";
		}

		cout<<endl;
	}
}

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix) {

	int n = matrix.size();
	vector<vector<int>> result(n, vector<int>(n));

	for(int i=0; i<n; ++i) {

		for(int j=0; j<n; ++j) {

			result[j][n-i-1] = matrix[i][j];
		}
	}

	return result;
}

void rotateMatrixInPlace(vector<vector<int>>& matrix) {

	int n = matrix.size();
	int numRotations = n/2;

	for(int i=0; i<numRotations; ++i) {

		for(int k=i; k<n-1-i; ++k) {

			int nextI = k;
			int nextJ = n-i-1;
			int nextVal = matrix[i][k];

			for(int j=0; j<4; ++j) {

				swap(matrix[nextI][nextJ], nextVal);
				swap(nextI, nextJ);
				nextJ = n - nextJ - 1;
			}
		}
	}
}

int main() {

	vector<vector<int>> test1 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> test2 {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };

    vector<vector<int>> test3 {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}, 
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    vector<vector<int>> rotated = rotateMatrix(test1);
	// printMatrix(rotated);

	rotateMatrixInPlace(test1);
	printMatrix(test1);

	rotateMatrixInPlace(test2);
	printMatrix(test2);

	rotateMatrixInPlace(test3);
	printMatrix(test3);
}