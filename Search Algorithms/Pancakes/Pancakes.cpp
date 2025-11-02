// Hackerrank Problem: Pancakes
// https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/problem

// Task:
// Given K cooks and N pancakes to make, each cook i needs Ti minutes per pancake.
// All cooks work in parallel. Find the minimal time needed to finish all N pancakes.
//
// Approach: Binary Search on Answer
// --------------------------------
// If we fix a certain time "t", we can calculate how many pancakes total
// all cooks can make within that time.
// We then binary search the minimal "t" for which total pancakes >= N.
//
// Time complexity: O(K * log(Tmax * N))
// Space complexity: O(1)

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool check(const vector<int>& prepTime, long long allPancakes, long long targetTime)
{
    long long pancakes = 0;
    for (int currCookTime : prepTime)
    {
        pancakes += targetTime / currCookTime;
    }
    return pancakes >= allPancakes;
}

int main() {
    long long n;
    int k;
    cin >> n >> k;

    vector<int> prepTime(k);
    int minTime = INT_MAX, maxTime = INT_MIN;

    for (int i = 0; i < k; i++) {
        cin >> prepTime[i];

        minTime = min(minTime, prepTime[i]);
        maxTime = max(maxTime, prepTime[i]);
    }

    long long left = (n / k) * minTime;
    long long right = (n / k + 1) * maxTime;
    long long ans = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (check(prepTime, n, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
