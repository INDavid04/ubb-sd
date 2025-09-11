/// 2025-09-11-1149-TODO

// Stivă simplă
// Implementează o stivă de numere întregi cu operațiile:
// push(x)
// pop()
// top()
// empty()
// Test: introdu 5 valori, scoate-le pe toate și verifică ordinea (LIFO).

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
};

void push(int x, Node &head) {
    Node *temp;
    temp->val = x;

    if (!head) {
        head = temp; 
    } else {
        head->next = temp;
    }
}

void pop(Node &head) {
    Node temp = *top(head);
    cout << "pop: " << temp->next->val << "\n";
    temp->next = nullptr;
}

Node *top(Node &head) {
    Node temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    return *temp;
}

int main() {
    Node head = nullptr;

    /// Push ("introdu cinci valori")
    push(1, head);
    push(2, head);
    push(3, head);
    push(4, head);
    push(5, head);

    /// Pop ("scoatele pe toate")
    pop(head); 
    pop(head); 
    pop(head); 
    pop(head); 
    pop(head);

    return 0;
}
