#include"CPhongQuanLy.h"


int main()
{

	PhongQuanLy ds;
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
			ds.NhapDanhSach();
			break;
		}
		case 2:
		{
			ds.XuatDanhSach();
			cout << endl;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Tong luong : ";
			cout << ds.TongLuongNV() << endl;
			system("pause");
			break;
		}
		case 4:
		{
			ds.MaxLuong();
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			string ms;
			cout << "Nhap ma so doi tuong muon xoa: ";
			cin >> ms;
			ds.XoaDoiTuongTheoMaSo(ms);
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
	return 0;
}

