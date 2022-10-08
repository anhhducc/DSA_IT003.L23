#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
typedef struct Node* stack;
struct Stack {
    Node* head;
    Node* tail;
};

bool isEmpty(stack s) {
    return (s == NULL);
}

Node* createNode(int data) {
    Node* p = new Node();
    if (p == NULL) {
        return NULL;
    }
    p->data = data;
    p->next = NULL;

    return p;
}

void push(stack& s, int data) {
    Node* ptr = createNode(data);
    if (isEmpty(s)) {
        s = ptr;
    }
    else {
        ptr->next = s;
        s = ptr;
    }
}

int top(stack s) {
    if (!isEmpty(s)) {
        return s->data;
    }
    else {
        cout << "Stack rong" << endl;
    }
}


int pop(stack& s) {
    if (!isEmpty(s)) {
        int data = s->data;
        Node* x = s;
        s = s->next;
        delete(x);
        cout << "*da xoa" << endl;
        return data;
    }
    else {
        cout << "Stack rong" << endl;
    }
}

int main() {
    stack s;
    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);
    push(s, 14);
    push(s, 15);
    push(s, 16);
    cout << "Phan tu dau tien: " << top(s) << endl;
    pop(s);
    cout << "Phan tu dau tien: " << top(s) << endl;
}