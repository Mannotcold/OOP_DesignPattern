#include "CPhongQuanLy.h"


vector<NhanSu*>PhongQuanLy::ListNhanSu;
vector<NhanSu*>TongNhanSu;

PhongQuanLy::PhongQuanLy()
{
}

PhongQuanLy::~PhongQuanLy() {
		for (auto a : ListNhanSu)
		{
			delete a;
		}
		ListNhanSu.clear();
	}



	void PhongQuanLy::NhapDanhSach()
	{
		PhongQuanLy::ThemDoiTuongMau(new GiangVien);
		PhongQuanLy::ThemDoiTuongMau(new TroGiang);
		PhongQuanLy::ThemDoiTuongMau(new NghienCuuVien);
		PhongQuanLy::ThemDoiTuongMau(new ChuyenVien);
		PhongQuanLy::ThemDoiTuongMau(new ThucTapSinh);

		NhanSu* ns;
		string ChucVu;
		cout << "\nNhap thong tin nhan vien truong dai hoc theo loai: GiangVien, TroGiang, NghienCuuVien, ChuyenVien, ThucTapSinh\n";
		cin >> ChucVu;
		ns = PhongQuanLy::TaoDoiTuongTheoTen(ChucVu);
		ns->NhapNhanSu();
		TongNhanSu.push_back(ns);

				
	}


	void PhongQuanLy::XuatDanhSach()
	{
		for (int i = 0;i < TongNhanSu.size();i++)
		{
			TongNhanSu[i]->XuatNhanSu();
			cout << "\n==============================================\n" << endl;
		}
	}

	float PhongQuanLy::TongLuongNV()
	{
		float Luong = 0;
		for (int i = 0;i < TongNhanSu.size();i++)
		{
			Luong += TongNhanSu[i]->LuongNV();
		}
		return Luong;
	}


	void PhongQuanLy::MaxLuong()
	{
		int a = 0;
		int max = TongNhanSu[0]->LuongNV();
		for (int i = 1; i < TongNhanSu.size(); i++)
		{
			if (max < TongNhanSu[i]->LuongNV())
			{
				a = i;
			}
		}
		cout << "Nhan vien trong truong co muc luong cao nhat la : \n";
		TongNhanSu[a]->XuatNhanSu();
	}

	void PhongQuanLy::ThemDoiTuongMau(NhanSu* ns)
	{
		if (!ns) return;
		for (int i = 0; i < ListNhanSu.size(); i++) {
			NhanSu* mau = ListNhanSu[i];
			if (mau->LayTenDoiTuong() == ns->LayTenDoiTuong())
				return;
		}
		ListNhanSu.push_back(ns);

	}

	NhanSu* PhongQuanLy::TaoDoiTuongTheoTen(string newTen)
	{
		for (int i = 0;i < ListNhanSu.size();i++)
		{
			NhanSu* ns = ListNhanSu[i];
			if (ns->LayTenDoiTuong() == newTen)
				return ListNhanSu[i]->Clone();
		}
	}

	void PhongQuanLy::XoaDoiTuongMau()
	{
		for (auto a : ListNhanSu)
			delete a;
		ListNhanSu.clear();
	}

	bool PhongQuanLy::XoaDoiTuongTheoMaSo(string newMaSo)
	{
		for (int i = 0;i < TongNhanSu.size();i++)
		{
			if (TongNhanSu[i]->GetMaSo() == newMaSo)
			{
				TongNhanSu.erase(TongNhanSu.begin() + i);
				cout << "Xoa thanh cong\n";
				return true;
			}
			cout << "Khong co doi tuong trong danh sach\n";
			return false;
		}
					
	}

	
	