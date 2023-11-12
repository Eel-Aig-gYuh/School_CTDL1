// KY PHAP NGHICH DAO BALAN
#include<iostream>
#include<string>
using namespace std;
struct Queue {
	string info;
	Queue* next;
}; typedef Queue* queue;
struct Stack {
	char info;
	Stack* next;
}; typedef Stack* stack;
struct StackSo {
	int info;
	StackSo* next;
}; typedef StackSo* stackso;
void init(queue& first);
void init(stack& first);
void init(stackso& first);
Queue* cre(string x);
Stack* cre(char x);
StackSo* cre(int x);
void push(queue& first, string x);
void push(stack& first, char x);
void push(stackso& first, int x);
string top(queue first);
char top(stack first);
int top(stackso first);
void pop(queue& first);
void pop(stack& first);
void pop(stackso& first);
bool isEmpty(queue first);
bool isEmpty(stack first);
bool isEmpty(stackso first);
void calculate(stackso& first, char ite);
int proiority(char c); // do uu tien


int main() {
	queue q; init(q);
	stack st; init(st);
	string s = "5+((1+2)*4)+3";
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			string tmp = "";
			while (isdigit(s[i])) {
				tmp += s[i];
				i++;
			}
			i--;
			push(q, tmp);
		}
		else {
			if (s[i] == '(') {
				push(st, s[i]);
			}
			else if (s[i] == ')') {				
				while (top(st) != '(') {
					string tmp;
					tmp = top(st);
					push(q, tmp);
					pop(st);
				}
				pop(st);
			}
			else {
				while (!isEmpty(st) && proiority(s[i]) <= proiority(top(st))) { // do uu tien cua thang dang xet < top cua stack
					string tmp;
					tmp = top(st);
					push(q, tmp);
					pop(st);
				}
				push(st, s[i]);
			}
		}
	}
	while (!isEmpty(st)) { // neu het chuoi thi day stack chua dau vao queue
		string tmp;
		tmp = top(st);
		push(q, tmp);
		pop(st);
	}
	
	stackso so; init(so);
	while (!isEmpty(q)) {
		//cout << q->info << " ";
		if (top(q) == "+" || top(q) == "-" || top(q) == "*" || top(q) == "/" || top(q) == "%") {
			push(st, top(q)[0]);
			//cout << top(st) << endl;
			pop(q);
			if (!isEmpty(st)) {
				char dau = top(st); pop(st);
				calculate(so, dau);
			}
		}
		else {
			push(so, stoi(top(q)));
			//cout << top(so) << endl;
			pop(q);
		}
	}
	cout << "Ket qua cua phep tinh " << s << " = " << top(so) << endl;
	pop(so);
	system("pause");
	return 0;
}

void calculate(stackso& first, char ite) {
	int x, y; // x - y
	y = top(first); pop(first);
	x = top(first); pop(first);
	switch (ite) {
	case '+':
		push(first, x + y);
		break;
	case '-':
		push(first, x - y);
		break;
	case '*':
		push(first, x * y);
		break;
	case '/':
		push(first, x / y);
		break;
	default:
		break;
	}
}
int proiority(char c) {
	switch (c) {
	case '+': case '-':
		return 1;
	case '/': case '%':
		return 2;
	case '*': 
		return 3;
	default:
		return 0;
	}
} // do uu tien
bool isEmpty(stackso first) {
	return first == NULL;
}
bool isEmpty(stack first) {
	return first == NULL;
}
bool isEmpty(queue first) {
	return first == NULL;
}
void pop(stackso& first) {
	stackso p = first;
	first = first->next;
	delete p;
}
void pop(stack& first) {
	stack p = first;
	first = first->next;
	delete p;
}
void pop(queue& first) {
	queue p = first;
	first = first->next;
	delete p;
}
int top(stackso first) {
	return first->info;
}
char top(stack first) {
	return first->info;
}
string top(queue first) {
	return first->info;
}
void push(stackso& first, int x) {
	StackSo* p = cre(x);
	if (!p) return;
	p->next = first;
	first = p;
}
void push(stack& first, char x) {
	Stack* p = cre(x);
	if (!p) return;
	p->next = first;
	first = p;
}
void push(queue& first, string x) {
	Queue* p = cre(x);
	if (!p) return;
	queue q = first;
	if (!q) {
		first = p;
	}
	else {
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
	}
}
StackSo* cre(int x) {
	StackSo* p = new StackSo;
	p->info = x;
	p->next = NULL;
	return p;
}
Stack* cre(char x) {
	Stack* p = new Stack;
	p->info = x;
	p->next = NULL;
	return p;
}
Queue* cre(string x) {
	Queue* p = new Queue;
	p->info = x;
	p->next = NULL;
	return p;
}
void init(stackso& first) {
	first = NULL;
}
void init(queue& first) {
	first = NULL;
}
void init(stack& first) {
	first = NULL;
}