// Irimia David - Grupa 141 - Test de laborator

///////////
/// S-1 ///
///////////

// #include <iostream>

// using namespace std;

// struct ABC {
//     int info;
//     ABC* left;
//     ABC* right;
// };

// int n, j, arbore[100];

// void inserare(ABC* &root, int val) {
//     if(root == NULL) {
//         root = new ABC;
//         root -> info = val;
//         root -> left = NULL;
//         root -> right = NULL;
//     } else {
//         if(val < root -> info) {
//             inserare(root -> left, val);
//         } else {
//             inserare(root -> right, val);
//         }
//     }
// }

// int test_case(ABC* root);

// int main() {
//     cin >> n;
//     ABC* root = NULL;
//     for(int i = 1; i <= n; i++) {
//         int x;
//         cin >> x;
//         arbore[j++] = x;
//         inserare(root, x);
//     }
//     int sol = test_case(root);
//     cout << sol;
//     return 0;
// }

// // MODIFY START

// int test_case(ABC* root) {
//     /// Primește un pointer catre radacina arborelui si returneaza diferenta maxima intre doua noduri din arbore.
//     /// in: 
//     /// 5
//     /// 12 13 1 17 15
//     /// out:
//     /// 16
//     /// Explicatie: Diferenta maxima intre doua noduri din arbore este diferenta dintre maxim si minim, in acest caz avem 17 - 1 = 16. Astfel ca problema se reduce in a gasi maximul si minimul
//     /// Arborele ar trebui sa arate in modul urmator:
//     /*
//                             12
//                             /\
//                            1  13
//                               /\
//                              N 17
//                                /\
//                              15  N
//         Unde N = NULL
//     */

//     /// Gasirea minimului si a maximului (Varianta primitiva)
//     int minim = arbore[0];
//     int maxim = arbore[0];
//     for (j = 1; j < n; j++) {
//         if (arbore[j] < minim) {
//             minim = arbore[j];
//         }
//         if (arbore[j] > maxim) {
//             maxim = arbore[j];
//         }
//     }
//     return maxim - minim; /// ar trebui sa returneze 16
// }

/////////
// S-2 //
/////////

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/// in: 4 1 5 2 5
/// out : 24
/// Explicatie: 
/// 1. Din 1 5 2 5, alegem 5 5 (10), obtinem 1 2 10, alegem 2 10 (12), obtinem 1 12, alegem 1 12 (13) obtinem 13, in total: 10 + 12 + 13 = 35
/// 2. Din 1 5 2 5, alegem 1 2 (3) si 5 5 (10), obtinem 3 10, dupa alegem 3 10 (13), in total: 3 + 10 + 13 = 26
/// 3. Din 1 5 2 5, alegem  1 5 (6) si 5 2 (7), obtinem 6 7, dupa avem (13) in total: 6 + 7 + 13 = 26
/// 4. Se ridica intrebarea, de unde acel 24?

int main() {
    unsigned int n, rezultat = 0;
    cin >> n;
    unsigned d[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n/2; i++) {
        for (int j = n/2 + 1; j < n; j++) {
            rezultat += d[i] + d[j];
        }
    }
    cout << rezultat;

    return 0;
}
