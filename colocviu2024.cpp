// Colocviu Structuri de date
// 18 Iunie 2024
// Rezolvat pe 9 Iunie 2025, 16:15 - 17:15

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

////////////////
// Problema 1 //
////////////////

struct StackNode {
    string dir;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;

public:
    Stack() { top = nullptr; }

    void push(const string& x) {
        StackNode* node = new StackNode;
        node->dir = x;
        node->next = top;
        top = node;
    }

    void pop() {
        if (top != nullptr) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek() {
        return top ? top->dir : "/";
    }

    bool empty() {
        return top == nullptr;
    }
};

void solve_problem_1() {
    int n;
    cin >> n;
    Stack s;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "cd") {
            string x;
            cin >> x;
            if (x == "..") {
                if (!s.empty()) s.pop();
            } else {
                s.push(x);
            }
        } else if (cmd == "pwd") {
            cout << s.peek() << '\n';
        }
    }
}

////////////////
// Problema 2 //
////////////////

struct HeapNode {
    int val;
    int dist;
};

class MaxHeap {
private:
    HeapNode* arr;
    int size;
    int capacity;

    void swap(HeapNode& a, HeapNode& b) {
        HeapNode temp = a;
        a = b;
        b = temp;
    }

    void heapify_up(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (compare(arr[idx], arr[parent])) {
                swap(arr[idx], arr[parent]);
                idx = parent;
            } else break;
        }
    }

    void heapify_down(int idx) {
        while (2 * idx + 1 < size) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;
            if (left < size && compare(arr[left], arr[largest]))
                largest = left;
            if (right < size && compare(arr[right], arr[largest]))
                largest = right;
            if (largest != idx) {
                swap(arr[idx], arr[largest]);
                idx = largest;
            } else break;
        }
    }

    bool compare(HeapNode a, HeapNode b) {
        if (a.dist != b.dist) return a.dist > b.dist;
        return a.val > b.val;
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        arr = new HeapNode[capacity];
        size = 0;
    }

    void push(int val, int dist) {
        if (size < capacity) {
            arr[size++] = {val, dist};
            heapify_up(size - 1);
        } else if (compare({val, dist}, arr[0])) {
            arr[0] = {val, dist};
            heapify_down(0);
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i].val << " ";
        }
        cout << "\n";
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

void solve_problem_2() {
    int n, k, x;
    cin >> n >> k >> x;
    MaxHeap heap(k);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        int dist = abs(v - x);
        heap.push(v, dist);
    }
    heap.print();
}

int main() {
    solve_problem_1();
    // solve_prosblem_2();
    return 0;
}
