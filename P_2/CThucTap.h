#pragma once
#include"CNhanSu.h"
class ThucTapSinh :public NhanSu
{
private:
	int KinhNghiemLV;
	vector<string> ListDADB;
public:
	ThucTapSinh();
	ThucTapSinh(const ThucTapSinh& gv);
	~ThucTapSinh();
	string LayTenDoiTuong();
	NhanSu* Clone();
	int SoDoAnDuBi();
	float LuongNV();
	void NhapNhanSu();
	void XuatNhanSu();
};
