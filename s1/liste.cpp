#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

void addFirst(node *&head, int x) {
    node *p = new node;
    p -> val = x;
    p -> next = head;
    head = p;
}

void print(node *head) {
    node *p = head;
    while(p != NULL) {
        cout << p -> val << " ";
        p = p -> next;
    }
}

int main() {
    node *head;
    head = NULL; // lista vida
    addFirst(head, 8);
    addFirst(head, 3);
    print(head);

    return 0;
}
