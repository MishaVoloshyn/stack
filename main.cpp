#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 5 };
	char st[FULL + 1];
	int top;

public:
	Stack();
	void Push(char c);
	char Pop();
	void Clear();
	char Top();
	bool Empty();
	bool Full();

	int GetCount();
	bool Check(Stack S, string user);
	void Show();
};


Stack::Stack()
{
	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

char Stack::Top()
{
	if (Empty()) {
		cout << "Стек пуст." << endl;
		return '\0';
	}
	return st[top];
}

bool Stack::Empty()
{
	return top == EMPTY;
}

bool Stack::Full()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}

bool Stack::Check(Stack S, string user)
{
	char c;
	for (int i = 0; i < user.length(); i++) {
		c = user[i];
		switch (c) {				
		case '(':
			S.Push(')');
			break;
		case '{':
			S.Push('}');
			break;
		case '[':
			S.Push(']');
			break;

		case ')':
			if (S.Empty() || S.Top() != c)			
			{
				cout << "error";						
				return false;
			}
			S.Pop();									
			break;

		case '}':
			if (S.Empty() || S.Top() != c)
			{
				cout << "error";
				return false;
			}
			S.Pop();
			break;
		case ']':
			if (S.Empty() || S.Top() != c)
			{
				cout << "error";
				return false;
			}
			S.Pop();
			break;
		}
	}
	cout << "All is correct!" << endl;
	return true;
}

void Stack::Show()
{
	for (int i = 0; i < GetCount(); i++) {
		cout << st[i] << ' ';
	}
}

void Stack::Push(char c)
{
	if (!Full()) {
		st[++top] = c;
	}
	else {
		cout << "Стек переполнен." << endl;
	}
}

char Stack::Pop()
{
	if (!Empty()) {
		return st[top--];
	}
	else {
		cout << "Стек пуст." << endl;
		return '\0';
	}
}


int main()
{
	srand(time(0));
	Stack S;
	string user;					
	cout << "Enter string: ";
	getline(cin, user);
	S.Check(S, user);

}