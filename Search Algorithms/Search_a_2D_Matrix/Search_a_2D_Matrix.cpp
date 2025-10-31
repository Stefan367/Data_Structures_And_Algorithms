// LeetCode #74: Search a 2D Matrix
// Approach: Binary Search per Row
// Time complexity: O(rows * log(cols))
// Space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int left = 0, right = matrix[0].size() - 1;
		int rows = matrix.size();

		for (size_t i = 0; i < rows; i++)
		{
			if (matrix[i][right] < target)
			{
				continue;
			}
			else
			{
				while (left <= right)
				{
					int mid = left + (right - left) / 2;

					if (matrix[i][mid] == target)
					{
						return true;
					}
					else if (matrix[i][mid] >= target)
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
				break;
			}
		}
		return false;
	}
};

int main() {
	Solution sol;

	vector<vector<int>> matrix1 = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	vector<vector<int>> matrix2 = {
		{1, 3}
	};

	cout << boolalpha;
	cout << sol.searchMatrix(matrix1, 3) << endl;  // Output: true
	cout << sol.searchMatrix(matrix1, 13) << endl; // Output: false
	cout << sol.searchMatrix(matrix2, 3) << endl;  // Output: true
	cout << sol.searchMatrix(matrix2, 2) << endl;  // Output: false
}
