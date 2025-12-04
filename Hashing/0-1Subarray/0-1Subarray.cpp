// Problem: 0-1 Subarray (SDA Homework 9, HackerRank)
// Difficulty: Medium
// Description: Given an array of 0s and 1s, find the length of the longest subarray
//              where the number of 0s and 1s is equal. We convert 0 -> -1 and 1 -> 1,
//              so the task becomes: "longest subarray with sum = 0".
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int subarrayPrefixSum(vector<int>& nums, int k)
{
    int sum = 0;
    int result = 0;
    unordered_map<int, int> prefSum_firstOccurance;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        sum += nums[i];

        if (sum == k)
            result = max(result, i + 1);

        if (prefSum_firstOccurance.find(sum - k) != prefSum_firstOccurance.end())
        {
            result = max(result, i - prefSum_firstOccurance[sum - k]);
        }
        else
        {
            prefSum_firstOccurance[sum - k] = i;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;

        if (curr == 0)
            nums[i] = -1;
        else
            nums[i] = 1;
    }

    cout << subarrayPrefixSum(nums, 0);
    return 0;
}
