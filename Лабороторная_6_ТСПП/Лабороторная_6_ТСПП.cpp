#include <stdlib.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstring>


using namespace std;

struct info
{

};

class Kniga
{
public:
	int ID;
	char name[30];
	char author[30];
	char price[5];
	char god[8];
	int quantity;
	bool status;
	Kniga* next;
};

class Manager
{
public:
	Kniga* head, * tail;
	Kniga elem;
public:
	Manager();
	~Manager();
	Kniga* Add(const Kniga& n);
	Kniga Vvod();
	Kniga* AddFirst(const Kniga& n);
	Kniga* Delete();
	void Prosmotr();
	void Print(const Kniga& n);
	int Proverka();
	Kniga* Get_head();
	Kniga* Get_tail();
	void Add1();
	bool Checker();
};

class Librarian
{
	char FIO[30];
	char doljnost[20];
public:

	void Prinyatie();
	void Vidacha();
};

class Client : public Manager

{
public:
	char kniga_na_rukax[30];
private:
	char FIO[30];
	char tel[20];
public:
	void Searchbook(Manager& ob);
	void Getting(Manager& ob);
	void Returning();

};

void Librarian::Prinyatie()
{
	cout << "Книги приняты библиотекарем " << endl;;
}



void Librarian::Vidacha()
{
	cout << "Книги выданы библиотекарем " << endl;;
}



void Client::Getting(Manager& ob)
{
	Kniga* temp = ob.head;
	cout << "Введите книгу, которую хотите получить: ";
	cin.get(kniga_na_rukax, 30);
	cout << kniga_na_rukax << endl;
	while (temp != NULL)
	{
		if (strcmp(temp->name, kniga_na_rukax) == 0)
		{
			strcpy_s(kniga_na_rukax, temp->name);
			cout << "Книга есть в наличии." << endl; cout << "Вы ее получили " << endl;
			temp->quantity--;
			cin.get(); return;
		}

		else temp = temp->next;
	}
	cout << "Книги нет в наличии. " << endl;
	cout << kniga_na_rukax;
	cin.get();
	return;

}

void Client::Returning()
{
	strcpy_s(kniga_na_rukax, "Нет книги");
}

void Client::Searchbook(Manager& ob)
{
	Kniga* temp1 = ob.head;
	char kniga_client[30];
	int count = 0;
	if (!ob.head) { cout << "Список пуст " << endl; return; }
	cout << "Введите название книги, которую вы хотите найти: ";
	cin.get(kniga_client, 30);
	while (temp1 != NULL)
	{
		cout << temp1->name << endl;
		if (strcmp(temp1->name, kniga_client) == 0)
		{
			cout << "Книга есть в наличии."; cin.get(); return;
		}
		else temp1 = temp1->next;
	}
	cout << kniga_client << endl;
	cout << "Книги нет в наличии. " << endl;
	cin.get();
	return;
}


// конструктор по умолчанию
Manager::Manager()
{
	head = NULL;
	tail = NULL;
}




//деструктор
Manager::~Manager()
{
	Kniga* temp = head;
	while (temp != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}



Kniga* Manager::Get_head()
{
	return head;
}

Kniga* Manager::Get_tail()
{
	return tail;
}

//ввод значений
Kniga Manager::Vvod()
{
	cout << endl;
	cout << "Введите название книги : ";
	cin.getline(elem.name, 30);
	cout << "Введите автора : ";
	cin.getline(elem.author, 30);
	cout << "Введите цену : ";
	cin.getline(elem.price, 30);
	cout << "Введите год издания : ";
	cin.getline(elem.god, 8);
	cout << "Количество книг : ";
	cin >> elem.quantity;

	return elem;

}

/* проверка элементов
int Manager::Proverka()
{
	Kniga* temp1;
	int count = 0;
	if (!head) { cout << "Очередь пустая" << endl; return 0; }
	Kniga* temp = head;

	while (temp->next != NULL)
	{
		temp1 = temp;
		{ while (temp1->next != NULL) {
			if (temp1->proton == temp->proton)
				count++;
			temp1 = temp1->next;
		}

		}
		temp = temp->next;


	}
	return count;
} */

//функция добавления_1
void Manager::Add1()
{
	head = AddFirst(Vvod());
	tail = head;
}

//функция добавления
Kniga* Manager::Add(const Kniga& elem1)
{
	Kniga* newE = new Kniga;
	*newE = elem1;
	newE->next = 0;
	tail->next = newE;
	tail = newE;

	return tail;
}

//добавление первого
Kniga* Manager::AddFirst(const Kniga& elem1)
{
	Kniga* head = new Kniga;
	*head = elem1;
	head->next = 0;
	return head;
}

//печать и удаление
Kniga* Manager::Delete()
{
	Kniga* temp;
	if (!head) { cout << "Очередь пустая" << endl; return 0; }
	Print(*head);
	temp = head;
	head = head->next;
	delete temp;
	return head;
}


//печать
void Manager::Print(const Kniga& elem1)
{
	cout << endl;
	cout << "Название книги: " << elem1.name << endl;
	cout << "Автор : " << elem1.author << endl;
	cout << "Цена: " << elem1.price << endl;
	cout << "Год издания : " << elem1.god << endl;
	cout << "Количество экземпляров : " << elem1.quantity << endl;

	cout << endl << "------------------------";
}

//просмотр очереди
void Manager::Prosmotr()
{
	if (!head) { cout << "Очередь пустая" << endl; return; }
	Kniga* temp = head;
	while (temp) {
		Print(*temp);
		cout << endl;

		temp = temp->next;
	}

}


int main()
{
	setlocale(LC_ALL, "Rus");
	Manager lst;
	Client first;
	Librarian second;
	int l = 0;
	char c;
	while (1)
	{
		system("cls");
		puts("1 - Добавление записей");
		puts("2 - Печать и удаление очереди");
		puts("3 - Просмотр");
		puts("4 - Проверка на наличие книги");
		puts("5 - Получение книги читателем");
		puts("6 - Выдача книги библиотекарю ");
		puts("7 - Выход из программы");

		puts("---------------------------------------------------------------");
		puts("Введите номер пункта от 1 - 7");
		c = _getch();
		switch (c)
		{
		case '1': if (lst.Get_head()) {
			lst.Add(lst.Vvod()); break;
		}
				  else {
			lst.Add1(); break;
		}
		case '2': lst.Delete(); cin.get(); break;
		case '3': lst.Prosmotr(); cin.get(); break;
		case '4': first.Searchbook(lst); cin.get(); break;
		case '5': first.Getting(lst); second.Vidacha(); cin.get(); break;
		case '6': first.Returning(); second.Prinyatie(); cin.get(); break;
		case '7': lst.~Manager();  return 0;
			return 0;
		}
	}

}