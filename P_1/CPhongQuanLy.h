#pragma once
#include"CGiangVien.h"
#include"CTroGiang.h"
#include"CNghienCuuVien.h"
#include"CChuyenVien.h"
#include"CThucTap.h"

class PhongQuanLy
{
private:
	static vector<NhanSu*>ListNhanSu;
public:
	PhongQuanLy();
	~PhongQuanLy();
	void NhapDanhSach();
	void XuatDanhSach();
	float TongLuongNV();
	void MaxLuong();
	static void ThemDoiTuongMau(NhanSu* ns);
	static NhanSu* TaoDoiTuongTheoTen(string newTen);
	static void XoaDoiTuongMau();
	static bool XoaDoiTuongTheoMaSo(string newMaSo);
	
};

