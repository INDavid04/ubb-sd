#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};


// Adaugarea unui nod
void addFirst(node *&head, int x) {
    node *p = new node;
    p -> val = x;
    p -> next = head;
    head = p;
}

// Afisarea listei
void print(node *head) {
    node *p = head;
    while(p != NULL) {
        cout << p -> val << " ";
        p = p -> next;
    }
}

// Stergerea unui nod
node *deleteHead(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *p = head -> next;
    delete head;
    return p;
}

// Inserarea unui nod x pe o pozitie poz
void insertPoz(node *&head, int poz, int x) {
    if (poz == 0) {
        addFirst(head, x);
    }
    node *p = head;
    for (int i = 1; i <= poz - 1; i++) {
        p = p -> next;
    }
    node *q = new node;
    q -> val = x;
    q -> next - p -> next;
    p -> next = q;
}

int main() {
    node *head;
    head = NULL; // lista vida

    // Adaugam nodurile cu valorile 8, respectiv 3
    addFirst(head, 8);
    addFirst(head, 3);
    print(head);

    // Stergem primul nod
    head = deleteHead(head);
    print(head);
    // Stergem primul nod
    head = deleteHead(head);
    print(head);

    // Inseram un nod cu o anumita valoare pe o anumita pozitie
    addFirst(head, 15);
    print(head);
    insertPoz(head, 1, 5);
    insertPoz(head, 2, 8);
    print(head);

    return 0;
}
