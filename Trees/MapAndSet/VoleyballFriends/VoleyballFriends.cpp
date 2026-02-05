/**
 * HackerRank (SDA HW 8) - Volleyball Friends
 * Difficulty: Medium
 * Link: https://www.hackerrank.com/contests/sda-hw-8/challenges/volleyball-friends/problem
 *
 * Problem summary:
 * You have an initial team containing student m. Then you are given N directed conditions (a, b) in order.
 * Each condition means: student b will join the team only if student a is already in the team at the moment
 * this condition is processed. The checks are done strictly in input order; if a is not in the team at that
 * time, b does not join because of this condition. Output the final team size.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;


int main() {
	int m, n;
	std::cin >> m >> n;

	vector<pair<int, int>> friends(n);
	set<int> team;
	team.insert(m);

	for (int i = 0; i < n; i++)
	{
		std::cin >> friends[i].first >> friends[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		if (!team.count(friends[i].first))
			continue;

		team.insert(friends[i].second);
	}

	std::cout << team.size();
	return 0;
}
