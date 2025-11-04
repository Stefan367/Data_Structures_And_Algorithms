// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Intersection of Two Linked Lists — LeetCode Problem

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        int lenA = 0, lenB = 0;

        ListNode* currA = headA;
        while (currA != nullptr)
        {
            currA = currA->next;
            lenA++;
        }

        ListNode* currB = headB;
        while (currB != nullptr)
        {
            currB = currB->next;
            lenB++;
        }

        int elementsToSkip = abs(lenA - lenB);
        currA = headA;
        currB = headB;

        if (lenA > lenB)
        {
            for (int i = 0; i < elementsToSkip; ++i)
            {
                currA = currA->next;
            }
        }
        else
        {
            for (int i = 0; i < elementsToSkip; ++i)
            {
                currB = currB->next;
            }
        }

        while (currA != nullptr && currB != nullptr)
        {
            if (currA == currB) return currA;

            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};