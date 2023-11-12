// TU DIEN ANH VIET
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<sstream>
#define MAX 50000
using namespace std;
struct Word {
	string anh;
	string viet;
};
struct Node {
	Word info;
	Node* next;
};
Node* first[MAX];
void init();
// ham bam
int h(Word p);
int addWord(Word w);
Node* cre(Word w);
void display();
Node* search(Word w);
int loadFile(char s[256]);
void addPer();

int main() {
	int choice;
	bool hadInit = false;
	char s[256] = "BTH4.txt";
	Word tmp;
	Node* p = NULL;
	do {
		system("cls");
		cout << "===\t TU DIEN \t===\n"
			<< "1, Khoi tao tu dien.\n"
			<< "2, Load cac tu tu file len bo nho.\n"
			<< "3, Them tu moi.\n"
			<< "4, Tim kiem mot tu.\n"
			<< "5, Xuat tu dien.\n"
			<< "6, Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice; cin.ignore();
		switch (choice) {
		case 1: // Khoi tao
			init();
			hadInit = true;
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // Load file
			if (!hadInit)
				cout << "Vui long khoi tao tu dien!" << endl;
			else {
				if (loadFile(s) == 1)
					cout << "Them thanh cong !" << endl;
				else
					cout << "Them khong thanh cong !" << endl;
			}
			break;
		case 3: // them tu moi
			if (!hadInit)
				cout << "Vui long khoi tao tu dien!" << endl;
			else {
				addPer();
			}
			break;
		case 4: // tim
			cout << "Nhap tu can tim kiem: "; getline(cin, tmp.anh);
			p = search(tmp);
			if (p != NULL)
				cout << "Nghia cua tu " << tmp.anh << ":  " << p->info.viet << endl;
			else {
				cout << "Chua xuat hien trong tu dien !" << endl;
				addWord(tmp);
			}
			break;
		case 5: 
			if (!hadInit)
				cout << "Vui long khoi tao tu dien!" << endl;
			else {
				display();
			}
			break;
		default:
			return 0;
		}
		system("pause");
	} while (true);
	return 0;
}

void addPer() {
	Word w;
	cout << "Nhap tu muon them vao tu dien: " << endl;
	cout << "Nhap tu tieng anh: "; getline(cin, w.anh);
	cout << "Nhap tu tieng viet: "; getline(cin, w.viet);
	if (addWord(w) == 1)
		cout << "Them thanh cong !" << endl;
	else {
		cout << "Them khong thanh cong !" << endl;
	}
}
int loadFile(char s[256]) {
	ifstream in;
	in.open(s, ios::in);
	if (!in.is_open()) return 0;
	int n;
	in >> n; in.ignore();
	for (int i = 0; i < n; i++) {
		Word tmp;
		string s;
		getline(in, s);
		stringstream ss(s);
		getline(ss, tmp.anh, '#');
		getline(ss, tmp.viet, '#');
		addWord(tmp);
	}
	in.close();
	return 1;
}
Node* search(Word w) {
	int index = h(w);
	Node* r = first[index];
	while (r != NULL && r->info.anh.compare(w.anh) != 0) {
		r = r->next;
	}
	return r;
}
void display() {
	for (int i = 0; i < MAX; i++) {
		if (first[i] != NULL) {
			cout << "Bucket " << i << endl;
			Node* p = first[i];
			while (p != NULL) {
				cout << p->info.anh << ":   " << p->info.viet << endl;
				p = p->next;
			}
		}
	}
}
Node* cre(Word w) {
	Node* p = new Node;
	p->info.anh = w.anh;
	p->info.viet = w.viet;
	p->next = NULL;
	return p;
}
int addWord(Word w) {
	int index = h(w);
	Node* r = first[index];
	Node* p = cre(w);
	Node* pos = search(w);
	if (pos != NULL) return 0;
	if (!r) { // them dau
		first[index] = p;
	} 
	else { // them cuoi
		if (h(w) == h(r->info))
			return 0;
		while (r->next != NULL) {
			if (h(w) == h(r->info))
				return 0;
			r = r->next;
		}
		r->next = p;
	}
	return 1;
}
int h(Word w) {
	int index = 0;
	for (int i = 0; i < w.anh.length(); i++) {
		index += (int)tolower(w.anh[i]) * (i + 1);
	}
	return index % 101;
}
void init() {
	for (int i = 0; i < MAX; i++) {
		first[i] = NULL;
	}
}