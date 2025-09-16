/// 2025-09-16-1203-1226

/// Cele mai apropiate 2 valori de 10
/// Vector: {3, 7, 11, 15, 9}
/// Output: {9, 11} (în orice ordine).
/// Hint: folosește heap de dimensiune k=2.
/// Heap-ul ar arata cam asa, de fapt nu e un min heap ci mai degraba un binary search tree:
/// (ne complicam prea mult cu un bst)
///     10
///    /  \
///   9    11
///  / \    \
/// 3   7    15

#include <iostream>

using namespace std;

int main() {
    int v[5] = {3, 7, 11, 15, 9};
    int celeMaiApropiateDouaValoriDeZece[2] = {3, 7};
    for (int i = 2; i < 5; i++) {
        if (abs(10 - v[i]) < abs(10 - celeMaiApropiateDouaValoriDeZece[0])) {
            celeMaiApropiateDouaValoriDeZece[0] = v[i];
        } else if (abs(10 - v[i]) < abs(10 - celeMaiApropiateDouaValoriDeZece[1])) {
            celeMaiApropiateDouaValoriDeZece[1] = v[i];
        }
    }

    cout << celeMaiApropiateDouaValoriDeZece[0] << " " << celeMaiApropiateDouaValoriDeZece[1] << "\n";

    return 0;
}
