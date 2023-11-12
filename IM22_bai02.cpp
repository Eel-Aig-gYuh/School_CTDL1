#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct HoaDon {
	int ma, ngayXuat;
	string tenNguoiMua;
	bool thanhToan; // chua thanh toan false, 
	double tongTien;
};
struct Node {
	HoaDon info;
	Node* next, 
		* pre;
};
Node* first, * last;
void init();
Node* creNode(int ma, int ngayXuat, string tenNguoiMua, bool thanhToan, double tongTien);
int insert(Node *p);
void inputDon();
Node* search(int ma);
int del(int ma);
void xoa_HoaDon();
void outPer(Node* p);
void output();
int count_HoaDon();
int interchageSort();
int count_HoaDon();
void bubleSort();
void sort_ABC();

int main() {
	int selected;
	bool inited = false;
	do {
		system("cls");
		cout << "1, Khoi tao." << endl
			<< "2, Them hoa don." << endl
			<< "3, Xoa hoa don." << endl
			<< "4, Xuat hoa don." << endl
			<< "5, Sap xep hoa don." << endl
			<< "6, Thoat chuong trinh." << endl
			<< "Vui long nhap chuc nang: "; cin >> selected;
		switch (selected) {
		case 1: 
			init();
			inited = true;
			cout << "Khoi tao danh sach thanh cong !" << endl;
			break;
		case 2:
			if (inited == false) {
				cout << "Vui long khoi tao danh sach !" << endl;
			}
			else {
				inputDon();
			}
			break;
		case 3: 
			if (inited == false) {
				cout << "Vui long khoi tao danh sach !" << endl;
			}
			else {
				xoa_HoaDon();
			}
			break;
		case 4:
			if (inited == false) {
				cout << "Vui long khoi tao danh sach !" << endl;
			}
			else {
				output();
			}
			break;
		case 5:
			if (inited == false) {
				cout << "Vui long khoi tao danh sach !" << endl;
			}
			else {
				sort_ABC();
			}
			break;
		default:
			return 0;	
			break;
		}
		_getch();
	} while (true);
}

void sort_ABC() {
	if (count_HoaDon() % 2 == 0) {
		bubleSort();
		cout << "Sap xep thanh cong theo kieu buble sort!" << endl;
	}
	else {
		interchageSort();
		cout << "Sap xep thanh cong theo kieu interchange sort!" << endl;
	}
}
void bubleSort() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = first;
		while (q->next != NULL) {
			Node* r = q->next;
			if (r->info.tongTien > q->info.tongTien) {
				swap(r->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
int count_HoaDon() {
	int count = 0;
	Node* p = first;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
int interchageSort() {
	if (first == NULL) return 0;
	Node* p = first;
	while (p != NULL) {
		Node* q = p->next;
		while (q != NULL) {
			if (p->info.tongTien < q->info.tongTien) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
	return 1;
}
void output() {
	Node* p = first;
	while (p != NULL) {
		cout << endl;
		outPer(p);
		cout << endl;
		p = p->next;
	}
}
void outPer(Node* p) {
	cout << "Ma don hang: " << p->info.ma << endl;
	cout << "Ngay xuat don: " << p->info.ngayXuat << endl;
	cout << "Ten nguoi mua: " << p->info.tenNguoiMua << endl;
	cout << "Tinh trang don: "; 
	if (p->info.thanhToan == true) cout << "Da thanh toan " << endl; 
	else cout << "Chua thanh toan " << endl;
	cout << "Tong tien: " << p->info.tongTien << endl;
}
void xoa_HoaDon() {
	int ma;
	cout << "Nhap ma hoa don muon xoa: ";
	cin >> ma;
	if (del(ma) == 0) {
		cout << "Xoa khong thanh cong !" << endl;
	}
	else
		cout << "Xoa thanh cong !" << endl;
}
int del(int ma) {
	if (first == NULL || last == NULL) return 0;
	Node* pos = search(ma);
	if (pos == NULL)
		return 0;
	if (pos == first) {
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL) {
			first->pre = NULL;
		}
		else{
			last = NULL;
		}
	}
	else if (pos == last) {
		Node* p = last;
		last = last->pre;
		if (last != NULL) {
			last->next = NULL;
		}
		else {
			first = NULL;
		}
		delete p;
	}
	else {
		pos->pre->next = pos->next;
		pos->next->pre = pos->pre;
		delete pos;
	}
	return 1;
}
Node* search(int ma) {
	Node* p = first;
	while (p != NULL && p->info.ma != ma) {
		p = p->next;
	}
	return p;
}
void inputDon() {
	int ma, ngayXuat;
	string tenNguoiMua;
	bool thanhToan = false; // chua thanh toan false, 
	double tongTien;
	bool valid = true;
	int soDon;
	do {
		cout << "Vui long dien so don muon nhap: "; cin >> soDon;
		if (soDon <= 0)
			cout << "Nhap khong hop le !" << endl;
	} while (soDon <= 0);
	for (int i = 0; i < soDon; i++) {
		cout << endl << "So don thu " << i + 1 << endl;
		cout << "Vui long nhap ma hoa don: ";
		cin >> ma;
		cout << "Vui long nhap ngay xuat don: ";
		cin >> ngayXuat;
		cin.ignore();
		cout << "Vui long nhap ten nguoi mua: ";
		getline(cin, tenNguoiMua);
		do {
			char tmp;
			cout << "Vui long nhap trang thai thanh toan: (y/n)";
			cin >> tmp; cin.ignore();
			if (tmp == 'y' || tmp == 'Y') {
				thanhToan = true;
				valid = true;
			}
			else if (tmp == 'n' || tmp == 'N') {
				thanhToan = false;
				valid = true;
			}
			else {
				cout << "Nhap sai yeu cau !" << endl;
				valid = false;
			}
		} while (valid != true);
		do {
			cout << "Vui long nhap tong tien: ";
			cin >> tongTien;
			if (tongTien < 0)
				cout << "Tong tien khong nhap am !" << endl;
		} while (tongTien < 0);
		if (insert(creNode(ma, ngayXuat, tenNguoiMua, thanhToan, tongTien)) == 0)
			cout << "Them khong thanh cong !" << endl;
		else
			cout << "Them thanh cong !" << endl;
	}
}
int insert(Node* p) {
	if (p == NULL) return 0;
	p->next = first;
	if (first != NULL)
		first->pre = p;
	else
		last = p;
	first = p;
	return 1;
}
Node* creNode(int ma, int ngayXuat, string tenNguoiMua, bool thanhToan, double tongTien) {
	Node* p = new Node;
	p->info.ma = ma;
	p->info.ngayXuat = ngayXuat;
	p->info.tenNguoiMua = tenNguoiMua;
	p->info.thanhToan = thanhToan;
	p->info.tongTien = tongTien;
	p->next = NULL;
	p->pre = NULL;
	return p;
}
void init() {
	first = NULL;
	last = NULL;
}