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

	cout<<endl;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> matrix) {

	vector<vector<int>> zeroedMatrix = matrix;
	vector<bool> rowZero(zeroedMatrix.size(), false);
	vector<bool> colZero(zeroedMatrix[0].size(), false);

	for(int i=0; i<matrix.size(); ++i) {

		for(int j=0; j<matrix[0].size(); ++j) {

			if(matrix[i][j] == 0) {

				rowZero[i] = true;
				colZero[j] = true;
			}
		}
	}


	for(int i=0; i<matrix.size(); ++i) {

		for(int j=0; j<matrix[0].size(); ++j) {

			if(rowZero[i] || colZero[j]) zeroedMatrix[i][j] = 0;
		}
	}

	return zeroedMatrix;
}

vector<vector<int>> zeroMatrixNoAdditionalSpace(vector<vector<int>> matrix) {

	bool zeroFirstRow = false;
	bool zeroFirstCol = false;

	for(int i=0; i<matrix.size(); ++i) {

		for(int j=0; j<matrix[0].size(); ++j) {

			if(matrix[i][j] == 0) {

				if(i != 0 && j != 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				} else {
					
					if(i == 0) zeroFirstRow = true;
					if(j == 0) zeroFirstCol = true;
				}
			}
		}
	}


	for(int i=1; i<matrix.size(); ++i) {

		if(matrix[i][0] == 0) {

			for(int j=1; j<matrix[0].size(); ++j) {

				matrix[i][j] = 0;
			}
		}
	}


	for(int j=1; j<matrix[0].size(); ++j) {

		if(matrix[0][j] == 0) {

			for(int i=1; i<matrix.size(); ++i) {
				matrix[i][j] = 0;
			}
		}
	}

	if(zeroFirstRow) {

		for(int j=0; j<matrix[0].size(); ++j) {

			matrix[0][j] = 0;
		}
	}

	if(zeroFirstCol) {

		for(int i=0; i<matrix.size(); ++i) {
			matrix[i][0] = 0;
		}
	}

	return matrix;
}

int main() {

	vector<vector<int>> test1 {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 0}
    };

    // printMatrix(zeroMatrix(test1));
    printMatrix(zeroMatrixNoAdditionalSpace(test1));

    vector<vector<int>> test2 {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    // printMatrix(zeroMatrix(test2));
    printMatrix(zeroMatrixNoAdditionalSpace(test2));
} 