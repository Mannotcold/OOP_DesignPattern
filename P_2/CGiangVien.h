#pragma once
#include"CNhanSu.h"

class GiangVien :public NhanSu
{
private:
	string HocHam;
	string HocVi;
	int ThamNien;
	int Mon;
	vector<string>List;

public:

	GiangVien();
	GiangVien(const GiangVien& gv);
	~GiangVien();
	string LayTenDoiTuong();
	NhanSu* Clone();
	float LuongNV();
	void NhapNhanSu();
	void XuatNhanSu();


};