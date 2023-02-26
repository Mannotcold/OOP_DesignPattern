#include "CPhongQuanLy.h"
PhongQuanLy* PhongQuanLy::instance = NULL;
vector<NhanSu*>PhongQuanLy::ListNhanSu;
vector<NhanSu*>TongNhanSu;

PhongQuanLy::PhongQuanLy()
{
	this->ListNhanSu;
}

PhongQuanLy::~PhongQuanLy() {
	for (auto a : ListNhanSu)
	{
		delete a;
	}
	ListNhanSu.clear();
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

PhongQuanLy* PhongQuanLy::getInstance()
{
	if (!instance)
		instance = new PhongQuanLy();
	return instance;
}

void PhongQuanLy::Menu()
{
	PhongQuanLy::getInstance;
	PhongQuanLy::ThemDoiTuongMau(new GiangVien);
	PhongQuanLy::ThemDoiTuongMau(new TroGiang);
	PhongQuanLy::ThemDoiTuongMau(new NghienCuuVien);
	PhongQuanLy::ThemDoiTuongMau(new ChuyenVien);
	PhongQuanLy::ThemDoiTuongMau(new ThucTapSinh);
	NhanSu* ns;
	int choice;
	while (1) {
		system("cls");
		cout << "\t\t============================Menu===================================\n";
		cout << "\t\t1. Nhap thong tin nhan vien truong dai hoc.\n";
		cout << "\t\t2. Xuat danh sach cac nhan vien trong truong dai hoc. \n";
		cout << "\t\t3. Xuat tong luong ma truong phai tra trong 1 thang. \n";
		cout << "\t\t4. Xuat thong tin nhan vien co luong cao nhat. \n";
		cout << "\t\t5. Xoa doi tuong dua theo ma so. \n";
		cout << "\t\t0. Thoat. \n" << endl;
		cout << "\t\t===================================================================\n";
		cout << "\t\tNhap lua chon : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string ChucVu;
			cout << "\nNhap thong tin nhan vien truong dai hoc theo loai: GiangVien, TroGiang, NghienCuuVien, ChuyenVien, ThucTapSinh\n";
			cin >> ChucVu;
			ns = PhongQuanLy::TaoDoiTuongTheoTen(ChucVu);
			ns->NhapNhanSu();
			TongNhanSu.push_back(ns);
			break;
		}
		case 2:
		{
			for (int i = 0;i < TongNhanSu.size();i++)
			{
				TongNhanSu[i]->XuatNhanSu();
				cout << "\n==============================================\n" << endl;
			}
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Tong luong : ";
			float Luong = 0;
			for (int i = 0;i < TongNhanSu.size();i++)
			{
				Luong += TongNhanSu[i]->LuongNV();
			}
			cout << Luong << endl;
			system("pause");
			break;
		}
		case 4:
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
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			string ms;
			cout << "Nhap ma so doi tuong muon xoa: ";
			cin >> ms;
			XoaDoiTuongTheoMaSo(ms);
			system("pause");
			break;
		}
		case 0:
		{
			exit(0);
			break;

		}
		}
	}

}
