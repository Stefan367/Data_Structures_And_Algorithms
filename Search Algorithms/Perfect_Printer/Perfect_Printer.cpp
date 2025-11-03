// Hackerrank Problem: Perfect Printer
// https://www.hackerrank.com/contests/sda-homework-3/challenges/challenge-2674/problem
//
// Problem from the SDA Homework 3 (FMI).
// Solved using the Binary Search on Answer approach.
// Difficulty: Medium
//
// Tags: #binarysearch #searchonanswer #hackerrank #sda #fmi

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool check(const vector<int>& printTimes, long long targetCount, long long targetTime)
{
    long long papers = 0;
    for (auto& currTime : printTimes)
    {
        papers += targetTime / currTime;
    }
    return papers >= targetCount;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<int> printTimes(k);

    long long minTime = LLONG_MAX, maxTime = LLONG_MIN;
    for (long long i = 0; i < k; ++i)
    {
        cin >> printTimes[i];

        minTime = min(minTime, (long long)printTimes[i]);
        maxTime = max(maxTime, (long long)printTimes[i]);
    }

    long long left = (n / k) * minTime;
    long long right = (n / k + 1) * maxTime;
    long long answer = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (check(printTimes, n, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer;
    return 0;
}
