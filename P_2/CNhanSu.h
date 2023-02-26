#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class NhanSu
{
private:
	string HoTen;
	string NamSinh;
	string MaSo;
public:

	NhanSu(string NewHoTen, string NewNamSinh, string NewMaSo);
	NhanSu(const NhanSu& gv);
	NhanSu();
	~NhanSu();
	virtual NhanSu* Clone() = 0;
	virtual string LayTenDoiTuong() = 0;
	string GetMaSo();
	virtual void NhapNhanSu();
	virtual void XuatNhanSu();
	virtual float LuongNV() = 0;
};