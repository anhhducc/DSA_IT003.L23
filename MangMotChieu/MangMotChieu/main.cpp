#include "header.h"

int main()
{
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	int* Arr = new int[n];
	NhapMang(Arr, n);
	XuatMang(Arr, n);
	XoaMotPhanTu(Arr, n);
	XuatMang(Arr, n);
	LietKeNhungPhanTuLonNhat(Arr, TimPhanTuLonNhat(Arr, n), n);
	LietKeNhungPhanTuNhoNhat(Arr, TimPhanTuNhoNhat(Arr, n), n);
	DemPhanTuAm(Arr, n);
	TimGiaTriAmLonNhat(Arr, n);
	TimGiaTriDuongNhoNhat(Arr, n);
	TimPhanTu(Arr, n);
	DemPhanTu(Arr, n);


	delete[] Arr;
	return 0;
}