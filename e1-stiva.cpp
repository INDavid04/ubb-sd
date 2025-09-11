/// 2025-09-11-1149-1256
/// Observatie: Initial am implementat o coada, nu o stiva :)

// Stivă simplă
// Implementează o stivă de numere întregi cu operațiile:
// push(x)
// pop()
// top()
// empty()
// Test: introdu 5 valori, scoate-le pe toate și verifică ordinea (LIFO).

#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int val;
    Node *next;
};

void push(int x, Node *&head) {
    Node *temp = new Node;
    temp->val = x;
    temp->next = head;
    head = temp;
}

void pop(Node *&head) {
    if (!head) {
        cout << "Stiva goala\n";
    } else {
        Node *temp = head;
        cout << "pop: " << temp->val << "\n";
        head = head->next;
        delete temp;
    }
}

int top(Node *head) {
    if (!head) {
        throw underflow_error("Stiva goala\n");
    } else {
        return head->val;
    }
}

void clear(Node *&head) {
    while (head) {
        pop(head);
    }
}

bool empty(Node *head) {
    return (head == nullptr);
}

int main() {
    Node *head = nullptr;

    /// Push 
    cout << "Adauga cinci valori...\n";
    push(1, head);
    push(2, head);
    push(3, head);
    push(4, head);
    push(5, head);

    /// Pop 
    cout << "Scoate toate valorile...\n";
    pop(head); 
    pop(head); 
    pop(head); 
    pop(head); 
    pop(head);
    pop(head);

    /// Top
    cout << "Adauga doua valori...\n";
    push(1, head);
    cout << "top: " << top(head) << "\n";
    push(2, head);
    cout << "top: " << top(head) << "\n";
    
    /// Clear
    cout << "Scoate doua valori...\n";
    clear(head);

    /// Top (cazul stivei goale)
    try {
        cout << "Afiseaza varful stivei...\n";
        cout << "top: " << top(head) << "\n";
    } catch (const underflow_error &e) {
        cout << "Underflow error: " << e.what();
    }

    /// Empty
    if (empty(head)) {
        cout << "Stiva este goala\n";
    }

    return 0;
}
