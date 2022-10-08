#include<iostream>
#include<stdio.h>
#include< string >
using namespace std;

struct Sv {
	string MaSV, Ten;
	float DTB;
	int XepLoai;
};
struct node {
	Sv i4;
	node* pNext;
};
struct list {
	node* pHead;
	node* pTail;
};
node* CreateNode(Sv x) {
	node* p = new node;
	p->i4 = x;
	p->pNext = NULL;
	return p;
}
void CreateNewList(list& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
void AddHead(list& l, node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void XuatList(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << "   " << p->i4.Ten << "\n";
		p = p->pNext;
	}
}
void FindNode(list l, Sv x) {
	int m = 0;
	node* p = l.pHead;
	while (p != NULL)
	{
		if (p->i4.MaSV == x.MaSV)
		{
			cout << "Co sinh vien " << x.Ten << endl;
			m++;
			break;
		}
		p = p->pNext;
	}
	if (m == 0)cout << "Khong co sinh vien " << x.Ten << endl;
}
void DeleteNode(list& l, Sv x) {
	node* p = l.pHead;
	if (p->i4.MaSV == x.MaSV) {
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
		delete p;
		return;
	}
	while (p != NULL)
	{
		if (p->pNext->i4.MaSV == x.MaSV)
		{
			p->pNext = p->pNext->pNext;
			break;
		}
		p = p->pNext;
	}
}
void SortListLow(list& l) {
	node* p = l.pHead;
	while (p != NULL) {
		node* q = p->pNext;
		while (q != NULL) {
			if (p->i4.DTB < q->i4.DTB) swap(p->i4, q->i4);
			q = q->pNext;
		}
		p = p->pNext;
	}
}
void AddAfterQ(list& l, node* p, node* Q) {
	if (Q != NULL)
	{
		p->pNext = Q->pNext;
		Q->pNext = p;
		if (l.pTail == Q)
			l.pTail = p;
	}
	else
		AddHead(l, p);
}
void ChenGiuNguyenListTang(list& l, Sv x) {
	node* q = NULL, * p = l.pHead;
	while (p != NULL && p->i4.DTB > x.DTB) {
		q = p;
		p = p->pNext;
	}
	AddAfterQ(l, CreateNode(x), q);
}
void XepLoai(list l) {
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	node* p = l.pHead;
	while (p != NULL)
	{
		if (p->i4.DTB <= 3.6) { p->i4.XepLoai = 1; a++; }
		if (p->i4.DTB >= 5.0 && p->i4.DTB < 6.5) { p->i4.XepLoai = 2; b++; }
		if (p->i4.DTB >= 6.5 && p->i4.DTB < 7.0) { p->i4.XepLoai = 3; c++; }
		if (p->i4.DTB >= 7.0 && p->i4.DTB < 8.0) { p->i4.XepLoai = 4; d++; }
		if (p->i4.DTB >= 8.0 && p->i4.DTB < 9.0) { p->i4.XepLoai = 5; e++; }
		if (p->i4.DTB >= 9.0 && p->i4.DTB < 10.0) { p->i4.XepLoai = 6; f++; }
		p = p->pNext;
	}
	p = l.pHead;
	if (a > 0)cout << "Sinh vien loai Yeu : \n";
	while (p != NULL) {
		if (p->i4.XepLoai == 1)cout << p->i4.MaSV << " " << p->i4.Ten << "\n";
		p = p->pNext;
	}
	p = l.pHead;
	if (b > 0)cout << "Sinh vien loai Trung Binh : \n";
	while (p != NULL) {
		if (p->i4.XepLoai == 2)cout << p->i4.MaSV << " " << p->i4.Ten << "\n";
		p = p->pNext;
	}
	p = l.pHead;
	if (c > 0)cout << "Sinh vien loai Trung Binh Kha : \n";
	while (p != NULL) {
		if (p->i4.XepLoai == 3)cout << p->i4.MaSV << " " << p->i4.Ten << "\n";
		p = p->pNext;
	}
	if (d > 0)cout << "Sinh vien loai Kha : \n";
	p = l.pHead;
	while (p != NULL) {
		if (p->i4.XepLoai == 4)cout << p->i4.MaSV << " " << p->i4.Ten << "\n";
		p = p->pNext;
	}
	p = l.pHead;
	if (e > 0)cout << "Sinh vien loai Gioi : \n";
	while (p != NULL) {
		if (p->i4.XepLoai == 5)cout << p->i4.MaSV << " " << p->i4.Ten << "\n";
		p = p->pNext;
	}p = l.pHead;
	if (f > 0)cout << "Sinh vien loai Xuat Sac : \n";
	while (p != NULL) {
		if (p->i4.XepLoai == 6)cout << p->i4.MaSV << " " << p->i4.Ten << "\n";
		p = p->pNext;
	}
}
int main() {
	list l;
	CreateNewList(l);
	Sv x, y, z;
	do {
		cout << "Nhap ten : ";
		getline(cin, x.Ten);
		if (x.Ten == "")break;
		cout << "Nhap ma sv : ";
		getline(cin, x.MaSV);
		do {
			cout << "Nhap diem TB : ";
			cin >> x.DTB;
		} while (x.DTB > 10);
		cin.ignore();
		if (x.Ten != "") {
			node* p = CreateNode(x);
			AddHead(l, p);
		}
	} while (x.Ten != "");
	SortListLow(l);
	XuatList(l);
	//
	cout << "Ma so sinh vien can tim :";
	getline(cin, x.MaSV);
	FindNode(l, x);
	//
	cout << "Ma so sinh vien can xoa : ";
	getline(cin, y.MaSV);
	DeleteNode(l, y);
	XuatList(l);
	system("pause");
	//
	cout << "Nhung sinh vien co Diem Trung Binh lon hon 5 la : \n";
	node* p = l.pHead;
	while (p != NULL)
	{
		if (p->i4.DTB >= 5) {
			cout << "   " << p->i4.Ten << "\n";
		}
		p = p->pNext;
	}
	//6
	XepLoai(l);
	//7
	cout << "Danh sach sinh vien sau khi sap xep la : \n";
	SortListLow(l);
	XuatList(l);
	//8 
	cout << "Ma so sinh vien chen vao: ";
	getline(cin, z.MaSV);
	cout << "Ten sinh vien chen vao: ";
	getline(cin, z.Ten);
	do {
		cout << "Diem TB sinh vien chen vao : ";
		cin >> z.DTB;
	} while (z.DTB > 10);
	ChenGiuNguyenListTang(l, z);
	XuatList(l);
}
