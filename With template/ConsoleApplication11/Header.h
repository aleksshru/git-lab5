#include <iostream>
using namespace std;
template<typename T>
struct comp
{
	T Data;
	comp* next;
	comp* prev;
};
template <typename T>
class Stack
{
public:
	Stack()
	{
		x = NULL;
		x = new comp<T>();
		x->next = NULL;
		x->prev = NULL;
	}
	Stack(const Stack& other)
	{
		int i = 0;
		comp<T>* d = other.x;
		while (d->next) 
		{ 
			++i;
			d = d->next;//����� ���� ��� ������ ����������� b �� ��������� �������(������)
		}
		for (int b = 0; b <= i; ++b)
		{
			push(d->Data);
			d = d->prev;
		}
	}
	Stack(Stack&& other)
	{
		x = other.x;
		other.x = NULL;
	}
	~Stack()
	{
		comp<T>* q = x;
		while (x->next)
		{
			q = x->next;
			delete x;
			x = q;
		}
		x = nullptr;
	}

	Stack& operator=(const Stack& other)
	{
		int i = 0;
		if (this == &other)
		{
			return *this;
		}
		while (x) 
		{
			Pop();
		}
		comp<T>* d = other.x;
		while (d->next)
		{
			++i;
			d = d->next;//����� ���� ��� ������ ����������� b �� ��������� �������(������)
		}
		for (int b = 0; b <= i; ++b)
		{
			push(d->Data);
			d = d->prev;
		}
	}
	
	Stack& operator=(Stack&& other)
	{
		int i = 0;
		if (this == &other)
		{
			return *this;
		}
		while (x)
		{
			Pop();
		}
		comp<T>* d = other.x;
		while (d->next)
		{
			++i;
			d = d->next;//����� ���� ��� ������ ����������� b �� ��������� �������(������)
		}
		for (int b = 0; b <= i; ++b)
		{
			push(d->Data);
			d = d->prev;
		}
		while (other.x)
		{
			other.Pop();
		}
	}
	
	template<typename T> 
	friend ostream& operator<<(ostream& stream, const Stack<T>* stack);
	
	comp<T>* x;
	T Pop()
	{
		T ret;
		comp<T>* q = x;
		ret = x->Data;
		q = x->next;
		delete x;
		x = q;
		q->prev = NULL;
		return ret;
	}
	void check()
	{
 		if (x->next == nullptr)
		{
			cout << "Empty Stack" << endl;
		}
	}
	T peek()
	{
		T ret = x->Data;
		return ret;
	}
	void push(T D)
	{
		comp<T>** c = &x;
		comp<T>* q; //������� ����� ��������� q ���� ��������� comp. �� ���� ��� � ���� ��� ����� �������
		q = new comp<T>(); //�������� ������ ��� ������ ��������
		comp<T>* pr = *c;
		
		q->Data = D; //���������� ����������� �����  � Data ��������
		if (*c == NULL)
		{
			*c = q; //�������� ����� ����� ����� �������
		}
		else //���� ���� �� ������
		{
			q->next = *c; //�������� ����� �� ������ ��������, � �������. ������ ������ ������ �� ������� ������.
			pr->prev = q;
			*c = q; //����������, ��� �������� ������ �������� ����� �������
		}
	}
private:
	
	int count = 9;
};
template<typename T>
ostream& operator<<(ostream& str,const Stack<T>* stack)
{
	comp<T> *q = stack->x;
	while (q) 
	{
		str << q->Data << endl;
		q = q->next;
	}
	return str;
}
