/// 2025-09-12-1401-TODO

/// Heap simplu
/// Implementează un min-heap de numere întregi cu:
///     insert(x)
///     extractMin()
/// Test: introdu valori {5, 2, 8, 1} și verifică dacă extragerile sunt {1,2,5,8}.

#include <iostream>
#include <string>

using namespace std;

void heapifyUp(int position, int *minheap) {
    if (position == 1 || position == 2) {
        return;
    } else {
        if (minheap[position] < minheap[(position) / 2]) {
            int temp = minheap[position - 1];
            minheap[position] = minheap[(position) / 2];
            minheap[(position) / 2] = temp;
            heapifyUp((position) / 2, minheap);
        }
    }
}

void insert(int value, int *minheap, int &size) {
    minheap[size++] = value;
    heapifyUp(size - 1, minheap);
}

void heapifyDown(int position, int *minheap, int &size) {
    if (size / 2 <= position) {
        return;
    } else if (minheap[2 * position + 1] < minheap[2 * position + 2]) {
        heapifyDown(2 * position + 1, minheap, size);
    } else {
        heapifyDown(2 * position + 2, minheap, size);
    }
}

int extractMin(int *minheap, int &size) {
    if (size <= 0) {
        cout << "Heap gol\n";
        return -1;
    } else {
        int root = minheap[0];
        cout << "Extrag: " << minheap[0] << "\n";
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

    cout << "\nMin heap:\n";
    for (int i = 0; i < size; i++) {
        cout << minheap[i] << " ";
    }

    cout << "\n\nExtragem fiecare minim:\n";
    for (int i = 0; i < size; i++) {
        cout << extractMin(minheap, size) << " ";
    }
    cout << "\n";

    return 0;
}
