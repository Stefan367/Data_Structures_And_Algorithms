// LeetCode problem: 621. Task Scheduler
// Difficulty: Medium
// Link: https://leetcode.com/problems/task-scheduler/
// Description: Schedule tasks with a cooldown n using a max-heap of remaining frequencies.
// Time complexity: O(T log 26) ~= O(T)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int freq[26] = { 0 };
		for (char& ch : tasks)
		{
			freq[ch - 'A']++;
		}

		vector<int> store;
		priority_queue<int> pq;
		for (int i = 0; i < 26; i++)
		{
			if (freq[i] > 0)
				pq.push(freq[i]);
		}

		int time = 0, cycle;
		while (!pq.empty())
		{
			cycle = n + 1;
			int temp = 0;

			while (cycle-- && !pq.empty())
			{
				if (pq.top() > 1)
				{
					store.push_back(pq.top() - 1);
				}
				pq.pop();
				temp++;
			}

			for (int& x : store)
				pq.push(x);

			time += pq.empty() ? temp : n + 1;
			store.clear();
		}
		return time;
	}
};

int main()
{
	Solution sol;

	vector<char> t1 = { 'A','A','A','B','B','B' };
	cout << sol.leastInterval(t1, 2) << " (expected 8)" << endl;

	vector<char> t2 = { 'A','A','A','B','B','B' };
	cout << sol.leastInterval(t2, 0) << " (expected 6)" << endl;

	vector<char> t3 = { 'A','A','A','A','A','A','B','C','D','E','F','G' };
	cout << sol.leastInterval(t3, 2) << " (expected 16)" << endl;

	return 0;
}
