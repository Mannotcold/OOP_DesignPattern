#include "CGiangVien.h"
GiangVien::GiangVien() :
	NhanSu()
{
	HocHam = "Giao Su";
	HocVi = "Tien Si";
	ThamNien = 5;
	Mon = 2;
}


GiangVien::GiangVien(const GiangVien& gv) : NhanSu(gv)
{
	HocHam = gv.HocHam;
	HocVi = gv.HocVi;
	ThamNien = gv.ThamNien;
	Mon = gv.Mon;
	for (int i = 0;i < gv.List.size();++i)
	{
		List.push_back(gv.List[i]);
	}

}


GiangVien::~GiangVien() {
	List.clear();
}
string GiangVien::LayTenDoiTuong()
{
	return "GiangVien";
}

NhanSu* GiangVien::Clone()
{
	return new GiangVien(*this);
}


float GiangVien::LuongNV()
{
	return Mon * ThamNien * 0.12 * 20000;;
}

void GiangVien::NhapNhanSu()
{

	string TenMon;
	NhanSu::NhapNhanSu();
	cout << "Nhap hoc ham cua giang vien : ";
	getline(cin, HocHam);
	cout << "Nhap hoc vi cua giang vien : ";
	getline(cin, HocVi);
	cout << "Nhap tham nien cua giang vien : ";
	cin >> ThamNien;
	cout << "Nhap so mon cua giang vien : ";
	cin >> Mon;
	for (int i = 0;i < Mon;i++)
	{
		cout << "Nhap ten mon giang vien giang day : ";
		cin >> TenMon;
		List.push_back(TenMon);
	}
	cin.ignore();
}

void GiangVien::XuatNhanSu()
{
	NhanSu::XuatNhanSu();
	cout << "\nHoc vi cua giang vien : ";
	cout << HocVi;
	cout << "\nHoc ham cua giang vien : ";
	cout << HocHam;
	cout << "\nTham nien cua giang vien : ";
	cout << ThamNien;
	cout << "\nSo mon cua giang vien : ";
	cout << Mon;
	cout << "\nTen cac mon dang day : ";
	for (auto sk : List)
	{
		cout << sk << ", ";
	}
	cout << "\nLuong : ";
	cout << LuongNV();
}



