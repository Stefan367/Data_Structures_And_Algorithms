// HackerRank - Gym Benches (Maximum Overlap of Intervals)
// Difficulty: Medium
// Link: https://www.hackerrank.com/contests/sda-test4-2022-2023-343rrsdfs/challenges/challenge-3768/problem
// Description: Given N training time intervals [Xi, Yi), find the maximum number of people training at the same time.
// Time complexity: O(n log n)
// Space complexity: O(n)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Time
{
    long beg;
    long end;

    Time() {}

    Time(long beg, long end) : beg(beg), end(end) {}
};

bool operator<(const Time& t1, const Time& t2)
{
    if (t1.end == t2.end)
    {
        return t1.beg < t2.beg;
    }

    return t1.end > t2.end;
}

bool compare(const Time& t1, const Time& t2)
{
    return t1.beg < t2.beg;
}

int main() {
    long n;
    std::cin >> n;

    vector<Time> times(n);
    for (long i = 0; i < n; i++)
    {
        long beg, end;
        std::cin >> beg >> end;
        Time t(beg, end);
        times[i] = t;
    }

    sort(times.begin(), times.end(), compare);
    priority_queue<Time> pq;
    unsigned long maxSize = 0;

    for (long i = 0; i < n; i++)
    {
        Time time = times[i];

        if (time.beg == time.end)
            continue;

        pq.push(time);

        while (!pq.empty() && pq.top().end <= time.beg)
        {
            pq.pop();
        }

        if (maxSize < pq.size())
        {
            maxSize = pq.size();
        }
    }

    std::cout << maxSize;
    return 0;
}