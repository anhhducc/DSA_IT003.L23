#include <iostream>
using namespace std;
int current_size = -1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];

bool isEmpty() {
    return (current_size == -1);
}

bool isFull() {
    return (current_size == MAX_SIZE);
}

void push(int data) {
    if (!isFull()) {
        current_size++;
        stack[current_size] = data;
    }
    else {
        cout << "Stack da day" << endl;
    }
}

int top() {
    if (!isEmpty()) {
        int data = stack[current_size];
        return data;
    }
    else {
        cout << "Stack rong" << endl;
    }
}

int pop() {
    if (!isEmpty()) {
        int data = stack[current_size];
        current_size--;
        return data;
    }
    else {
        cout << "Stack rong" << endl;
    }
}

void viewstack() {
    if (!isFull()) {
        for (int i = current_size; i >= 0; i--) {
            cout << stack[i] << "<--";
        }
        cout << endl;
    }
}

int main() {
    cout << "Nhap vao 1,2,3,4,5,6 " << endl;
    for (int i = 1; i <= 6; i++) {
        push(i);
    }
    cout << "Phan tu dau tien " << top() << endl;
    viewstack();
    pop();
    cout << "Phan tu dau tien " << top() << endl;
    viewstack();
}