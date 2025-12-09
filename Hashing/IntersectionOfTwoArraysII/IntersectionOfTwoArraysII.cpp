// LeetCode problem: 350. Intersection of Two Arrays II
// Difficulty: Easy
// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Description: Computes the intersection of two arrays, allowing duplicates.
//              Uses an unordered_map to count occurrences of elements in nums1,
//              then consumes matches while iterating through nums2.
// Time complexity: O(n + m)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> elems;
        vector<int> intersection;

        for (int i = 0; i < nums1.size(); i++)
        {
            elems[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (elems.count(nums2[i]))
            {
                intersection.push_back(nums2[i]);
                elems[nums2[i]]--;

                if (elems[nums2[i]] == 0)
                    elems.erase(nums2[i]);
            }
        }

        return intersection;
    }
};

int main()
{
    Solution sol;

    vector<int> a1 = { 1, 2, 2, 1 };
    vector<int> b1 = { 2, 2 };
    auto r1 = sol.intersect(a1, b1);
    cout << "Test 1 (expected [2,2]): ";
    for (int x : r1) cout << x << " ";
    cout << endl;

    vector<int> a2 = { 4,9,5 };
    vector<int> b2 = { 9,4,9,8,4 };
    auto r2 = sol.intersect(a2, b2);
    cout << "Test 2 (expected [4,9] or [9,4]): ";
    for (int x : r2) cout << x << " ";
    cout << endl;

    return 0;
}
