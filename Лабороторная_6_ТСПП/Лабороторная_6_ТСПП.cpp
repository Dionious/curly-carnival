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