
#define MAX 100
struct nhanvien
{
	string maNV;
	string hoNV;
	string tenLot;
	string tenNV;
	int namSinh;
	double heSoLuong;

};

typedef nhanvien NV;
struct tagNODE
{
	NV info;
	tagNODE* pNext;
};

typedef tagNODE NODE;
struct LIST
{
	NODE* pHead;
	NODE* pTail;

};

//===================

NODE* GetNode(NV x)
{
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;

	}
	return p;
}

void CreatList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmty(LIST& l)
{
	if (l.pHead != NULL)
	{
		return 1;
	}
	return 0;
}

void InsertTail(LIST& l, NV x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "Khong du bo nho";
		return;

	}

	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}

	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}

}

int TapTin_List(char* filename, LIST& l)
{
	NV x;
	ifstream Doc(filename);
	if (!Doc)
	{
		cout << "Khong doc duoc file";
		system("CLS");
		return 0;
	}

	CreatList(l);
	while (Doc >> x.maNV >> x.hoNV >> x.tenLot >> x.tenNV >> x.namSinh >> x.heSoLuong)
	{
		InsertTail(l, x);
	}

	Doc.close();
	return 1;

}

void TieuDe()
{
	cout << "\n";
	cout << ':';
	for (int i = 0; i <= 70; i++)
	{
		cout << '=';
	}
	cout << ':';
	cout << "\n";

	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho NV"
		<< ':'
		<< setw(10) << "Ten Lot"
		<< ':'
		<< setw(10) << "Ten NV"
		<< ':'
		<< setw(10) << "Nam Sinh"
		<< ':'
		<< setw(5) << "Luong"
		<< ':';
	cout << "\n";
	cout << ':';
	for (int i = 0; i <= 70; i++)
	{
		cout << '=';
	}
	cout << ':';
	cout << "\n";

}

void Xuat_NV(NV p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(10) << p.maNV
		<< ':'
		<< setw(10) << p.hoNV
		<< ':'
		<< setw(10) << p.tenLot
		<< ':'
		<< setw(10) << p.tenNV
		<< ':'
		<< setw(10) << p.namSinh
		<< ':'
		<< setw(5) << setprecision(2) << setiosflags(ios::fixed) << p.heSoLuong
		<< ':';

}


void Xuat_DSNV(LIST& l)
{
	TieuDe();
	NODE* p = l.pHead;
	while (p != NULL)
	{
		Xuat_NV(p->info);
		cout << endl;
		p = p->pNext;

	}

}

int SoNut(LIST l)
{
	int i = 0;
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		i++;
	}
	return i;
}


void HoanVi(NV& x, NV& y)
{
	swap(x, y);
}

int DemNhanVienLuongCao(LIST l, double heSoLuong)
{
	int dem = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (p->info.heSoLuong >= heSoLuong)
		{
			dem++;
		}
		p = p->pNext;
	}
	return dem;
}

void XuatNhanVienLuongCao(LIST l, double heSoLuong)
{
	// Đếm số lượng nhân viên thỏa mãn
	int soLuong = DemNhanVienLuongCao(l, heSoLuong);

	TieuDe(); // Xuất tiêu đề bảng

	NODE* p = l.pHead;
	while (p != NULL)
	{
		if (p->info.heSoLuong >= heSoLuong)
		{
			Xuat_NV(p->info); // Xuất thông tin nhân viên
			cout << endl;
		}
		p = p->pNext;
	}

	// In tổng số lượng nhân viên
	cout << "\nTong so nhan vien co he so luong >= 3.4 " << ": " << soLuong << endl;
}


void Nhap_NV(nhanvien& nv) {
	cout << "Nhap MaNV: ";
	cin >> nv.maNV;

	cout << "Nhap Ho: ";
	cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi
	getline(cin, nv.hoNV);

	cout << "Nhap Ten Lot: ";
	getline(cin, nv.tenLot);

	cout << "Nhap Ten: ";
	getline(cin, nv.tenNV);

	cout << "Nhap Nam sinh: ";
	cin >> nv.namSinh;

	cout << "Nhap He so luong: ";
	cin >> nv.heSoLuong;
}



void ChenNhanVienSau(LIST& l, string maNV)
{
	// Tìm nhân viên có mã nhân viên = maNV
	NODE* p = l.pHead;
	while (p != NULL && p->info.maNV != maNV)
	{
		p = p->pNext;
	}

	//// Nếu không tìm thấy nhân viên có mã maNV
	//if (p == NULL)
	//{
	//	cout << "Khong tim thay nhan vien co ma: " << maNV << endl;
	//	return;
	//}

	// Nhập thông tin nhân viên mới
	cout << "Nhap thong tin nhan vien moi:\n";
	nhanvien nvMoi;
	Nhap_NV(nvMoi);

	// Tạo node mới
	NODE* newNode = new NODE;
	newNode->info = nvMoi;

	// Chèn node mới sau node p
	newNode->pNext = p->pNext;
	p->pNext = newNode;

	// Nếu p là node cuối, cập nhật pTail
	if (p == l.pTail)
	{
		l.pTail = newNode;
	}

	cout << "Da chen nhan vien moi sau nhan vien co ma: " << maNV << endl;
}

void XoaNhanVienTheoTen(LIST& l, const string& ten) {
	NODE* p = l.pHead;
	NODE* prev = NULL;

	while (p != NULL)
	{
		if (p->info.tenNV == ten)
		{
			if (prev == NULL)
			{ // Nếu là nút đầu
				l.pHead = p->pNext;
				delete p;
				p = l.pHead;
			}
			else
			{
				prev->pNext = p->pNext;
				if (p == l.pTail) { // Nếu là nút cuối
					l.pTail = prev;
				}
				delete p;
				p = prev->pNext;
			}
		}
		else
		{
			prev = p;
			p = p->pNext;
		}
	}
}

NODE* TK_TUYENTINH_TEN_NHANVIEN(LIST& l, string ten) {
	NODE* ketQua = nullptr; // Con trỏ lưu kết quả cuối cùng
	NODE* p = l.pHead;      // Bắt đầu duyệt từ nút đầu tiên

	while (p != nullptr)
	{
		if (p->info.tenNV == ten)
		{
			ketQua = p; // Cập nhật nút chứa tên khớp
		}
		p = p->pNext; // Di chuyển tới nút tiếp theo
	}

	return ketQua; // Trả về kết quả (nút cuối cùng có tên khớp hoặc nullptr nếu không tìm thấy)
}

