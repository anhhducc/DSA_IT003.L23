#include<iostream>
#include<stack>
#include<math.h>
#include<queue>
using namespace std;

void chuyen(char a[], queue<char>& b) {
	int size = strlen(a);
	for (int i = 0; i < size; i++) {
		b.push(a[i]);
	}
}
float Tinh(char dau, float a, float b) {
	if (dau == '+')
		return a + b;
	if (dau == '-')
		return a - b;
	if (dau == '*')
		return a * b;
	if (dau == '/')
		return a / b;
	if (dau == '^')
		return pow(a, b);
}
bool check(char a) {
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^')return 0;
	else return 1;
}
float chuyen1(char a) {
	return float(a) - 48;
}
float compute(queue<char>& a, stack<float>& b) {
	float kq = 0;
	while (!a.empty()) {
		char temp = a.front();
		a.pop();
		if (check(temp))
			b.push(chuyen1(temp));
		else {
			float num1 = b.top();
			b.pop();
			float num2 = b.top();
			b.pop();
			kq = Tinh(temp, num2, num1);
			b.push(kq);
		}
	}
	return kq;
}
int main() {
	char a[50];
	cout << "Nhap bieu thuc (theo ky phap Balan): ";
	cin.getline(a, 50);
	stack<float>b;
	queue<char>c;
	chuyen(a, c);
	float kq = compute(c, b);
	cout << "Ket qua la: " << kq;
}