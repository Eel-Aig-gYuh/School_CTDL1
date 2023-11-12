// QUAN LI DANH SACH SINH VIEN
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<iomanip>
#define MAX 100
using namespace std;
struct SinhVien {
	string maSV, hoTen, diaChi;
	int namSinh;
	bool gioiTinh; // nam la true, nu la false
	double diemTB;
};
struct Node {
	SinhVien info;
	Node* next;
};
Node* first;
void init();
bool checkGerender(string s);
void insert(Node* sv);
Node* showInfo();
void input(int &n);
int inputFromFile(int& n, char s[256]);
void outputOnePer(Node* sv);
void output(int n);
Node* filterId(string s);
void filterName(string s); // chua lam
void filterAge(int s); 
void filterAddress(string s); 
void filterGerender(bool s); 
void filterMark(double s);
void insertOnePer(int& n);
void delFirstPer();
int delPer(string s);
void sortId();
void sortName();
void sortAge();
void sortMark();
int outFile(int n, char s[256]);
void delLinkedList();

int main() {
	char s[256] = "SV.txt";
	char outName[256];
	Node* tmp;
	int n = 0, choice, cfilter, intValue, pos;
	bool hadValue = false;
	string stringValue;
	double doubleValue;
	do {
		system("cls");
		cout << "=== QUAN LI DANH SACH SINH VIEN ===\n"
			<< "1, Khoi tao\n"
			<< "2, Nhap thong tin sinh vien tu ban phim\n"
			<< "3, Nhap thong tin sinh vien tu tap tin\n"
			<< "4, Xuat danh sach sinh vien\n"
			<< "5, Loc danh sach\n"
			<< "6, Them mot sinh vien vao danh sach\n"
			<< "7, Xoa mot sinh vien khoi danh sach\n"
			<< "8, Sap xep danh sach sinh vien\n"
			<< "9, Ghi danh sach sinh vien ra tap tin\n"
			<< "10, Thoat chuong trinh\n"
			<< "Ban chon: "; cin >> choice; cin.ignore();
		switch (choice) {
		case 1: // khoi tao
			init();
			cout << "Da khoi tao thanh cong !" << endl;
			break;
		case 2: // nhap tu ban phim
			input(n);
			cout << "Nhap thanh cong !" << endl;
			hadValue = true;
			break;
		case 3: // nhap tu file
			if (inputFromFile(n, s) == 1) {
				cout << "Nhap thong tin thanh cong !" << endl;
				hadValue = true;
			}
			else {
				cout << "Nhap khong thanh cong do khong mo duoc file !" << endl;
			}
			break;
		case 4: // xuat danh sach
			if (!hadValue)
				cout << "Danh sach trong !" << endl;
			else {
				output(n);
			}
			break;
		case 5: // loc danh sach
			if (!hadValue)
				cout << "Danh sach trong !" << endl;
			else {
				cout << "=== THANH PHAN DU LIEU ===\n"
					<< "1, Ma so sinh vien\n"
					<< "2, Ho va ten sinh vien\n"
					<< "3, Nam sinh sinh vien\n"
					<< "4, Dia chi sinh vien\n"
					<< "5, Gioi tinh\n"
					<< "6, Diem TB\n"
					<< "Ban chon: "; cin >> cfilter; cin.ignore();
				switch (cfilter) {
				case 1: // loc id
					cout << "Nhap ma so sinh vien: "; cin >> stringValue;
					tmp = filterId(stringValue);
					if (tmp == NULL) {
						cout << "Khong co sinh vien co ma " << stringValue << endl;
					}
					else {
						outputOnePer(tmp);
					}
					break;
				case 2: // loc theo ten
					cout << "Nhap ten sinh vien: "; getline(cin, stringValue);
					filterName(stringValue);
					break;
				case 3: // loc theo nam sinh
					cout << "Nhap nam sinh: "; cin >> intValue; cin.ignore();
					filterAge(intValue);
					break;
				case 4: // loc theo dia chi
					cout << "Nhap dia chi: "; getline(cin, stringValue);
					filterAddress(stringValue);
					break;
				case 5: // loc theo gioi tinh
					cout << "Nhap gioi tinh: (nam/nu)"; cin >> stringValue;
					filterGerender(checkGerender(stringValue));
					break;
				case 6: // loc theo diem TB
					cout << "Nhap diem trung binh: "; cin >> doubleValue;
					filterMark(doubleValue);
					break;
				default:
					break;

				}
			}
			break;
		case 6: // them sinh vien
			insertOnePer(n);
			hadValue = true;
			break;
		case 7: // xoa sinh vien
			if (!hadValue)
				cout << "Danh sach trong !" << endl;
			else {
				cout << "Nhap ma sinh vien muon xoa: "; getline(cin, stringValue);
				if (delPer(stringValue) == 0)
					cout << "Khong ton tai sinh vien trong danh sach de xoa !" << endl;
				else {
					cout << "Xoa thanh cong !" << endl;
				}
				break;
			}
		case 8: // sort
			if (!hadValue)
				cout << "Danh sach trong !" << endl;
			else {
				cout << "=== CAC THANH PHAN SAP XEP ===\n"
					<< "1, Theo ma\n"
					<< "2, Theo ten\n"
					<< "3, Theo nam sinh\n"
					<< "4, Theo diem trung binh\n"
					<< "Ban chon: "; cin >> cfilter; cin.ignore();
				switch (cfilter) {
				case 1: // ma
					sortId();
					cout << "Danh sach da duoc sap xep theo ma !" << endl;
					break;
				case 2: // ten
					sortName();
					cout << "Danh sach da duoc sap xep theo ten !" << endl;
					break;
				case 3: // theo nam sinh
					sortAge();
					cout << "Danh sach da duoc sap xep theo nam sinh !" << endl;
					break;
				case 4: // theo diem tb
					sortMark();
					cout << "Danh sach da duoc sap xep theo diem trung binh !" << endl;
					break;
				default:
					break;
				}
			}
			break;
		case 9: // xuat file
			if (!hadValue)
				cout << "Danh sanh trong !" << endl;
			else {
				cout << "Nhap ten file muon xuat: "; cin.getline(outName, 256);
				if (outFile(n, outName) == 1)
					cout << "Xuat file thanh cong !" << endl;
				else
					cout << "Xuat file khong thanh cong !" << endl;
			}
			break;
		default:
			cout << "Da thoat chuong trinh !" << endl;
			delLinkedList();
			return 0;
		}

		_getch();
	} while (true);
}

void delLinkedList() {
	if (!first) return;
	Node* p = first;
	while (p != NULL) {
		delFirstPer();
		p = p->next;
	}
	init();
}
void sortMark() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = p->next;
		while (q != NULL) {
			if (p->info.diemTB > q->info.diemTB) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void sortAge() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = p->next;
		while (q != NULL) {
			if (p->info.namSinh > q->info.namSinh) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void sortName() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = p->next;
		stringstream ss1 (p->info.hoTen);
		string s1;
		while (ss1 >> s1) {}
		while (q != NULL) {
			stringstream ss2(q->info.hoTen);
			string s2;
			while(ss2>>s2){}
			if (s1[0] > s2[0]) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void sortId() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = p->next;
		while (q != NULL) {
			if (p->info.maSV > q->info.maSV) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
int outFile(int n, char s[256]) {
	ofstream out;
	out.open(s, ios::app);
	if (!out.is_open())
		return 0;
	Node* p = first;
	out << n << endl;
	while (p != NULL) {
		out << p->info.maSV << "#"
			<< p->info.hoTen << "#"
			<< p->info.namSinh << "#"
			<< p->info.diaChi << "#";
		if (p->info.gioiTinh) out << "Nam#";
		else out << "Nu#";
		out << p->info.diemTB << endl;
		p = p->next;
	}
	out.close();
	return 1;
}
int delPer(string s) {
	Node* pos = filterId(s);
	if (pos == NULL) return 0;
	if (pos == first) {
		delFirstPer();
		return 1;
	}
	Node* p = first;
	while (p->next != pos) {
		p = p->next;
	}
	p->next = pos->next;
	delete pos;
}
void delFirstPer() {
	if (!first) return;
	Node* p = first;
	first = first->next;
	delete p;
}
void insertOnePer(int& n) {
	int pos;
	do {
		cout << "Nhap vi tri muon them: "; cin >> pos; cin.ignore();
		if (pos <= 0 || pos > n)
			cout << "So sinh vien khong hop le, tong sinh vien hien tai: " << n << endl;
	} while (pos <= 0 || pos > n);
	pos--;
	if (pos == 0) {
		insert(showInfo());
	}
	else {
		int i = 0;
		Node* p = first;
		Node* front = NULL;
		while (i != pos) {
			front = p;
			p = p->next;
			++i;
		}
		Node *q = showInfo();
		front->next = q;
		q->next = p;
		++n;
	}
	cout << "Them thanh cong !" << endl;
}
void filterMark(double s) {
	Node* p = first;
	bool had = false;
	while (p != NULL) {
		if (p->info.diemTB == s) {
			outputOnePer(p);
			had = true;
		}
		p = p->next;
	}
	if (!had)
		cout << "Khong co sinh vien !" << endl;
}
void filterGerender(bool s) {
	Node* p = first;
	bool had = false;
	while (p != NULL) {
		if (p->info.gioiTinh == s) {
			outputOnePer(p);
			had = true;
		}
		p = p->next;
	}
	if (!had)
		cout << "Khong co sinh vien !" << endl;
}
void filterAddress(string s) {
	Node* p = first;
	bool had = false;
	while (p != NULL) {
		if (p->info.diaChi == s) {
			outputOnePer(p);
			had = true;
		}
		p = p->next;
	}
	if (!had)
		cout << "Khong co sinh vien !" << endl;
}
void filterAge(int s) {
	Node* p = first;
	bool had = false;
	while (p != NULL) {
		if (p->info.namSinh == s) {
			outputOnePer(p);
			had = true;
		}
		p = p->next;
	}
	if (!had)
		cout << "Khong co sinh vien !" << endl;
}
void filterName(string s) {
	Node* p = first;
	bool had = false;
	while (p != NULL) {
		if (s == p->info.hoTen) {
			outputOnePer(p);
			had = true;
		}
		else {
			stringstream ss(p->info.hoTen);
			string name;
			while (ss >> name) {
				if (name == s) {
					outputOnePer(p);
					had = true;
				}
			}
		}
		p = p->next;
	}
	if (!had)
		cout << "Khong co sinh vien !" << endl;
}
Node* filterId(string s) {
	Node* p = first;
	while (p != NULL && p->info.maSV != s) {
		p = p->next;
	}
	return p;
}
void output(int n) {
	if (!first) {
		cout << "Danh sach hien dang trong !" << endl;
		return;
	}
	Node* p = first;
	cout << "Danh sach hien tai co " << n << " sinh vien\n";
	int i = 1;
	while (p != NULL) {
		cout << "Thong tin sinh vien thu " << i << endl;
		outputOnePer(p);
		++i;
		p = p->next;
	}
}
void outputOnePer(Node* sv) {
	cout << "Ma sinh vien: " << sv->info.maSV << "\n"
		<< "Ho va ten: " << sv->info.hoTen << "\n"
		<< "Nam sinh: " << sv->info.namSinh << "\n"
		<< "Dia chi: " << sv->info.diaChi << "\n"
		<< "Gioi tinh: "; if (sv->info.gioiTinh == 1) cout << "Nam\n"; else cout << "Nu\n";
	cout << "Diem trung binh: " << sv->info.diemTB << "\n";
	cout << endl;
}
int inputFromFile(int& n, char tenFile[256]) {
	ifstream in;
	int m;
	in.open(tenFile, ios::in);
	if (!in.is_open()) return 0;
	else {
		in >> m; in.ignore();
		for (int i = n; i < n+m; i++) {
			Node* sv = new Node;
			string s, tmp;
			getline(in, s);
			stringstream ss(s);
			getline(ss, tmp, '#'); sv->info.maSV = tmp;
			getline(ss, tmp, '#'); sv->info.hoTen = tmp;
			getline(ss, tmp, '#'); sv->info.namSinh = stoi(tmp);
			getline(ss, tmp, '#'); sv->info.diaChi = tmp;
			getline(ss, tmp, '#'); if (checkGerender(tmp)) sv->info.gioiTinh = true; else sv->info.gioiTinh = false;
			getline(ss, tmp, '#'); sv->info.diemTB = stod(tmp);
			insert(sv);
		}
	}
	in.close();
	n += m;
	return 1;
}
void input(int &n) {
	do {
		cout << "Nhap tong so sinh vien can luu thong tin: ";
		cin >> n; cin.ignore();
		if (n <= 0 || n > MAX)
			cout << "Khong hop le, nhap lai !" << endl;
	} while (n <= 0 || n > MAX);
	cout << "Nhap thong tin cho " << n << " sinh vien:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Sinh vien thu " << i + 1 << endl;
		insert(showInfo());
		cout << endl;
	}
}
Node* showInfo() {
	Node* sv = new Node;
	sv->next = NULL;
	cout << "Nhap ma so: "; getline(cin, sv->info.maSV);
	cout << "Nhap ho va ten: "; getline(cin, sv->info.hoTen);
	cout << "Nhap nam sinh: "; cin >> sv->info.namSinh; cin.ignore();
	cout << "Nhap dia chi: "; getline(cin, sv->info.diaChi);
	cout << "Nhap gioi tinh: (nam / nu) "; string s; getline(cin, s); sv->info.gioiTinh = checkGerender(s);
	cout << "Nhap diem trung binh: "; cin >> sv->info.diemTB; cin.ignore();
	return sv;
}
void insert(Node* sv) {
	if (!sv) return;
	sv->next = first;
	first = sv;
}
bool checkGerender(string s) {
	if (s == "Nam" || s == "nam") {
		return true;
	}
	return false;
}
void init() {
	first = NULL;
}