// https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3729/problem
// Replace X with X ones - SDA Test 2022/2023
// Complexity: O(N + X) time, O(X) space per replacement

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int value, Node* next = nullptr) : value(value), next(next) {};
};

struct SinglyLinkedList
{
    Node* head, * tail;
    int size;

    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {};

    void addAtHead(int X);
    void addAtTail(int X);
    void add(int X, int pos);
    void remove(int pos);
    void replace(int X);
    friend ostream& operator<<(ostream& os, const SinglyLinkedList& list);
};

int main()
{
    size_t N, Q;
    cin >> N;

    int el(0), pos(0);

    for (size_t i = 0; i < N; i++)
    {
        SinglyLinkedList list;
        cin >> Q;
        cin.ignore();
        for (size_t j = 0; j < Q; j++)
        {
            string line;
            getline(cin, line);
            istringstream istr(line);

            string command;
            istr >> command;

            if (command == "add")
            {
                istr >> el >> pos;
                list.add(el, pos);
            }
            else if (command == "print")
            {
                cout << list;
            }
            else if (command == "remove")
            {
                istr >> pos;
                list.remove(pos);
            }
            else if (command == "replace")
            {
                istr >> el;
                list.replace(el);
                cout << list << "\n";
            }
            else
            {
                int count(0);
                while (istr)
                {
                    istr >> command;
                    count++;
                }
                i += count - 1;
            }
        }
    }
    return 0;
}

ostream& operator<<(ostream& os, const SinglyLinkedList& list)
{
    Node* traverse = list.head;
    while (traverse != nullptr)
    {
        os << traverse->value << '#';
        traverse = traverse->next;
    }
    return os;
}

void SinglyLinkedList::addAtHead(int X)
{
    Node* newNode = new Node(X);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        Node* temp = head;
        newNode->next = temp;
        head = newNode;
    }
    size++;
}

void SinglyLinkedList::addAtTail(int X)
{
    Node* newNode = new Node(X);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SinglyLinkedList::add(int X, int pos)
{
    if (pos == 0)
    {
        addAtHead(X);
    }
    else if (pos < 0 || pos > size)
    {
        addAtTail(X);
    }
    else if (pos == size)
    {
        addAtTail(X);
    }
    else
    {
        Node* newNode = new Node(X);
        Node* traverse = head;
        for (int i = 1; i < pos; i++)
        {
            traverse = traverse->next;
        }
        Node* temp = traverse->next;
        traverse->next = newNode;
        newNode->next = temp;
        size++;
    }
}

void SinglyLinkedList::remove(int pos)
{
    if (pos < 0 || pos >= (int)size)
    {
        cout << "remove_failed";
    }
    else if (pos == 0)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
        if (head == nullptr) tail = nullptr;
        size--;
    }
    else
    {
        Node* traverse = head;
        for (int i = 0; i < pos - 1; i++)
        {
            traverse = traverse->next;
        }
        Node* temp = traverse->next;
        traverse->next = temp->next;
        if (temp->next == nullptr)
        {
            tail = traverse;
        }
        delete temp;
        size--;
    }
}

void SinglyLinkedList::replace(int X)
{
    if (head == nullptr) return;
    if (X == 1) return;

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr)
    {
        if (curr->value == X)
        {
            Node* beg = new Node(1);
            Node* end = beg;

            for (int i = 0; i < X - 1; ++i)
            {
                end->next = new Node(1);
                end = end->next;
            }

            if (prev != nullptr)
            {
                prev->next = beg;
            }
            else
            {
                head = beg;
            }

            if (curr->next != nullptr)
            {
                end->next = curr->next;
            }
            else
            {
                tail = end;
                end->next = nullptr;
            }

            delete curr;
            curr = end;
            size += X - 1;
        }

        prev = curr;
        curr = curr->next;
    }
}