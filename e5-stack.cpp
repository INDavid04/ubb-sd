/// 2025-09-17-0910-0955

/// Input:
///     6
///     cd a
///     cd b
///     cd c
///     pwd
///     cd ..
///     pwd
/// Output:
///     c
///     b

#include <iostream>

using namespace std;

class Stack {
    char directoare[100][100];
    int size;
public:
    Stack() {
        size = 0;
    }
    void push(char director[]) {
        int i = 0;
        while (director[i] != '\0') {
            directoare[size][i] = director[i];
            i++;
        }
        directoare[size][i] = '\0';
        size++;
    }

    void pop() {
        if (size) {
            size--;
        }
    }

    char *top() {
        return directoare[size - 1];
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    char comanda[100];
    Stack s;
    int n;

    cout << "Numar comenzi: ";
    cin >> n;
    cin.get();

    while (n--) {
        cin.getline(comanda, 100);
        
        if (comanda[0] == 'c' && comanda[1] == 'd' && comanda [2] == ' ') {
            if (comanda[3] == '.' && comanda[4] == '.') {
                s.pop();
            } else {
                char director[100];
                int k = 0;
                for (int i = 0; director[i] != '\0'; i++) {
                    director[k++] = comanda[i];
                }
                s.push(director);
            }
        } else if (comanda[0] == 'p' && comanda[1] == 'w' && comanda[2] == 'd') {
            if (s.empty()) {
                cout << "/\n";
            } else {
                cout << s.top() << "\n";
            }
        } else {
            cout << "Comanda necunoscuta\n";
        }
    }

    return 0;
}
