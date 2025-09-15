/// 2025-09-15-1950-2024

/// GPT

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

void pop(int &size) {
    size--;
}

void push(char stack[][80], const char director[], int &size) {
    int i = 0;
    for(; director[i] != '\0'; i++) {
        stack[size][i] = director[i];
    }
    stack[size][i] = '\0';
    size++;
}

int main() {
    int n;
    cin >> n;
    cin.get(); /// consuma \n

    char stack[20][80];
    char output[20][80];
    int size = 0, outputSize = 0;;

    for (int i = 0; i < n; i++) {
        char comanda[20];
        cin.getline(comanda, 20);
        
        if (eComandaCd(comanda)) {
            char director[20];
            int k = 0;
            for (int j = 3; comanda[j] != '\0'; j++) {
                director[k++] = comanda[j];
            }
            director[k] = '\0'; /// la final
            
            if (eDouaPuncte(director)) {
                if (size) {
                    pop(size);
                }
            } else {
                push(stack, director, size);
            }
        } else if (eComandaPwd(comanda)) {
            if (size) {
                size--;
                int j = 0;
                for (; stack[size][j] != 0; j++) {
                    output[outputSize][j] = stack[size][j];
                }
                output[outputSize][j] = '\0';
                size++;
                outputSize++;
            } else {
                cout << "/\n";
            }
        } else {
            cout << "Nu cunosc comanda\n";
        }
    }

    for (int i = 0; i < outputSize; i++) {
        for (int j = 0; output[i][j] != '\0'; j++) {
            cout << output[i][j];
        }
        cout << '\n';
    }

    return 0;
}
