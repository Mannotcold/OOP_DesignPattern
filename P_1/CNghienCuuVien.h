#pragma once
#include"CNhanSu.h"
class NghienCuuVien :public NhanSu
{
private:
	int KinhNghiemNC;
	vector<string> ListNC;
public:
	void ListNghienCuu();
	NghienCuuVien();
	NghienCuuVien(string NewHoTen, string NewNamSinh, string NewMaSo, int NewKinhNghiemNC);
	NghienCuuVien(const NghienCuuVien& gv);
	~NghienCuuVien();
	string LayTenDoiTuong();
	
	NhanSu* Clone();
	int SoMonNC();
	float LuongNV();
	void NhapNhanSu();
	void XuatNhanSu();
};
