#include "CChuyenVien.h"

void ChuyenVien::ListGiaoDuc()
{
	ListGD.push_back("M01");
	ListGD.push_back("X92");
	ListGD.push_back("T02");
	ListGD.push_back("D15");
	ListGD.push_back("D44");
	ListGD.push_back("X47");
	ListGD.push_back("I47");
}

ChuyenVien::ChuyenVien() :
	NhanSu()
{
	KinhNghiemLV = 2;
	ListGiaoDuc();
}

ChuyenVien::ChuyenVien(string NewHoTen, string NewNamSinh, string NewMaSo, int NewKinhNghiemLV) :
	NhanSu(NewHoTen, NewNamSinh, NewMaSo)
{
	KinhNghiemLV = NewKinhNghiemLV;
	ListGiaoDuc();
}

ChuyenVien::ChuyenVien(const ChuyenVien& gv) : NhanSu(gv)
{
	KinhNghiemLV = gv.KinhNghiemLV;
	for (int i = 0;i < gv.ListGD.size();++i)
	{
		ListGD.push_back(gv.ListGD[i]);
	}
}
ChuyenVien::~ChuyenVien() {}
string ChuyenVien::LayTenDoiTuong()
{
	return "ChuyenVien";
}
NhanSu* ChuyenVien::Clone()
{
	return new ChuyenVien(*this);
}
int ChuyenVien::SoMonLV()
{
	int a = 0;
	for (auto sk : ListGD)
	{
		for (int i = 0;i < sk.size();++i)
		{
			if (sk[i] == 84)
				a++;
		}

	}
	return a;
}

float ChuyenVien::LuongNV()
{
	return (KinhNghiemLV * 4 + SoMonLV()) * 18000;
}

void ChuyenVien::NhapNhanSu()
{
	NhanSu::NhapNhanSu();
	cout << "Nhap so nam kinh nghiem lam viec cua chuyen vien : ";
	cin >> KinhNghiemLV;
}

void ChuyenVien::XuatNhanSu()
{
	NhanSu::XuatNhanSu();
	cout << "\nSo nam kinh nghiem lam viec cua chuyen vien : ";
	cout << KinhNghiemLV;
	cout << "\nCac ma du an giao duc da hoan thanh : ";
	cout << SoMonLV();
	cout << "\nLuong : ";
	cout << LuongNV();
}