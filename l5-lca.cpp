/// TODO: solve this problem from the following link: https://www.infoarena.ro/problema/lca

#include <bits/stdc++.h>
using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int NMAX = 1000005;
int N, M;
int tati[NMAX];
vector<int> L[NMAX];
int e[2*NMAX]; // doi pentru ca avem muchiile dublate, odata cand ajung la nodul 7 si cand plec din 7, spre exemplu
int niv[2*NMAX];

void Euler(int nod, int lvl) {
    e[sz] = nod;
    niv[sz] = lvl;
    sz++;
    for (int fiu: L[nod]) {
        cout << fiu << " ";
        Euler(fiu, lvl + 1);
        e[sz] = nod;
        niv[sz] = lvl;
        sz++;
    }
}

void calc_rmq(int n) {

}

void calc_rmq() {
    for (i = 0; i < n; i++) {
        rmq[i][0] = i;
    }
    for (j = 1; j <= log2(n); j++) {
        for (i = 0; i <= n - (1 << j); i++) {
            if (niv[rmq[i][j-1]])
        }
    }
}

int main () {
    fin >> N >> M;
    for (int i = 1; i < N; i++) {
        int j;
        fin >> j;
        L[j].pushback(i);
    }
    Euler(0, 0);
    for (int i = 0; i < sz; i++) {
        
    }
}
