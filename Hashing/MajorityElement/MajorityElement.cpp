// LeetCode problem: 169. Majority Element
// Difficulty: Easy
// Link: https://leetcode.com/problems/majority-element/
// Description: Find the majority element (appearing more than n/2 times) using a hash map counting approach.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_counter;

        int size = nums.size();
        for (int& num : nums)
        {
            num_counter[num]++;

            if (num_counter[num] > size / 2)
            {
                return num;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> test1 = { 3, 2, 3 };
    cout << "Test 1 (expected 3): " << sol.majorityElement(test1) << endl;

    vector<int> test2 = { 2, 2, 1, 1, 1, 2, 2 };
    cout << "Test 2 (expected 2): " << sol.majorityElement(test2) << endl;

    return 0;
}
