#include "CNghienCuuVien.h"


void NghienCuuVien::ListNghienCuu()
{
	ListNC.push_back("M01");
	ListNC.push_back("X92");
	ListNC.push_back("T02");
	ListNC.push_back("D15");
	ListNC.push_back("D44");
	ListNC.push_back("X47");
}

NghienCuuVien::NghienCuuVien() :
	NhanSu()
{
	KinhNghiemNC = 2;
	ListNghienCuu();
}

NghienCuuVien::NghienCuuVien(string NewHoTen, string NewNamSinh, string NewMaSo, int NewKinhNghiemNC) :
	NhanSu(NewHoTen, NewNamSinh, NewMaSo)
{
	KinhNghiemNC = NewKinhNghiemNC;
	ListNghienCuu();
}

NghienCuuVien::NghienCuuVien(const NghienCuuVien& gv) : NhanSu(gv)
{
	KinhNghiemNC = gv.KinhNghiemNC;
	for (int i = 0;i < gv.ListNC.size();++i)
	{
		ListNC.push_back(gv.ListNC[i]);
	}
}
NghienCuuVien::~NghienCuuVien() {}
string NghienCuuVien::LayTenDoiTuong()
{
	return "NghienCuuVien";
}
NhanSu* NghienCuuVien::Clone()
{
	return new NghienCuuVien(*this);
}
;
int NghienCuuVien::SoMonNC()
{
	int a = 0;
	for (auto sk : ListNC)
	{
		//os << sk << "\n ";
		for (int i = 0;i < sk.size();++i)
		{
			if (sk[i] == 68)
				a++;
		}

	}
	return a;
}

float NghienCuuVien::LuongNV()
{
	return (KinhNghiemNC * 2 + SoMonNC()) * 20000;
}

void NghienCuuVien::NhapNhanSu()
{
	NhanSu::NhapNhanSu();
	cout << "so nam kinh nghiem nghien cuu : ";
	cin >> KinhNghiemNC;
}

void NghienCuuVien::XuatNhanSu()
{
	NhanSu::XuatNhanSu();
	cout << "\nSo nam kinh nghiem nghien cuu : ";
	cout << KinhNghiemNC;
	cout << "\nCac ma du an giao duc da hoan thanh : ";
	cout << SoMonNC();
	cout << "\nLuong : ";
	cout << LuongNV();
}
