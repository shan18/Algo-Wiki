/* Implementation of stack in C++
*/


#include <iostream>
#define SIZE 20
using namespace std;


int top = -1;
int stack[SIZE];

void push(int n) {
    if(top == SIZE - 1)
        cout << "Overflow!" << endl;
    else
        stack[++top] = n;
}

int pop() {
    if(top == -1) {
        cout << "Underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

void print_stack() {
    for(int i=0; i <= top; i++)
        cout << stack[i] << " ";
    cout << endl;
}

int main() {
    int n = 1;
    while(n == 1 || n == 2 || n == 3) {
        cout << "1. Push\n" << "2. Pop\n" << "3. Print\n" << "4. Exit" << endl;
        cin >> n;
        switch(n) {
            case 1:
                int a;
                cin >> a;
                push(a);
                break;
            
            case 2:
                cout << pop() << endl;
                break;
            
            case 3:
                print_stack();
        }
    }
}

