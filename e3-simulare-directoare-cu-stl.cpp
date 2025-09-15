/// 2025-09-15-1854-1900

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
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get(); /// consuma \n

    stack<string> st;
    string comanda;

    for (int i = 0; i < n; i++) {
        getline(cin, comanda);
        if (comanda.substr(0, 3) == "cd ") {
            string dir = comanda.substr(3); /// de pe pozitia 3 pana la final
            if (dir == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(dir);
            }
        } else if (comanda == "pwd") {
            if (!st.empty()) {
                cout << st.top() << "\n";
            } else {
                cout << "/\n";
            }
        } else {
            cout << "Nu cunosc comanda\n";
        }
    }

    return 0;
}
