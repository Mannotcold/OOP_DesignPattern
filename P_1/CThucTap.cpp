#include "CThucTap.h"



ThucTapSinh::ThucTapSinh() :
	NhanSu()
{
}

ThucTapSinh::ThucTapSinh(const ThucTapSinh& gv) : NhanSu(gv)
{
	for (int i = 0;i < gv.ListDADB.size();++i)
	{
		ListDADB.push_back(gv.ListDADB[i]);
	}
}
ThucTapSinh::~ThucTapSinh() {}
string ThucTapSinh::LayTenDoiTuong()
{
	return "ThucTapSinh";
}
;

NhanSu* ThucTapSinh::Clone()
{
	return new ThucTapSinh(*this);
}

int ThucTapSinh::SoDoAnDuBi()
{
	int a = 0;
	for (auto sk : ListDADB)
	{
		for (int i = 0;i < sk.size();++i)
		{
			if (sk[i] == 82)
				a++;
		}

	}
	return a;
}

float ThucTapSinh::LuongNV()
{
	return (SoDoAnDuBi() * 0.1) * 10000;
}

void ThucTapSinh::NhapNhanSu()
{
	int Mon;
	string TenMon;
	NhanSu::NhapNhanSu();
	cout << "Nhap so do an du bi cua thuc tap sinh tham gia : ";
	cin >> Mon;
	for (int i = 0;i < Mon;i++)
	{
		cout << "Nhap ten do an du bi : ";
		cin >> TenMon;
		ListDADB.push_back(TenMon);
	}
}

void ThucTapSinh::XuatNhanSu()
{
	NhanSu::XuatNhanSu();
	cout << "\nSo do an du bi ma thuc tap sinh tham gia : ";
	cout << SoDoAnDuBi();
	cout << "\nLuong : ";
	cout << LuongNV();
}