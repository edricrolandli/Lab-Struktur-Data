#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1; // awalnya kosong

// push = memasukkan 
void push (int value) {
    if (top == MAX) {
        cout << "Stack Penuh!\n";
    }
    else
    {
        top++;
        stack[top] = value;
        cout << value << " masuk ke stack \n";
    }
}

// pop
void pop (){
    if (top == -1) {
        cout << "Stack kosong!\n";
    }
    else
    {
        cout << stack[top] << " keluar dari stack.\n";
        top--;
    }
}

// nampilin stack
void display(){
    if (top == -1) {
        cout << "Stack kosong!\n";
    }
    else
    {
        cout << "\nisi stack : ";

        for (int i = top; i >= 0; i--){
            cout << stack[i] << " ";
        }

        cout << endl;
    }
}

int main (){
    system("CLS");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    for (int i = 0; i < 5; i++)
    {
        pop();
        display();
    }

    return 0;
}