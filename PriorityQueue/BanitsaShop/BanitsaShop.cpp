// HackerRank (SDA HW 8 2022) - Banitsa Shop
// Difficulty: Medium
// Link: https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/fullstack-developer
// Description: Simulate a single worker who always processes the currently available order with the smallest duration;
//              if tied, pick the one with the smallest input index. Output the processing order indices.
// Time complexity: O(n log n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Task
{
	int index;
	int start;
	int duration;

	Task(int index, int start, int duration) : index(index), start(start), duration(duration) {}
};

struct ComparatorByStart
{
	bool operator()(const Task& lhs, const Task& rhs)
	{
		return lhs.start > rhs.start;
	}
};

struct ComparatorByDuration
{
	bool operator()(const Task& lhs, const Task& rhs)
	{
		if (lhs.duration == rhs.duration)
		{
			return lhs.index > rhs.index;
		}
		return lhs.duration > rhs.duration;
	}
};

priority_queue<Task, vector<Task>, ComparatorByStart> pqToCome;
priority_queue<Task, vector<Task>, ComparatorByDuration> pqWaiting;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int st, dur;
		cin >> st >> dur;
		Task t(i, st, dur);
		pqToCome.push(t);
	}

	long long time = 0;

	bool firstPrinted = false;

	while (!pqToCome.empty() || !pqWaiting.empty())
	{
		while (!pqToCome.empty() && pqToCome.top().start <= time)
		{
			pqWaiting.push(pqToCome.top());
			pqToCome.pop();
		}

		if (pqWaiting.empty() && !pqToCome.empty())
		{
			time = pqToCome.top().start;
			continue;
		}

		Task newTask = pqWaiting.top();
		pqWaiting.pop();

		if (firstPrinted) cout << " ";
		cout << newTask.index;
		firstPrinted = true;

		time += newTask.duration;
	}

	return 0;
}
