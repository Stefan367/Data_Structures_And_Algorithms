// Leetcode problem 328. Odd Even Linked List
// Link - https://leetcode.com/problems/odd-even-linked-list/
// Complexity: O(n) time, O(1) space

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode* iter = head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = nullptr;

        int counter = 1;

        while (iter != nullptr)
        {
            iter = iter->next;
            counter++;

            if (!iter) break;

            if (counter % 2 != 0)
            {
                odd->next = iter;
            }
            else
            {
                if (!evenHead)
                {
                    evenHead = iter;
                }
                else
                {
                    even->next = iter;
                }
            }
        }

        if (evenHead != nullptr)
        {
            odd->next = evenHead;
            even->next = nullptr;
        }

        return head;
    }
};