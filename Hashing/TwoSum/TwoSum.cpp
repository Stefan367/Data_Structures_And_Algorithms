// LeetCode problem: 1. Two Sum
// Difficulty: Easy
// Link: https://leetcode.com/problems/two-sum/
// Description: Find indices of two numbers such that they add up to a target.
//              Uses a hash map to store previously seen values in O(n) time.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_num;
        vector<int> indexes;

        for (int i = 0; i < nums.size(); i++)
        {
            int needed = target - nums[i];
            auto iter = index_num.find(needed);

            if (iter != index_num.end())
            {
                indexes.push_back(iter->second);
                indexes.push_back(i);
                break;
            }
            index_num[nums[i]] = i;
        }

        return indexes;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = { 2, 7, 11, 15 };
    auto r1 = sol.twoSum(t1, 9);
    cout << "Test 1 (expected [0,1]): " << r1[0] << ", " << r1[1] << endl;

    vector<int> t2 = { 3, 2, 4 };
    auto r2 = sol.twoSum(t2, 6);
    cout << "Test 2 (expected [1,2]): " << r2[0] << ", " << r2[1] << endl;

    vector<int> t3 = { 3, 3 };
    auto r3 = sol.twoSum(t3, 6);
    cout << "Test 3 (expected [0,1]): " << r3[0] << ", " << r3[1] << endl;

    return 0;
}
