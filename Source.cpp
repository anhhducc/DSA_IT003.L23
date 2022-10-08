#include <iostream>
#include <math.h>
using namespace std;
struct DonThuc{
float heso;
int  somu;
};
struct DaThuc{
       DonThuc  A[50];
};
void NhapDaThuc(DaThuc& a, int& n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.A[i].heso;
        cin >> a.A[i].somu;
    }
}
void XuatDaThuc(DaThuc& a, int& n) {
    DonThuc b;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a.A[i].somu < a.A[j].somu) {
                b = a.A[j];
                a.A[j] = a.A[i];
                a.A[i] = b;
            }
    int i = 0;
    while (i < n)
    {
        while (a.A[i].somu == a.A[i + 1].somu)
        {
            if (i >= n - 1) break;
            a.A[i].heso += a.A[i + 1].heso;
            for (int j = i + 1; j < n - 1; j++)
            {
                a.A[j] = a.A[j + 1];
            }
            n--;
        }
        i++;
    }
    if ((a.A[0].somu) == 0)cout << a.A[0].heso; else
        if ((a.A[0].somu) == 1 && (a.A[i].heso) == 1) cout << "x"; else
            if (a.A[0].heso == 1)cout << "x^" << a.A[0].somu; else
                if (a.A[0].heso == 0) cout << 0;else
                    cout << a.A[0].heso << "x^" << a.A[0].somu;
    for (int i = 1; i < n; i++) {
        if ((a.A[i].heso) == 0) continue;
        if ((a.A[i].heso) == 1)
            if ((a.A[i].somu) == 0)cout << "+" << a.A[i].heso; else
                if ((a.A[i].somu) == 1) cout << "+" << "x"; else
                    cout << "+" << "x^" << a.A[i].somu;
        if ((a.A[i].heso) > 1) {
            if ((a.A[i].somu) == 0)cout << "+" << a.A[i].heso; else
                if ((a.A[i].somu) == 1) cout << "+" << a.A[i].heso << "x"; else
                    cout << "+" << a.A[i].heso << "x^" << a.A[i].somu;
        }
        if ((a.A[i].heso) <0 )
            if ((a.A[i].somu) == 0)cout << a.A[i].heso; else
                if ((a.A[i].somu) == 1) cout << a.A[i].heso << "x"; else
                    cout << a.A[i].heso << "x^" << a.A[i].somu;
    }
    cout << endl;
}

void XacDinhBac(DaThuc a, int n,int& m) {
     m=a.A[0].somu;
    for (int i = 0; i < n; i++) {
        if (a.A[i].somu > m)m = a.A[i].somu;
    }
    cout << "Bac cua da thuc la : " << m<<endl;
}
void TinhDaThuc(DaThuc a, int n) {
    int x;
    int s = 0;
    cout << "Nhap x : "; cin >> x;
    for (int i = 0; i < n; i++)
    {
        s = a.A[i].heso * pow(x, a.A[i].somu) + s;
    }
    cout << "Gia tri cua da thuc bang : " << s<<endl;
}
DaThuc CongDaThuc(DaThuc a, DaThuc b, int& n, int& m) {
    DaThuc c;
    for (int i = 0; i < n; i++) {
         c.A[i]=a.A[i] ;
    }
    for (int j = 0; j < m; j++)
         c.A[j+n]= b.A[j];
    return c;
}
DaThuc TruDaThuc(DaThuc a, DaThuc b, int n, int m) {
    DaThuc c;
    for (int i = 0; i < n; i++) {
        c.A[i] = a.A[i];
    }
    for (int j = 0; j < m; j++) {
        c.A[j + n].heso = -(b.A[j].heso);
        c.A[j + n].somu = b.A[j].somu;
    }
    return c;
}
DaThuc DonNhanDa(DonThuc b, DaThuc a, int n) {
    for (int i = 0; i < n; i++) {
        a.A[i].heso = a.A[i].heso * b.heso;
        a.A[i].somu = a.A[i].somu + b.somu;
    }
    return a;
}
void DaNhanDa(DaThuc a, DaThuc b, int n, int m) {
    DaThuc c[50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i].A[j].heso = a.A[i].heso * b.A[j].heso;
            c[i].A[j].somu = a.A[i].somu + b.A[j].somu;
        }
    }
    DaThuc p ;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p.A[k] = c[i].A[j] ;
            k++;
        }
    }
    XuatDaThuc(p, k);
}
int main() {
    int n, m, x;
    DaThuc a,b,c,d;
    NhapDaThuc(a, n);
    XuatDaThuc(a, n);
    XacDinhBac(a, n, x);
    TinhDaThuc(a, n);
    NhapDaThuc(b, m);
    XuatDaThuc(b, m);
    c = CongDaThuc(a, b, n, m);
    int k = n + m;
    cout << "Tong 2 da thuc la : ";
    XuatDaThuc(c,k);
    k = n + m;
    c = TruDaThuc(a, b, n, m);
    cout << "Hieu 2 da thuc la :";
    XuatDaThuc(c, k);
    int l = m * n;
    cout << "Tich 2 da thuc la : ";
    DaNhanDa(a, b, n, m);

}
