#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cctype>

using namespace std;
struct SinhVien {
	string maSV;
	string hoTen;
	int namSinh;
	string diaChi;
	bool gioiTinh; // nam: true / nu: false;
	double diemTB;
};
struct Node {
	SinhVien info;
	Node* next;
};
Node* first;
void init();
Node* cre(SinhVien sv);
int insertPer(Node *p);
void inputPer();
int loadFile(char s[256]);
void outPer(Node* p);
void display();

int main() {
	char s[256] = "On_BTH1.txt";
	init();
	loadFile(s);
	display();

	system("pause");
	return 0;
}


void display() {
	Node* p = first;
	while (p != NULL) {
		outPer(p);
		cout << endl;
		p = p->next;
	}
}
void outPer(Node* p) {
	cout << "=== \t THONG TIN SINH VIEN \t ===" << endl;
	cout << "MSSV: " << p->info.maSV << endl;
	cout << "Ho va ten: " << p->info.hoTen << endl;
	cout << "Nam sinh: " << p->info.namSinh << endl;
	cout << "Dia chi: " << p->info.diaChi << endl;
	cout << "Gioi tinh: "; 
	if (p->info.gioiTinh) cout << "Nam" << endl;
	else cout << "Nu" << endl;
	cout << "Diem trung binh: " << p->info.diemTB << endl;
}
int loadFile(char s[256]) {
	ifstream in;
	in.open(s, ios::in);
	if (!in.is_open()) return 0;
	int n; in >> n; in.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		SinhVien sv;
		string tmp;
		stringstream ss(s);

		getline(in, s);
		getline(ss, sv.maSV, '#');
		getline(ss, sv.hoTen, '#');
		getline(ss, tmp, '#'); sv.namSinh = stoi(tmp);
		getline(ss, sv.diaChi, '#');
		getline(ss, tmp, '#'); 
		for (int j = 0; j < tmp.size(); j++) {
			tmp[j] = tolower(tmp[j]);
		}
		if (tmp == "nam") sv.gioiTinh = true;
		else sv.gioiTinh = false;
		getline(ss, tmp, '#'); sv.diemTB = stoi(tmp);
		insertPer(cre(sv));
	}
	in.close();
	return 1;
}
void inputPer() {
	SinhVien sv;
	cout << "=== \t THONG TIN SINH VIEN \t ===" << endl;
	cout << "Nhap ma so:\t"; cin >> sv.maSV;
	cout << "Nhap ho ten:\t"; cin >> sv.hoTen;
	cout << "Nhap nam sinh:\t"; cin >> sv.namSinh; cin.ignore();
	cout << "Nhap dia chi:\t"; cin >> sv.diaChi; 
	char tmp;
	do {
		cout << "Nhap gioi tinh: y/n (y: male, n: female)\t"; cin >> tmp;
		tmp = tolower(tmp);
		if (tmp != 'y' || tmp != 'n')
			cout << "Nhap sai, nhap lai !" << endl;
	} while (tmp != 'y' || tmp != 'n');
	cout << "Nhap diem trung binh:\t"; cin >> sv.diemTB; cin.ignore();
	if (insertPer(cre(sv)) == 0) {
		cout << "Them khong thanh cong !" << endl;
	}
	else
		cout << "Them thanh cong !" << endl;
}
int insertPer(Node* p) {
	if (!p) return 0;
	if (first == NULL)
		first = p;
	else {
		p->next = first;
		first = p;
	}
	return 1;
}
Node* cre(SinhVien sv) {
	Node* p = new Node;
	p->info.maSV = sv.maSV;
	p->info.hoTen = sv.hoTen;
	p->info.namSinh = sv.namSinh;
	p->info.diaChi = sv.diaChi;
	p->info.gioiTinh = sv.gioiTinh;
	p->info.diemTB = sv.diemTB;
	p->next = NULL;
	return p;
}
void init() {
	first = NULL;
}