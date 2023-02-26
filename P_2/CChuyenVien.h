#pragma once
#include"CNhanSu.h"


class ChuyenVien :public NhanSu
{
private:
	int KinhNghiemLV;
	vector<string> ListGD;
public:
	void ListGiaoDuc();
	ChuyenVien();
	ChuyenVien(string NewHoTen, string NewNamSinh, string NewMaSo, int NewKinhNghiemLV);
	ChuyenVien(const ChuyenVien& gv);
	~ChuyenVien();
	string LayTenDoiTuong();
	NhanSu* Clone();
	int SoMonLV();
	float LuongNV();
	void NhapNhanSu();
	void XuatNhanSu();
};

