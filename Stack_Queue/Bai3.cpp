#include<iostream>
using namespace std;
struct Node {
    Node* next;
    int data;
};

struct Queue {
    Node* head, * tail;
};

void Init(Queue& q) {
    q.head = q.tail = NULL;
}

Node* createNode(int x) {
    Node* p = new Node;
    if (!p) exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void Push(Queue& q, Node* p) {
    if (!q.head) q.head = q.tail = p;
    else {
        q.tail->next = p;
        q.tail = p;
    }
}

int Top(Queue q) {
    if (q.head) {
        return q.head->data;
    }
    else return 0;
}

int Pop(Queue& q) {
    if (q.head) {
        Node* p = q.head;
        q.head = q.head->next;
        return p->data;
        delete p;
    }
    return 0;
}

void nhap(Queue& q) {
    int n, x;
    cout << "Nhap so phan tu them vao trong Queue: ";
    cin >> n;
    while (n--) {
        cout << "\nNhap phan tu trong Q: "; cin >> x;
        Node* p = createNode(x);
        Push(q, p);
    }
}

void xuat(Queue q) {
    Node* p = q.head;
    while (p) {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Queue q;
    Init(q);
    nhap(q);
    xuat(q);
    Top(q);
    Pop(q);
    xuat(q);
}