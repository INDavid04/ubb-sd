/// 2025-09-12-1401

/// Heap simplu
/// Implementează un min-heap de numere întregi cu:
///     insert(x)
///     extractMin()
/// Test: introdu valori {5, 2, 8, 1} și verifică dacă extragerile sunt {1,2,5,8}.

#include <iostream>
#include <string>

using namespace std;

void heapifyUp(int position, int *minheap) {
    if (position == 0) {
        return;
    }
    if (minheap[position] < minheap[(position - 1)/2]) {
        swap(minheap[position], minheap[(position - 1)/2]);
        heapifyUp((position - 1)/2, minheap);
    }
}

void heapifyDown(int position, int *minheap, int &size) {
    int left = 2 * position + 1;
    int right = 2 * position + 2;
    int smallest = position;

    if (left < size && minheap[left] < minheap[smallest]) {
        smallest = left;
    }
    if (right < size && minheap[right] < minheap[smallest]) {
        smallest = right;
    }
    if (smallest != position) {
        swap(minheap[position], minheap[smallest]);
        heapifyDown(smallest, minheap, size);
    }
}

void insert(int value, int *minheap, int &size) {
    minheap[size++] = value;
    heapifyUp(size - 1, minheap);
}

int extractMin(int *minheap, int &size) {
    if (size <= 0) {
        cout << "Heap gol\n";
        return -1;
    } else {
        int root = minheap[0];
        minheap[0] = minheap[size - 1];
        size--;
        heapifyDown(0, minheap, size);
        return root;
    }
}

int main() {
    int x, minheap[100], size = 0;
    string raspuns;

    do {
        cout << "x: ";
        cin >> x;
        cin.get();
        insert(x, minheap, size);
        cout << "Mai adaugi (da/nu): ";
        getline(cin, raspuns);
    } while (raspuns == "da");

    cout << "\nMin heap array:\n";
    for (int i = 0; i < size; i++) {
        cout << minheap[i] << " ";
    }

    cout << "\n\nExtragem fiecare minim:\n";
    while (size) {
        cout << extractMin(minheap, size) << " ";
    }
    cout << "\n";

    return 0;
}
