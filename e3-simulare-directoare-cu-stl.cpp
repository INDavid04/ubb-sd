/// 2025-09-15-1807-TODO

/// Incercarea mea

/// Simulare directoare (stack)
/// Input:
///     5
///     cd abc
///     cd def
///     pwd
///     cd ..
///     pwd
/// Output așteptat:
///     def
///     abc
/// Hint: folosește stiva de șiruri, nu de numere.

#include <iostream>
#include <string>

using namespace std;

void push(vector<string> &stack, const string &comanda) {
    char director[100];
    int k = 0;
    for (int i = 3; comanda[i] != "\0"; i++) {
        directoare[k++] = comanda[i];
    }
    stack.push_front(director);
}

const string top(vector<string> &stack) {
    return stack[0];
}

int main() {
    int numarComenzi;
    string comanda;
    vector<string> stack;
    vector<string> output;

    cin >> numarComenzi;
    cin.get();

    while(numarComenzi--) {
        getline(cin, comanda);
        if (comanda[0] == "c") {
            push(stack, comanda);
        } else if (comanda[0] == "p") {
            output.push_back(top(stack));
        } else {
            cout << "Nu cunosc aceasta comanda\n";
        }
    }

    for (auto comanda : output) {
        cout << comanda << "\n";
    } 

    return 0;
}
