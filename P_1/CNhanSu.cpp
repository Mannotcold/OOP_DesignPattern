#include "CNhanSu.h"
NhanSu::NhanSu(string NewHoTen, string NewNamSinh, string NewMaSo)
{
	HoTen = NewHoTen;
	NamSinh = NewNamSinh;
	MaSo = NewMaSo;
}

NhanSu::NhanSu(const NhanSu& gv)
{
	HoTen = gv.HoTen;
	NamSinh = gv.NamSinh;
	MaSo = gv.MaSo;
}
NhanSu::NhanSu()
{
	HoTen = "";
	NamSinh = "";
	MaSo = "";
}
NhanSu::~NhanSu()
{
	HoTen = "";
	NamSinh = "";
	MaSo = "";
};

string NhanSu::GetMaSo()
{
	return MaSo;
}

void NhanSu::NhapNhanSu()
{
	cin.ignore();
	cout << "\nNhap ten: ";
	getline(cin, HoTen);
	cout << "Nhap nam sinh: ";
	getline(cin, NamSinh);
	cout << "Nhap ma so: ";
	getline(cin, MaSo);


}

void NhanSu::XuatNhanSu()
{
	cout << "\nTen : ";
	cout << HoTen;
	cout << "\nNam sinh : ";
	cout << NamSinh;
	cout << "\nMa so : ";
	cout << MaSo;
}