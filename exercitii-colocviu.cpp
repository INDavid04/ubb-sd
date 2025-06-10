/////////////////////////////
// LISTE SIMPLU ÎNLĂNȚUITE //
/////////////////////////////

#include <iostream>
using namespace std;

/// `Node` folosit la exercitiile 1, 2, 5
struct Node {
    int val;
    Node* next;
};

/// 1. Să se insereze un element cu valoarea x la sfârșitul unei liste simplu înlănțuite.

void insert_end(Node*& head, int x) {
    Node* new_node = new Node{x, nullptr};
    if (!head) {
        head = new_node;
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = new_node;
}

void print_list(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// int main () {
//     Node* cap = nullptr;
//     print_list(cap);
//     insert_end(cap, 1);
//     print_list(cap);
//     insert_end(cap, 2);
//     print_list(cap);
//     insert_end(cap, 3);
//     print_list(cap);
//     insert_end(cap, 4);
//     print_list(cap);
//     return 0;
// }

/// 2. Să se insereze un element cu valoarea x pe poziția k într-o listă simplu înlănțuită. Pozițiile sunt indexate de la 0. Dacă k este 0, inserarea se face la început.

void insert_value_on_position(Node*& head, int value, int position) {
    Node* new_node = new Node {value, nullptr};
    if (!head) {
        if (position == 0) {
            head = new_node;
            return;
        } else {
            cout << "Nu pot adauga pe aceasta pozitie\n";
            return;
        }
    }
    Node* p = head;
    position--;
    while(position) {
        p = p->next;
        position--;
    }
    cout << "DEGUG: postion = " << position << "\n";
    if (position) {
        cout << "Nu pot adauga pe aceasta pozitie\n";
    } else if (p->next == nullptr) {
        p->next = new_node;
    } else {
        Node* copie = p->next;
        p->next = new_node;
        new_node->next = copie;
    }
}

void print_list_2(Node* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// int main () {
//     Node* head = nullptr;
//     insert_value_on_position(head, 1, 0);
//     print_list_2(head);
//     insert_value_on_position(head, 8, 1);
//     print_list_2(head);
//     insert_value_on_position(head, 7, 1);
//     print_list_2(head);
//     insert_value_on_position(head, 100, 30);
//     print_list_2(head);
//     return 0;
// }

//////////////
// HEAP MAX //
//////////////

/// 3. Să se implementeze o coadă de priorități (heap maxim) care permite inserarea unui număr și extragerea maximului.

const int MAXN = 100000;
int heap[MAXN], sz;

void heap_push(int x) {
    heap[++sz] = x;
    int i = sz;
    while (i > 1 && heap[i] > heap[i/2]) {
        swap(heap[i], heap[i/2]);
        i /= 2;
    }
    cout << "After heap_push: ";
    for (int i = 1; i <= sz; i++) {
        cout << heap[i] << " ";
    }
    cout << "\n";
}

int heap_pop() {
    int max_val = heap[1];
    heap[1] = heap[sz--];
    int i = 1;
    while (2 * i <= sz) {
        int j = 2 * i;
        if (j + 1 <= sz && heap[j + 1] > heap[j]) j++;
        if (heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
        } else break;
    }
    cout << "After heap_pop: ";
    for (int i = 1; i <= sz; i++) {
        cout << heap[i] << " ";
    }
    cout << "\n";
    return max_val;
}

// int main () {
//     heap_push(18);
//     heap_push(7);
//     heap_push(15);
//     heap_push(50);
//     heap_push(30);
//     heap_push(100);
//     heap_push(20);
//     heap_push(70);
//     heap_push(9);
//     heap_push(45);
//     heap_push(58);
//     cout << "Maxim: " << heap_pop() << "\n";
//     return 0;
// }

/// 4. Să se modifice implementarea de mai sus pentru a construi un heap MINIM.

int n, min_heap[100];

void min_heap_push(int value) {
    min_heap[++n] = value;
    int i = n;
    while (i > 1 && min_heap[i] < min_heap[i/2]) {
        int aux = min_heap[i];
        min_heap[i] = min_heap[i/2];
        min_heap[i/2] = aux;
        i /= 2;
    }
    cout << "After min heap push: ";
    for (int i = 1; i <= n; i++) {
        cout << min_heap[i] << " ";
    }
    cout << "\n";
}

int min_heap_pop() {
    int min_val = min_heap[1]; /// retinem valoarea radacinii in min_val
    min_heap[1] = min_heap[n--]; /// inlocuim valoarea radacinii cu valoarea ultimului nod adaugat
    int i = 1;
    while (2 * i <= n) {
        cout << "DEBUG: min heap: ";
        for (int k = 1; k <= n; k++) {
            cout << min_heap[k] << " ";
        }
        cout << "\n";
        int j = 2 * i;
        if (j + 1 <= n && min_heap[j + 1] < min_heap[j]) {
            j++;
        }
        if (min_heap[i] > min_heap[j]) {
            swap(min_heap[i], min_heap[j]);
            i = j;
        } else {
            break;
        }
    }
    cout << "After min heap pop: ";
    for (int i = 1; i <= n; i++) {
        cout << min_heap[i] << " ";
    }
    cout << "\n";
    return min_val;
}

// int main () {
//     min_heap_push(18);
//     min_heap_push(7);
//     min_heap_push(15);
//     min_heap_push(50);
//     min_heap_push(30);
//     min_heap_push(100);
//     min_heap_push(20);
//     min_heap_push(70);
//     min_heap_push(9);
//     min_heap_push(45);
//     min_heap_push(58);
//     cout << "Minimum: " << min_heap_pop() << "\n";
//     return 0;
// }

/// 5. Să se insereze un element cu valoarea x la sfârșitul unei liste circular simplu înlănțuite.

void insert_circular(Node*& tail, int x) {
    Node* new_node = new Node{x, nullptr};
    if (!tail) {
        new_node->next = new_node;
        tail = new_node;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }
}

void print_circular(Node* tail) {
    if (!tail) return;
    Node* p = tail->next;
    do {
        cout << p->val << " ";
        p = p->next;
    } while (p != tail->next);
    cout << endl;
}

// int main () {
//     Node* tail = nullptr;
//     print_circular(tail);
//     insert_circular(tail, 19);
//     print_circular(tail);
//     insert_circular(tail, 29);
//     print_circular(tail);
//     return 0;
// }

/// 6. Să se șteargă primul nod cu valoarea x dintr-o listă circular simplu înlănțuită.

void insert_circular_list(Node*& tail, int value) {
    Node* new_node = new Node {value, nullptr};
    if (!tail) {
        new_node->next = new_node;
        tail = new_node;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }
}

void print_circular_list(Node* tail) {
    if (!tail) {
        cout << "The list is empty!\n";
    } else {
        cout << "Circular list: ";
        Node* p = tail->next;
        do {
            cout << p->val << " ";
            p = p->next;
        } while (p != tail->next);
        cout << "\n";
    }
}

void remove_from_circular_list(Node* tail, int value) {
    if (!tail) {
        cout << "The list is empty! I can not remove anything!\n";
    } else {
        Node* p = tail->next;
        do {
            if (p->next->val == value) {
                cout << "Remove " << value << "\n";
                p->next = p->next->next;
                return;
            }
            p = p->next;
        } while (p != tail->next);
        cout << "Value " << value << " not found\n";
    }
}

// int main () {
//     Node* tail = nullptr;
//     print_circular_list(tail);
//     remove_from_circular_list(tail, 1001);
//     insert_circular_list(tail, 8);
//     insert_circular_list(tail, 10);
//     insert_circular_list(tail, 34);
//     print_circular_list(tail);
//     remove_from_circular_list(tail, 10);
//     print_circular_list(tail);
//     remove_from_circular_list(tail, 100);
//     print_circular_list(tail);
//     remove_from_circular_list(tail, 10);
//     print_circular_list(tail);
//     return 0;
// }

///////////////////
// STACK (STIVĂ) //
///////////////////

//// 7. Implementați o stivă care suportă operațiile push și pop.

struct StackNode {
    int val;
    StackNode* next;
};

void push(StackNode*& top, int x) {
    StackNode* new_node = new StackNode{x, top};
    top = new_node;
}

int pop(StackNode*& top) {
    StackNode* initialTop;
    int top_value;
    if (!top) {
        cout << "Empty stack\n";
        return -1;
    } else {
        initialTop = top->next;
        top_value = top->val;
        top = top->next;
    }
    top = initialTop;
    return top_value;
}

void printStack(StackNode*& top) {
    StackNode* initialTop;
    if (!top) {
        cout << "Empty stack\n";
    } else {
        initialTop = top;
        cout << "Stack: ";
        while (top) {
            cout << top->val << " ";
            top = top->next;
        }
        cout << "\n";
    }
    top = initialTop;
}

int main () {
    StackNode* top = nullptr;
    printStack(top);
    push(top, 10);
    push(top, 20);
    push(top, 100);
    printStack(top);
    printStack(top);
    cout << "Pop: " << pop(top) << "\n";
    printStack(top);
    return 0;
}

/// 8. Verifică dacă un șir de paranteze este corect folosind o stivă proprie (ex: "(()())" este valid).

struct stackNodeP {
    char value;
    stackNodeP* next;
};

void pushP(stackNodeP*& top, char value) {
    stackNodeP* new_node = new stackNodeP{value, top};
    top = new_node;
}

char popP(stackNodeP*& top) {
    if (!top) return 'e'; /// e comes from empty
    char value = top->value;
    stackNodeP* temporary = top;
    top = top->next;
    delete temporary;
    return value; 
}

void printStackP(stackNodeP*& top) {
    if (!top) {
        cout << "Empty stack\n";
    } else {
        cout << "Stack: ";
        while (top) {
            cout << top->value << " ";
            top = top->next;
        }
        cout << "\n";
    }
}

// int main () {
//     return 0;
// }

///////////////////
// ARBORI BINARI //
///////////////////

/// 9. Să se insereze un nod într-un arbore binar de căutare (BST).

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

TreeNode* insert_bst(TreeNode* root, int x) {
    if (!root) return new TreeNode{x, nullptr, nullptr};
    if (x < root->val)
        root->left = insert_bst(root->left, x);
    else
        root->right = insert_bst(root->right, x);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/// 10. Scrie o funcție care caută o valoare x într-un arbore binar de căutare (BST). Returnează true/false.
