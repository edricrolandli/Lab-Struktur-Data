#include <iostream>
using namespace std;

// Deklarasi struktur node
struct node {
    int value;
    node *next;
};

// node head sama tail ini kayak deklarasi di awal, karena node awalnya itu masih kosong, jadi sebelum ada nilai itu diisi null dulu
node *head = NULL;
node *tail = NULL;

// Insert di depan
void insertFirst(int n){
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = head;
    }
    else
    {
        newnode -> next = head;
        head = newnode;
    }
}

// Insert di belakang
void insertLast(int n){
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL)
    {
        head = newnode;
        tail = head;
    }
    else
    {
        tail -> next = newnode;
        tail = newnode;
    }
}

// Insert setelah node dgn nilai tertentu
void insertAfter(int n, int check){
    if (head == NULL)
    {
        cout << "List kosong, insert di depan dahulu\n";
        return;
    }
    
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL; 
    
    node *p = head;
    // intinya while ini ngecek satu" linked list yang kita punya, sampai kondisinya salah di mana dia cek valuenya itu sama atau enggak, ketika sama maka kondisinya false kan, nah jadi p itulah nanti masuk ke next node
    while (p != NULL && p -> value != check)
    {
        p = p -> next;
    }

    if (p == NULL)
    {
        cout << "node dengan nilai " << check << " tidak ditemukan\n";
        delete newnode;
    }
    else
    {
        newnode -> next = p -> next;
        p -> next = newnode;
        if (p == tail)
        {
            tail == newnode;
        }
    }
}


void printList(){
    node *temp = head;
    cout << "Isi linked list : ";
    while (temp != NULL)
    {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main(){
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}