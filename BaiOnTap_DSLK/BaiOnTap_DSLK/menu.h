void XuatMenu()
{
	cout << "=========================MENU=========================";
	cout << "\n0.Thoat chuong trinh\n";
	cout << "\n1.Doc file\n";
	cout << "\n2.Xuat danh sach\n";
	cout << "\n3.Diem he so luong nhan vien >= 3.4\n";
	cout << "\n4.Tim kiem theo ten nhan vien\n";
	cout << "\n5.Chen 1 nhan vien sau nhan vien co ma x\n";
	cout << "\n6.Xoa tat ca nhan vien theo ten\n";
	cout << "\n7.Sap xep tang dan theo nam sinh(chon truc tiep)\n";
	cout << "=====================================================";
}

int ChonMenu(int SoMenu)
{
	int stt;
	do
	{
		cout << "\nHay nhap mot so tu [0,..." << SoMenu << "] de chon chuc nang:";
		cin >> stt;
	} while (stt < 0 || stt > SoMenu);
	return stt;

}

void XuLyMenu(int menu, LIST& l, int n)
{
	char filename[MAX];
	int kq;
	string maNVX;
	string ten;
	NODE* nut_kq = NULL;
	switch (menu)
	{
	case 0:
		cout << "Thoat thanh cong!";
		break;
	case 1:
		system("CLS");
		cout << "\nNhap file";
		do
		{
			cout << "\nNhap ten tap tin:";
			cin >> filename;
			kq = TapTin_List(filename, l);

		} while (!kq);
		Xuat_DSNV(l);
		cout << "Danh sach nhap co " << SoNut(l) << " nhan vien";
		cout << endl;
		break;

	case 2:
		system("CLS");
		cout << "2.Xuat danh sach";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "3.Xuat nhan vien co he so luong >= 3.4\n";
		XuatNhanVienLuongCao(l, 3.4);

		break;
	case 4:
		system("CLS");
		cout << "4.Tim kiem theo ten nhan vien";
		Xuat_DSNV(l);
		cout << "\nNhap ten can tim:";
		cin >> ten;
		nut_kq = TK_TUYENTINH_TEN_NHANVIEN(l, ten);
		if (nut_kq != NULL)
		{
			cout << "\nDa tim thay nhan vien " << ten << " tai node cuoi cung:\n";
			TieuDe();
			Xuat_NV(nut_kq->info);
			cout << endl;
		}
		else {
			cout << "\nTen: " << ten << " khong tim thay!!";
		}
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "5. Chen nhan vien sau nhan vien co ma nhan vien = x\n";

		cout << "Nhap ma nhan vien x: ";
		cin >> maNVX;
		ChenNhanVienSau(l, maNVX);

		break;

	case 6:
		system("CLS");
		cout << "6.Xoa tat ca nhan vien theo ten";

		cout << "\nNhap ten can xoa: ";
		cin.ignore();
		getline(cin, ten);
		XoaNhanVienTheoTen(l, ten);
		Xuat_DSNV(l);
		cout << endl;
		break;



	default:
		break;
	}
}

LIST ds;

void ChayChuongTrinh()
{
	int soMenu = 10, n = 0, menu;
	do
	{
		system("CLS");
		XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, ds, n);
		system("pause");


	} while (menu != 0);
}