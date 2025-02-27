#include <iostream>
using namespace std;

struct interval{
    int x, y;
};

int main () {

    /* L1 Pointeri */

    /* Tipul de date pointer */
    // int x = 1234; // x: 1234
    // cout << "x: " << x << endl;
    // cout << "sizeof(int): " << sizeof(int) << endl; // sizeof(int): 4
    // cout << "&x: " << &x << endl; // &x: 0x61ff0c

    /* Notam &x adresa lui x si *(&x) valoarea de la adresa lui x */
    // int x = 123;
    // int *px;
    // px = &x;
    // cout << x << " " << px << endl; // 123 0xadresa_lui_x
    // cout << *px << endl; // 123 i.e. valoarea de la adresa lui x
    // *px = *px + 2; // i.e. x = 2
    // cout << x << " " << *px << endl; // 125 125
    // x = x + 4; // i.e. x = 129
    // cout << x << " " << *px << endl; // 129 129

    /* L1 Liste */

    /* Cele doua pi -> x si (*pi).x sunt echivalente */
    // interval i = {4,5};
    // cout << i.x << " " << i.y << endl; // 4 5
    // interval *pi;
    // pi = &i;
    // cout << (*pi).x << " " << (*pi).y << endl; // 4 5 i.e. valoarea de la adresa lui i.x si i.y
    // cout << pi -> x << " " << pi -> y << endl; // 4 5 fiindca (*pi).x <=> pi -> x

    /* Tipul de date referinta. Alias. */
    // int u = 8, &w = u; // declara w ca o referinta la u, un alt nume pentru aceeasi zona de memorie ca u
    // cout << "&u: " << &u << endl; // 0xu i.e. adresa lui u
    // cout << "w: " << w << endl; // 8 fiindca w este doar un alias pentru u
    // cout << "&w: " << &w << endl; // 0xu
    // cout << "*&w: " << *&w << endl; // 8
    // cout << u << " " << w << endl; // 8 8 fiindca w este un alias pentru u
    // u++;
    // cout << u << " " << w <<endl; // 9 9 fiindca orice modificaer a lui u afecteaza si pe w si invers
    // w++;
    // cout << u << " " << w << endl; // 10 10
    // cout << (&u) << " " << (&w) << endl; // adresa_lui_u adresa_lui_u

    /* Alocare dinamica */
    // int *x;
    // x = new int;
    // cin >> (*x); // 8
    // cout << *x << endl; // 8
    // cout << &x << endl; // 0xx
    // delete x;
    // cout << &x << endl; // 0xx
    // cout << *x << endl; // nu da E.C., insa afiseaza o valoare random

    return 0;
}