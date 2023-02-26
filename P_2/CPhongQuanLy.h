#pragma once
#include"CGiangVien.h"
#include"CTroGiang.h"
#include"CNghienCuuVien.h"
#include"CChuyenVien.h"
#include"CThucTap.h"

class PhongQuanLy
{
private:
	static PhongQuanLy* instance;
	static vector<NhanSu*>ListNhanSu;
	PhongQuanLy();
public:
	~PhongQuanLy();
	static void ThemDoiTuongMau(NhanSu* ns);
	static NhanSu* TaoDoiTuongTheoTen(string newTen);
	static void XoaDoiTuongMau();
	static bool XoaDoiTuongTheoMaSo(string newMaSo);
	static PhongQuanLy* getInstance();
	static void Menu();
};

