#include <iostream>
using namespace std;
class Stack
{
public:
	Stack()
	{
		x = NULL;
		x = new comp();
		x->next = NULL;
		x->prev = NULL;
	}
	Stack(const Stack& other)
	{
		int i = 0;
		comp* d = other.x;
		while (d->next) 
		{ 
			++i;
			d = d->next;//после того как вывели передвигаем b на следующий элемент(ячейку)
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
		comp* q = x;
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
			del();
		}
		comp* d = other.x;
		while (d->next)
		{
			++i;
			d = d->next;//после того как вывели передвигаем b на следующий элемент(ячейку)
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
			del();
		}
		comp* d = other.x;
		while (d->next)
		{
			++i;
			d = d->next;//после того как вывели передвигаем b на следующий элемент(ячейку)
		}
		for (int b = 0; b <= i; ++b)
		{
			push(d->Data);
			d = d->prev;
		}
		while (other.x)
		{
			other.del();
		}
	}
	friend ostream &operator<<(ostream &stream, const Stack* instance);

	struct comp
	{
		int Data;
		comp* next;
		comp* prev;
	};
	comp* x;
	void del()
	{
		comp* q = x;
		q = x->next;
		delete x;
		x = q;
	}
	void check()
	{
 		if (x->next == nullptr)
		{
			cout << "Empty Stack" << endl;
		}
	}
	void peek()
	{
		cout << x->Data << endl;
	}
	void push(int D)
	{
		comp** c = &x;
		comp* q; //Создаем новый указатель q типа структуры comp. По сути это и есть наш новый элемент
		q = new comp(); //выделяем память для нового элемента
		comp* pr = *c;
		
		q->Data = D; //Записываем необходимое число  в Data элемента
		if (*c == NULL)
		{
			*c = q; //вершиной стека будет новый элемент
		}
		else //если стек не пустой
		{
			q->next = *c; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
			pr->prev = q;
			*c = q; //Обозначаем, что вершиной теперь является новый элемент
		}
	}
private:
	
	int count = 9;
};
ostream& operator<<(ostream& str,  Stack* stack)
{
	Stack::comp *q = stack->x;
	while (q) 
	{
		str << q->Data << endl;
		q = q->next;
	}
	return str;
}