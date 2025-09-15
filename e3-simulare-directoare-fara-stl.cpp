/// 2025-09-15-1905-TODO

/// Incercarea mea de a transforma codul cu stl fara stl

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

using namespace std;

bool eComandaCd(const char comanda[]) {
    if (comanda[0] == 'c' && comanda[1] == 'd' && comanda[2] == ' ') {
        return true;
    } else {
        return false;
    }
}

bool eComandaPwd(const char comanda[]) {
    if (comanda[0] == 'p' && comanda[1] == 'w' && comanda[2] == 'd') {
        return true;
    } else {
        return false;
    }
}

bool eDouaPuncte(const char director[]) {
    if (director[0] == '.' && director[1] == '.') {
        return true;
    } else {
        return false;
    }
}

bool empty(const char &stack) {
    return stack[0][0] == '\0';
}

void pop(const char stack[]) {
    for (int i = 0; stack[i + 1][0] != '\0'; i++) {
        for (j = 0; stack[i][j] != '\0'; j++) {
            stack[i][j] = stack[i + 1][j];
        }
    }
    stack[i][0] = '\n';
}

void push(const char stack[], const char director[]) {
    /// aici m-am blocat
}

int main() {
    int n;
    cin >> n;
    cin.get(); /// consuma \n

    char stack[20][80];
    char comanda[20];

    for (int i = 0; i < n; i++) {
        stack[i][0] = 0; /// initializam stiva cu \0
    }

    for (int i = 0; i < n; i++) {
        cin.get(comanda, 20);
        cin.get();
        
        if (eComandaCd(comanda)) {
            char director[20];
            int k = 0;
            for (int j = 3; comanda[j] != '\0'; j++) {
                director[k++] = comanda[j];
            }
            if (eDouaPuncte(dir)) {
                if (!empty(stack)) {
                    pop(stack);
                }
            } else {
                // push(stack, director);
            }
        } else if (comanda == "pwd") {
            if (!empty(stack)) {
                // cout << st.top() << "\n";
            } else {
                cout << "/\n";
            }
        } else {
            cout << "Nu cunosc comanda\n";
        }
    }

    return 0;
}
