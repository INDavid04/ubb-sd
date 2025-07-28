#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

//////////////////////////////
// Adauga un nod la inceput //
//////////////////////////////

void addFirst(node *&head, int x) {
    node *p = new node;
    p -> val = x;
    p -> next = head;
    head = p;
}

////////////////////////////
// Adauga un nod la final //
////////////////////////////

void addLast(node*& head, int x) {
    node *p = new node;
    p->val = x;
    p->next = nullptr;
    if (head == nullptr) {
        head = p;
    } else {
        node *i = head;
        while (i->next != nullptr) {
            i=i->next;
        }
        i->next=p;
    }
}

////////////////////
// Afiseaza lista //
////////////////////

void print(node *head) {
    node *p = head;
    // Parcurgere lista 
    while(p != NULL) {
        cout << p -> val << " ";
        p = p -> next;
    }
}

///////////////////////
// Sterge primul nod //
///////////////////////

node* deleteHead(node* head) {
    node *p = new node;
    if (head == NULL) {
        return NULL;
    }
    p = head->next;
    delete head;
    return p;
}

////////////////////////
// Sterge ultimul nod //
////////////////////////

node* deleteTail(node*& head) {
    if (head == nullptr) {
        cout << "\nNu am ce sa sterg. Lista este goala.";
        return nullptr;
    } else if (head->next == nullptr) {
        cout << "\nSterg " << head->val;
        delete head;
        return nullptr;
    } else {
        node* i = head;
        while (i->next != nullptr) {
            i = i->next;
        }
        cout << "\nSterg " << i->val;
        i = head;
        while (i->next->next != nullptr) {
            i = i->next;
        }
        delete i->next->next;
        i->next = nullptr;
        return head;
    }
}

/////////////////////////////////////////
// Insereaza un nod x pe o pozitie poz //
/////////////////////////////////////////

void insertPoz(node*& head, int poz, int x) {
    if (poz == 0) {
        addFirst(head, x);
    } else {
        node* p = head;
        for (int i = 0; i < poz - 1; i++) {
            p = p->next;
        }
        node* q = new node;
        q->val = x;
        q->next = p->next;
        p->next = q;
    }
}

//////////////////////////
// Cauta o valoare data //
//////////////////////////

void searchValue(node* head, int x) {
    node* p = head;
    int i = 0;
    bool gasit = false;
    while (p != nullptr) {
        if (p->val == x) {
            cout << "\nAm gasit valoarea " << x << " pe pozitia " << i;
            gasit = true;
            break; // comenteaza linia daca vrei toate pozitiile, cu break ne oprim la prima
        }
        p = p->next;
        i++;
    }
    if (!gasit) {
        cout << "\nNu am gasit valoarea " << x << " pe nicio pozitie in lista curenta";
    }
}

int main() {
    ////////////////////////////////
    // Declara lista vida initial //
    ////////////////////////////////

    node *head;
    head = NULL;

    ////////////////////////////////////////////////////////////
    // Adauga nodurile cu valorile 8 si 3 la inceputul listei //
    ////////////////////////////////////////////////////////////

    addFirst(head, 8);
    addFirst(head, 3);
    cout << "Lista dupa adaugarea nodurilor 8 si 3 la inceput: ";
    print(head);

    ///////////////////////////////////
    // Sterge primul nod de doua ori //
    ///////////////////////////////////

    cout << "\nSterg: " << head->val << "\n";
    head = deleteHead(head); 
    cout << "Lista dupa stergerea primului nod: ";
    print(head);

    cout << "\nSterg: " << head->val << "\n";
    head = deleteHead(head);
    cout << "Lista dupa stergerea primului nod: ";
    print(head);

    //////////////////////////////////////////////
    // Adauga nodurile 8 si 3 la finalul listei //
    //////////////////////////////////////////////

    addLast(head, 8);
    addLast(head, 3);
    cout << "\nLista dupa adaugarea nodurilor 8 si 3 la final: ";
    print(head);

    ////////////////////////////////////////////////////////////////
    // Insereaza un nod cu o anumita valoare pe o anumita pozitie //
    ////////////////////////////////////////////////////////////////

    /// Nota: pozitiile incep de la zero

    addFirst(head, 15);
    cout << "\nDupa adaugarea nodului 15 la inceputul listei: ";
    print(head);

    insertPoz(head, 1, 5);
    insertPoz(head, 2, 8);
    cout << "\nDupa inserarea nodului 5 pe pozitia 1 si 8 pe pozita 2: ";
    print(head);

    insertPoz(head, 0, 100);
    insertPoz(head, 4, 4);
    cout << "\nDupa inserarea nodului 100 pe pozitia 0 si 4 pe pozita 4: ";
    print(head);

    ////////////////////////////
    // Cauta valoare in lista //
    ////////////////////////////

    searchValue(head, 8);

    ////////////////////////
    // Sterge ultimul nod //
    ////////////////////////

    head = deleteTail(head);
    cout << "\nLista dupa stergerea ultimului element din lista: ";
    print(head);

    // Pentru a sterge toate elementele (iterativ)

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    // head = deleteTail(head);
    // cout << "\nLista dupa stergerea ultimului element din lista: ";
    // print(head);

    return 0;
}
