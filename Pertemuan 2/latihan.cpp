#include <iostream>
using namespace std;

// deklarasi struktur node
// bikin struktur data node untuk linked list, terus nyimpen nilai (angka) yang masuk ke stack
struct node {
    int value;
    node *next; // pointer ke node berikutnya (kayak rantai penghubung)
};

// deklarasi di awal dulu yaa sebagai penanda paling atas (top) stack, awalnya kosong (NULL)
node* top = NULL;

// buat nambah data intinya, tapi naruh dari atas karena stacking
/* 
1. bkin node baru dulu di memori
2. node tadi diisi dgn value yang di input user
3. baru node baru tadi sambungkan ke node paling atas (sebagai headnya)
*/
void push(int n) 
{
    node* newnode = new node;
    newnode -> value = n; 
    newnode -> next = top;   

    top = newnode;       

    cout << n << " ditambahkan ke stack.\n";
}

// hapus data, dari atas juga
/* 
1. cek dulu, klo stack kosong yauda return
2. klo engga, node paling di put di variabel temp
3. geser dulu status top ke node di bawahnya
4. hapus node temp tadi
*/
void pop() 
{                       
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
/*
1. cek dulu, klo stack kosong yauda return
2. display ini bakal mulai dari paling top
3. then looping selama node itu gak null
4. nah dalam looping itu temp nya bakal otomatis move ke next node, makanya bakal sampe akhir
*/
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
