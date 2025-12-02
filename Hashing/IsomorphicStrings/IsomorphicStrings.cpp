// LeetCode problem: 205. Isomorphic Strings
// Difficulty: Easy
// Link: https://leetcode.com/problems/isomorphic-strings/
// Description: Check if two strings are isomorphic using bidirectional character mappings.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> sTot;
		unordered_map<char, char> tTos;

		for (int i = 0; i < s.size(); i++)
		{
			auto iter1 = sTot.find(s[i]);
			auto iter2 = tTos.find(t[i]);

			if (iter1 == sTot.end() && iter2 == tTos.end())
			{
				sTot[s[i]] = t[i];
				tTos[t[i]] = s[i];
				continue;
			}

			if (iter1 == sTot.end() || iter2 == tTos.end())
			{
				return false;
			}

			if (iter1->first != iter2->second)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution sol;
	cout << boolalpha << sol.isIsomorphic("egg", "add") << endl; // true
	cout << boolalpha << sol.isIsomorphic("foo", "bar") << endl; // false
	return 0;
}
