#include "header.h"

void NhapMang(int* Arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << ":";
		cin >> Arr[i];
	}
}
void XuatMang(int* Arr, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Arr[" << i << "]:" << Arr[i] << endl;
	}
}
void XoaMotPhanTu(int* Arr, int& n) {
	cout << "Nhap phan tu can xoa " << endl;
	int k;
	cin >> k;
	if (k >= 0 && k < n) {
		for (int i = k; i < n - 1; i++)
		{
			Arr[i] = Arr[i + 1];
		}
		n--;
	}
	else
		cout << "Khong co phan tu de xoa" << endl;
}
int TimPhanTuLonNhat(int* Arr, int n) {
	int iMax = Arr[0];
	for (int i = 1; i < n; i++)
	{
		if (Arr[i] > iMax)
		{
			iMax = Arr[i];
		}
	}
	return iMax;
}
void LietKeNhungPhanTuLonNhat(int* Arr, int iMax, int n) {
	cout << "\n" << "Nhung phan tu lon nhat la: " << "\t";
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == iMax)
		{
			cout << "Arr[" << i << "]" << "\t";
		}
	}
}
int TimPhanTuNhoNhat(int* Arr, int n) {
	int iMin = Arr[0];
	for (int i = 1; i < n; i++)
	{
		if (Arr[i] < iMin)
		{
			iMin = Arr[i];
		}
	}
	return iMin;
}
void LietKeNhungPhanTuNhoNhat(int* Arr, int iMin, int n) {
	cout << "\n" << "Nhung phan tu nho nhat la: " << "\t";
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == iMin)
		{
			cout << "Arr[" << i << "]" << "\t";
		}
	}
}
void DemPhanTuAm(int* Arr, int n) {
	cout << "\n" << "Phan tu am la: " << "\t";
	int iDem = 0;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] < 0)
		{
			cout << "Arr[" << i << "]" << "\t";
			iDem++;
		}
	}
	if (iDem == 0)
		cout << " Khong co" << endl;

}
void TimGiaTriAmLonNhat(int* Arr, int n) {
	int iAmMax=0;
	for (int j = 0; j < n; j++)
	{
		if (Arr[j] < 0)
		{
			iAmMax = Arr[j];
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if ((Arr[i] > iAmMax) && (Arr[i] < 0))
		{
			iAmMax = Arr[i];
		}
	}
	if (iAmMax==0)
		cout << "\n" << "Khong co gia tri am lon nhat";
	else 
		cout << "\n" << "Gia tri am lon nhat cua mang la :" << iAmMax;
	
}
void TimGiaTriDuongNhoNhat(int* Arr, int n) {
	int iDuongMin=0;
	for (int j = 0; j < n; j++)
	{
		if (Arr[j] > 0)
		{
			iDuongMin = Arr[j];
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if ((Arr[i] < iDuongMin) && (Arr[i] > 0))
		{
			iDuongMin = Arr[i];
		}
	}
	if( iDuongMin==0)
		cout << "\n" << "Khong co gia tri duong nho nhat" << endl;
	else
		cout << "\n" << "Gia tri duong nho nhat cua mang la :" << iDuongMin << endl;
		
}
void TimPhanTu(int* Arr, int n)
{
	int x;
	int dem = 0;
	cout << "Nhap so can tim:";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == x)
		{
			cout << "Co" << endl;
			dem++;
			break;
		}
	}
	if (dem == 0)
	cout << "Khong" << endl;
}
void DemPhanTu(int* Arr, int n) {
	int x;
	cout << "Nhap phan tu can dem: " << endl;
	cin >> x;
	int count = 0;
	for (int j = 0; j < n; j++) {
		if (Arr[j] == x) {
			count++;
		}
	}
	if (count > 0) {
		cout << "Co " <<count <<" phan tu co gia tri la " << x << endl;
	}
	else
		cout << "Khong co phan tu co gia tri la " << x << endl;
}