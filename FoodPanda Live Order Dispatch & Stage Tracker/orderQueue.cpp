#include <iostream>
using namespace std;

struct Node {
    int stationIndex;
    Node* next;
};

struct OrderQueue {
    Node* front = NULL;
    Node* end = NULL;

    void push(int index) {
        Node* tmp = new Node{index, NULL};
        if (front == NULL) {
            front = end = tmp;
        } else {
            end->next = tmp;
            end = tmp;
        }
    }

    int pop() {
        if (front == NULL) return -1;
        Node* tmp = front;
        int val = front->stationIndex;
        front = front->next;
        if (front == NULL) end = NULL;
        delete tmp;
        return val;
    }

    bool isEmpty() {
        return front == NULL;
    }
};
