// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem
// Detect a Cycle in a Linked List — HackerRank Problem

#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& out) {
    while (node) {
        out << node->data;
        node = node->next;
        if (node) out << sep;
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        delete temp;
    }
}

/*
 * Complete the 'has_cycle' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts SinglyLinkedListNode* head as parameter.
 *
 * Floyd’s Tortoise and Hare algorithm — O(n) time, O(1) space
 */

bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr) return false;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}
