/* Implementation of queue in C++
*/

#include <iostream>
#define SIZE 20
using namespace std;


int front = -1;
int rear = -1;
int queue[SIZE];

void insert(int n) {
    if((rear + 1) % SIZE == front)
        cout << "Overflow!" << endl;
    else {
        rear = (rear + 1) % SIZE;
        if(front == -1)
            front = 0;
        queue[rear] = n;
    }
}

int remove() {
    if(front == -1) {
        cout << "Underflow!" << endl;
        return -1;
    } else {
        int x = queue[front];
        if(front == rear)
            front = rear = -1;
        else if(front == SIZE - 1)
            front = 0;
        else
            front++;
        return x;
    }
}

void print_queue() {
    if(front <= rear) {
        for(int i=front; i <= rear; i++)
            cout << queue[i] << " ";
    } else {
        for(int i=front; i < SIZE; i++)
            cout << queue[i] << " ";
        for(int i=0; i <=rear; i++)
            cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 1;
    while(n == 1 || n == 2 || n == 3) {
        cout << "1. Insert\n" << "2. Delete\n" << "3. Print\n" << "4. Exit" << endl;
        cin >> n;
        switch(n) {
            case 1:
                int a;
                cin >> a;
                insert(a);
                break;
            
            case 2:
                cout << remove() << endl;
                break;
            
            case 3:
                print_queue();
        }
    }
}
