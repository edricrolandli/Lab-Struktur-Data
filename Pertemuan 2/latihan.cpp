#include <iostream>
using namespace std;

// Deklarasi struktur node
struct node {
    int value;
    node *next;
};

// Deklarasi di awal dulu yaa
node* top = NULL;

// Buat nambah data intinya, tapi naruh dari atas karena stacking
void push(int n) {
    node* newnode = new node;
    newnode -> value = n;
    newnode -> next = top;

    top = newnode;

    cout << n << " ditambahkan ke stack.\n";
}

// hapus data, dari atas juga
void pop() {
    if (top == NULL) 
    {
        cout << "List kosong!\n";
        return;
    }

    cout << top->value << " dihapus dari stack.\n";

    node* temp = top;
    top = top->next;
    delete temp;
}

// tampilkan, display
void printStack() {
    if (top == NULL) 
    {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "Isi stack: ";
    node* temp = top;

    while (temp != NULL) 
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    push(10);
    push(20);
    push(30);

    printStack();

    pop();

    printStack();

    return 0;
}
