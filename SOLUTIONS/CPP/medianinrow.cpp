#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double find_median(vector<vector<int>> matrix) {
	// Flatten the matrix into a 1D array
	vector<int> arr;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			arr.push_back(matrix[i][j]);
		}
	}

	// Sort the array
	sort(arr.begin(), arr.end());

	// Find the median element
	int mid = arr.size() / 2;
	double median;
	if (arr.size() % 2 == 0) {
		median = (arr[mid-1] + arr[mid]) / 2.0;
	} else {
		median = arr[mid];
	}

	return median;
}

int main() {
	// Example 1
	vector<vector<int>> matrix1 = {{1, 3, 5},
								{2, 6, 9},
								{3, 6, 9}};
	double median1 = find_median(matrix1);
	cout << "Median of matrix1: " << median1 << endl;

	// Example 2
	vector<vector<int>> matrix2 = {{1, 3, 4},
								{2, 5, 6},
								{7, 8, 9}};
	double median2 = find_median(matrix2);
	cout << "Median of matrix2: " << median2 << endl;

	return 0;
}
