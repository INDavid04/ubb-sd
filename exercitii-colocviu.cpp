/////////////////////////////
// LISTE SIMPLU ÎNLĂNȚUITE //
/////////////////////////////

#include <iostream>
using namespace std;

/// 1. Să se insereze un element cu valoarea x la sfârșitul unei liste simplu înlănțuite.

struct Node {
    int val;
    Node* next;
};

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

/// 2. Să se insereze un element cu valoarea x pe poziția k într-o listă simplu înlănțuită. Pozițiile sunt indexate de la 0. Dacă k este 0, inserarea se face la început.

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
    return max_val;
}

/// 4. Să se modifice implementarea de mai sus pentru a construi un heap MINIM.



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

/// 6. Să se șteargă primul nod cu valoarea x dintr-o listă circular simplu înlănțuită.

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
    if (!top) return -1; // sau arunca exceptie
    int val = top->val;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return val;
}

/// 8. Verifică dacă un șir de paranteze este corect folosind o stivă proprie (ex: "(()())" este valid).

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
