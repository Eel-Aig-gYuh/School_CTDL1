#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
struct MonHoc {
	int ma, tinChi;
	string tenMon, tenGV;
	char hocKi[4];
	string trangThai; // chua mo, dang dien ra, da hoan tat
};
struct Don {
	MonHoc info;
	Don* next;
};
struct Kep {
	MonHoc info;
	Kep* next,
		* pre;
};
Don* head;
Kep* first, * last;
void init();
Don* inputDon();
Kep* inputKep();
int insert_dsDon(Don* p);
int insert_dsKep(Kep* p);
void input(string s);
void outPerDon(Don* p);
void outPerKep(Kep* p);
void output();
int del(int ma);

int main() {

	return 0;
}

int del(int ma) {
	bool valid = false;
	Don* p = head;
	Don* f = NULL;
	while (p != NULL && p->info.ma != ma) {
		f = p;
		p = p->next;
	}
	if (p != NULL) {
		valid = true;
		if (p == head) {
			head = head->next;
		}
		else {
			f->next = p->next;
		}
		delete p;
	}
	
	Kep* kp = first;
	while (kp != NULL && kp->info.ma != ma) {
		kp = kp->next;
	}
	if (kp != NULL) {
		valid = true;
		if (kp == first) {
			first = first->next;
			if (first != NULL) {
				first->pre = NULL;
			}
			else {
				last = NULL;
			}
		}
		else if (kp == last) {
			last = last->pre;
			if (last != NULL) {
				last->next = NULL;
			}
			else
				first = NULL;
		}
		else {
			kp->pre->next = kp->next;
			kp->next->pre = kp->pre;
		}
		delete kp;
	}
	if (valid) return 1;
	return 0;
}
void output() {
	Don* p = head;
	Kep* q = first;
	cout << "Danh sach lien ket don: " << endl;
	while (p != NULL) {
		outPerDon(p);
		cout << endl;
		p = p->next;
	}
	cout << "Danh sach lien ket kep: " << endl;
	while (q != NULL) {
		outPerKep(q);
		cout << endl;
		q = q->next;
	}
}
void outPerKep(Kep* p) {
	cout << "Ma mon hoc: " << p->info.ma << endl;
	cout << "So tin chi: " << p->info.tinChi << endl;
	cout << "Ten mon hoc: " << p->info.tenMon << endl;
	cout << "Ten giang vien: " << p->info.tenGV << endl;
	cout << "Hoc ky: " << p->info.hocKi << endl;
	cout << "Trang thai: " << p->info.trangThai << endl;
}
void outPerDon(Don *p) {
	cout << "Ma mon hoc: " << p->info.ma << endl;
	cout << "So tin chi: " << p->info.tinChi << endl;
	cout << "Ten mon hoc: " << p->info.tenMon << endl;
	cout << "Ten giang vien: " << p->info.tenGV << endl;
	cout << "Hoc ky: " << p->info.hocKi << endl;
	cout << "Trang thai: " << p->info.trangThai << endl;
}
void input(string s) {
	if ((s[s.size() - 1] - '0') % 2 == 0) {
		insert_dsKep(inputKep());
	}
	else {
		insert_dsDon(inputDon());
	}
}
int insert_dsKep(Kep* p) {
	if (p == NULL) return 0;
	p->next = first;
	if (first != NULL) {
		first->pre = p;
	}
	else
		last = p;
	first = p;
	return 1;
}
int insert_dsDon(Don* p) {
	if (p == NULL) return 0;
	if (head == NULL)
		head = p;
	else {
		p->next = head;
		head = p;
	}
	return 1;
}
Kep* inputKep() {
	Kep* p = new Kep;
	int tmp;
	string status[3] = { "chua mo", "dang dien ra", "da hoan tat" };
	cout << "Nhap ma mon hoc: "; cin >> p->info.ma;
	cout << "Nhap so tin chi: "; cin >> p->info.tinChi; cin.ignore();
	cout << "Nhap ten mon hoc: "; getline(cin, p->info.tenMon);
	cout << "Nhap ten giang vien: "; getline(cin, p->info.tenGV);
	cout << "Nhap hoc ky có 3 ký tự (Ví dụ: học kỳ 3 năm học 2018-2019 được ghi lại là 183): "; cin >> p->info.hocKi;
	do {
		cout << "Nhap trang thai: " << endl;
		cout << "1, Chua mo.\n"
			<< "2, Dang dien ra.\n"
			<< "3, Da hoan tat.\n"
			<< "Ban chon: ";
		cin >> tmp;
		switch (tmp) {
		case 1:
			p->info.trangThai = status[0];
			break;
		case 2:
			p->info.trangThai = status[1];
			break;
		case 3:
			p->info.trangThai = status[2];
		default:
			break;
		}
	} while (tmp < 0 || tmp >3);
	p->next = NULL;
	p->pre = NULL;
	return p;
}
Don* inputDon() {
	Don* p = new Don;
	int tmp;
	string status[3] = { "chua mo", "dang dien ra", "da hoan tat" };
	cout << "Nhap ma mon hoc: "; cin >> p->info.ma;
	cout << "Nhap so tin chi: "; cin >> p->info.tinChi; cin.ignore();
	cout << "Nhap ten mon hoc: "; getline(cin, p->info.tenMon);
	cout << "Nhap ten giang vien: "; getline(cin, p->info.tenGV);
	cout << "Nhap hoc ky có 3 ký tự (Ví dụ: học kỳ 3 năm học 2018-2019 được ghi lại là 183): "; cin >> p->info.hocKi;
	do {
		cout << "Nhap trang thai: " << endl;
		cout << "1, Chua mo.\n"
			<< "2, Dang dien ra.\n"
			<< "3, Da hoan tat.\n"
			<< "Ban chon: ";
		cin >> tmp;
		switch (tmp) {
		case 1: 
			p->info.trangThai = status[0];
			break;
		case 2:
			p->info.trangThai = status[1];
			break;
		case 3:
			p->info.trangThai = status[2];
		default:
			break;
		}
	} while (tmp < 0 || tmp >3);
	p->next = NULL;
	return p;
}
void init() {
	head = NULL;
	first = NULL;
	last = NULL;
}