#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cmath>
#include <locale.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

const int N = 150; // размер строк в струтуре и макисмальнео кол-во записей в таблице

const int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // вспомогательный массив для перевода даты в дни 

struct dat { // структура даты
	int dd, dd2;
	int mm, mm2;
	int yy, yy2;
};
struct exam { // структура данных
	char name[N];
	dat date;
	dat date2;
};
struct table { // структура таблицы
	exam TBL[N];
};

int checkYear(table& people, int& i) //проверка года на высоксность
{
	if (people.TBL[i].date.yy % 4 == 0) return 1;
	return 0;
}

int checkYear2(table& people, int& i) //проверка года на высоксность
{
	if (people.TBL[i].date2.yy2 % 4 == 0) return 1;
	return 0;
}

int strCount()    // кол-во строк в файле
{
	char* str = new char[1024];
	int i = 0;
	ifstream base("table.txt");
	while (!base.eof())
	{
		base.getline(str, 1024, '\n');
		i++;
	}
	base.close();
	delete str;
	return i;
}

void loadFile(table& people, int& n) //Считывание данных из файла
{
	n = strCount();	 // подсчитываем кол-во записей 	
	ifstream file("table.txt");
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s++;
		file >> people.TBL[i].name;
		file >> people.TBL[i].date.dd;
		file >> people.TBL[i].date.mm;
		file >> people.TBL[i].date.yy;
		file >> people.TBL[i].date2.dd2;
		file >> people.TBL[i].date2.mm2;
		file >> people.TBL[i].date2.yy2;
	}
	n = s;
	file.close();
}

void SaveFile(table& people, int& n) {											//Запись данных в файл 
	ofstream file("table.txt");
	for (int i = 0; i < n; i++)
	{   
		file << people.TBL[i].name << " ";
		file << people.TBL[i].date.dd << " ";
		file << people.TBL[i].date.mm << " ";
		file << people.TBL[i].date.yy << " ";
		file << people.TBL[i].date2.dd2 << " ";
		file << people.TBL[i].date2.mm2 << " ";
		file << people.TBL[i].date2.yy2 << " ";
		file << endl;
	}
	file.close();
}

void dobavitZapis(table& people, int& n) //Добавление записи с клавиатуры
{
	system("cls");
	int a;
	cout << "Введите количество записей: ";
	cin >> a;
	system("cls");
	int flag = 0;
	int flag1 = 0;
	for (int i = n; i < a + n; i++)
	{
		cout << "Введите фамилию: ";
		cin >> people.TBL[i].name;
		cout << "Введите дату поступления: " << endl;
		cout << "Год: ";
		cin >> people.TBL[i].date.yy;
		while (flag != 1) {
			cout << "Месяц: ";
			cin >> people.TBL[i].date.mm;
			if (people.TBL[i].date.mm <= 12) flag = 1;
			else cout << "Неверный месяц" << endl;
		}
		flag = 0;
		while (flag != 1) { // Проверка правильности введеной даты (защита от выхода за границы дней и месяцев)
			cout << "День: ";
			cin >> people.TBL[i].date.dd;
			if (people.TBL[i].date.dd <= month[people.TBL[i].date.mm - 1]) flag = 1;
			if ((checkYear(people, i) == 1) && (people.TBL[i].date.mm == 2) && (people.TBL[i].date.dd <= 29)) flag = 1;
			if (flag == 0) cout << "Неверный день" << endl;
			cout << "Введите дату отчисления: " << endl;
			cout << "Год: ";
			cin >> people.TBL[i].date2.yy2;
			while (flag1 != 1) {
				cout << "Месяц: ";
				cin >> people.TBL[i].date2.mm2;
				if (people.TBL[i].date2.mm2 <= 12) flag1 = 1;
				else cout << "Неверный месяц" << endl;
			}
			flag1 = 0;
			while (flag1 != 1) { // Проверка правильности введеной даты (защита от выхода за границы дней и месяцев)
				cout << "День: ";
				cin >> people.TBL[i].date2.dd2;
				if (people.TBL[i].date2.dd2 <= month[people.TBL[i].date2.mm2 - 1]) flag1 = 1;
				if ((checkYear2(people, i) == 1) && (people.TBL[i].date2.mm2 == 2) && (people.TBL[i].date2.dd2 <= 29)) flag1 = 1;
				if (flag1 == 0) cout << "Неверный день" << endl;
			}
		}
		flag = 0;
		flag1 = 0;
	}
	n = a + n;
	cout << "Ввод выполнен успешно";
	cin.get();
	cin.get();
}

void outputALL(table& people, int& n) //Вывод на экран всех
{
	for (int i = 0; i < n; i++) {
		cout << people.TBL[i].name << " " << people.TBL[i].date.dd << "." << people.TBL[i].date.mm << "." << people.TBL[i].date.yy
			<< " " << people.TBL[i].date2.dd2 << "." << people.TBL[i].date2.mm2 << "." << people.TBL[i].date2.yy2;
		cout << endl;
	}
}

void outputONE(table& people, int& n, int i) //Вывод на экран одного
{
	cout << people.TBL[i].name << " " << people.TBL[i].date.dd << "." << people.TBL[i].date.mm << "." << people.TBL[i].date.yy 
		<< " " << people.TBL[i].date2.dd2 << "." << people.TBL[i].date2.mm2 << "." << people.TBL[i].date2.yy2;
	cout << endl;
}

void printMenu() { // главное меню
	system("cls");
	std::cout << "Программа по работе по таблице с данными:" << endl;
	std::cout << "1 - Загрузить таблицу из файла" << endl;
	std::cout << "2 - Сохранить таблицу в файл" << endl;
	std::cout << "3 - Добавить запись в таблицу" << endl;
	std::cout << "4 - Просмотреть текущую таблицы" << endl;
	std::cout << "5 - Поиск в таблице" << endl;
	std::cout << "6 - Удалить запись" << endl;
	std::cout << "7 - Редактировать запись" << endl;
	std::cout << "8 - Сортировка" << endl;
	std::cout << "0 - Выход" << endl;
}


void sortName(table& people, int& n) //Сортировка по фамилии 
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (people.TBL[i + 1].name[j] < people.TBL[i].name[j])
			{
				swap(people.TBL[i + 1], people.TBL[i]);
				i = -1;
				break;
			}
			else
				if (people.TBL[i + 1].name[j] == people.TBL[i].name[j])
					continue;
				else
					break;
		}
	}
	cout << endl;
	outputALL(people, n);
	cin.get();
	cin.get();
}
	void sortDate(table & people, int& n) //сортировка по дате поступления
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (people.TBL[i].date.yy < people.TBL[i + 1].date.yy)
			{
				swap(people.TBL[i + 1], people.TBL[i]);
				i = -1;
			}
			else
				if ((people.TBL[i].date.yy == people.TBL[i + 1].date.yy) && (people.TBL[i].date.mm < people.TBL[i + 1].date.mm))
				{
					swap(people.TBL[i + 1], people.TBL[i]);
					i = -1;
				}
				else
					if ((people.TBL[i].date.mm == people.TBL[i + 1].date.mm) && (people.TBL[i].date.dd < people.TBL[i + 1].date.dd))
					{
						swap(people.TBL[i + 1], people.TBL[i]);
						i = -1;
					}
		}
		cout << endl;
		outputALL(people, n);
		cin.get();
		cin.get();
	}

	void sortDate2(table& people, int& n) //сортировка по дате отчисления
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (people.TBL[i].date2.yy2 < people.TBL[i + 1].date2.yy2)
			{
				swap(people.TBL[i + 1], people.TBL[i]);
				i = -1;
			}
			else
				if ((people.TBL[i].date2.yy2 == people.TBL[i + 1].date2.yy2) && (people.TBL[i].date2.mm2 < people.TBL[i + 1].date2.mm2))
				{
					swap(people.TBL[i + 1], people.TBL[i]);
					i = -1;
				}
				else
					if ((people.TBL[i].date2.mm2 == people.TBL[i + 1].date2.mm2) && (people.TBL[i].date2.dd2 < people.TBL[i + 1].date2.dd2))
					{
						swap(people.TBL[i + 1], people.TBL[i]);
						i = -1;
					}
		}
		cout << endl;
		outputALL(people, n);
		cin.get();
		cin.get();
	}

	void sortMenu(table& people, int& n) { // функция управляющая сортировками 
		system("cls");
		int exit = 0;
		int item;
		cout << "1 - По фамилии" << endl;
		cout << "2 - По дате поступления" << endl;
		cout << "3 - По дате отчисления" << endl;
		cout << "0 - выход в предыдущее меню" << endl;
		while (exit != 1) {
			cin >> item;

			switch (item) {
			case 0: {
				exit = 1;
			}break;
			case 1: {
				sortName(people, n);
				cout << endl << "Для продолжения нажмите любую клавишу";
				exit = 1;
			}break;
			case 2: {
				sortDate(people, n);
				cout << endl << "Для продолжения нажмите любую клавишу";
				exit = 1;
			}
			case 3: {
				sortDate2(people, n);
				cout << endl << "Для продолжения нажмите любую клавишу";
				exit = 1;
			}
			default: break;
			}
		}
	}

	int dateDays(int dd, int mm, int yy) { // перевод полной даты в дни (нужно для функции поиска даты и наименьшой разницы)
		int days = 0;
		if ((yy) % 4 == 0) {
			for (int i = 0; i < mm - 1; i++) {
				if (i != 2)	days += month[i];
				else days += month[2] + 1;
			}
			days += yy * 365 + yy / 4 + dd;
		}
		else {
			for (int i = 0; i < mm - 1; i++) {
				days += month[i];
			}
			days += yy * 365 + yy / 4 + dd;
		}
		return days;
	}
	int dateDays2(int dd2, int mm2, int yy2) { // перевод полной даты в дни (нужно для функции поиска даты и наименьшой разницы)
		int days = 0;
		if ((yy2) % 4 == 0) {
			for (int i = 0; i < mm2 - 1; i++) {
				if (i != 2)	days += month[i];
				else days += month[2] + 1;
			}
			days += yy2 * 365 + yy2 / 4 + dd2;
		}
		else {
			for (int i = 0; i < mm2 - 1; i++) {
				days += month[i];
			}
			days += yy2 * 365 + yy2 / 4 + dd2;
		}
		return days;
	}

	void searchName(table& people, int n) {									//Поиск по фамилии

		int i, j, maxs = 0, s = 0, minr = 1000, r = 0;
		int otv = 0;
		char B[25];
		cout << "Введите фрагмент поиска: " << endl;
		cin >> B;
		for (i = 0; i < n; i++) {
			for (j = 0; B[j] != '/0' && r == 0; j++) {
				if (people.TBL[i].name[j] == B[j]) {
					s++;
				}
				else {
					r = r + abs(people.TBL[i].name[j] - B[j]);
				}
			}
			if (s > maxs) {
				otv = i;
				maxs = s;
				minr = r;
			}
			if (s == maxs) {
				if (r < minr) {
					otv = i;
					minr = r;
				}
			}
			s = 0;
			r = 0;
		}
		outputONE(people, n, otv);
	}


	void searchDate(table& people, int& n) //Поиск даты поступления
	{
		int d = 0, m = 0, y = 0;
		int dd, mm, yy;
		int max[2] = { 99999999, -1 };
		int flag = 0;
		cout << "Введите дату: " << endl;
		cout << "Год: ";
		cin >> y;
		while (flag != 1) {
			cout << "Месяц: ";
			cin >> m;
			if (m <= 12) flag = 1;
			else cout << "Неверный месяц" << endl;
		}
		flag = 0;
		while (flag != 1) { // Проверка правильности введеной даты (защита от выхода за границы дней и месяцев)
			cout << "День: ";
			cin >> d;
			if (d <= month[m - 1]) flag = 1;
			if ((y % 4 == 0) && (m == 2) && (d <= 29)) flag = 1;
			if (flag == 0) cout << "Неверный день" << endl;
		}
		flag = 0;
		for (int i = 0; i < n; i++) // ищем наименьшую разницу в днях 
			if (abs(dateDays(d, m, y) - dateDays(people.TBL[i].date.dd, people.TBL[i].date.mm, people.TBL[i].date.yy)) < max[0])
			{
				max[0] = abs(dateDays(d, m, y) - dateDays(people.TBL[i].date.dd, people.TBL[i].date.mm, people.TBL[i].date.yy));
				max[1] = i;
			}
		if (max[1] != -1)
			outputONE(people, n, max[1]);
	}

	void searchDate2(table& people, int& n) //Поиск даты отчисления
	{
		int d = 0, m = 0, y = 0;
		int dd2, mm2, yy2;
		int max[2] = { 99999999, -1 };
		int flag = 0;
		cout << "Введите дату: " << endl;
		cout << "Год: ";
		cin >> y;
		while (flag != 1) {
			cout << "Месяц: ";
			cin >> m;
			if (m <= 12) flag = 1;
			else cout << "Неверный месяц" << endl;
		}
		flag = 0;
		while (flag != 1) { // Проверка правильности введеной даты (защита от выхода за границы дней и месяцев)
			cout << "День: ";
			cin >> d;
			if (d <= month[m - 1]) flag = 1;
			if ((y % 4 == 0) && (m == 2) && (d <= 29)) flag = 1;
			if (flag == 0) cout << "Неверный день" << endl;
		}
		flag = 0;
		for (int i = 0; i < n; i++) // ищем наименьшую разницу в днях 
			if (abs(dateDays2(d, m, y) - dateDays2(people.TBL[i].date2.dd2, people.TBL[i].date2.mm2, people.TBL[i].date2.yy2)) < max[0])
			{
				max[0] = abs(dateDays2(d, m, y) - dateDays2(people.TBL[i].date2.dd2, people.TBL[i].date2.mm2, people.TBL[i].date2.yy2));
				max[1] = i;
			}
		if (max[1] != -1)
			outputONE(people, n, max[1]);
	}

	void searchMenu(table& people, int& n) { // функция управления поиском
		system("cls");
		int item;
		bool exit = false;


		while (exit != true) {
			system("cls");
			std::cout << "1 - По фамилии" << endl;
			std::cout << "2 - По дате поступления" << endl;
			std::cout << "3 - По дате отчисления" << endl;
			std::cout << "0 - Выход в предыдущее меню" << endl;

			std::cin >> item;

			switch (item) {
			case 0: {
				exit = true;
			}break;
			case 1: {
				searchName(people, n);
				std::cout << endl << "Для продолжения нажмите любую клавишу";
				_getch();
			}break;
			case 2: {
				searchDate(people, n);
				std::cout << endl << "Для продолжения нажмите любую клавишу";
				_getch();
			}break;
			case 3: {
				searchDate(people, n);
				std::cout << endl << "Для продолжения нажмите любую клавишу";
				_getch();
			}break;
			default: std::cout << "Несуществующий пункт";
			}
		}
	}

	void del(table& people, int& n) { //Удаление записи
		system("cls");
		int nom;
		cout << "Введите номер строки, которую хотите удалить" << endl;
		outputALL(people, n);
		cin >> nom;
		for (int i = nom - 1; i < n - 1; i++)
		{
			people.TBL[i] = people.TBL[i + 1];
		}
		n--;
		cout << endl;
		outputALL(people, n);
		cin.get();
		cin.get();
	}

	void redakt(table& people, int n) //Изменение таблицы
	{
		system("cls");
		int b, y;
		outputALL(people, n);
		cout << endl << "Введите номер строки, которую хотите изменить" << endl;
		cin >> b;
		b--;
		int exit = 0;

		while (exit != 1) {
			cout << "Что хотите изменить?" << endl << " 1 - Фамилию" << endl << " 2 - Дату поступления" << endl << " 3 - Дату отчисления" 
				<< endl << " 0 - выйти" << endl;
			cin >> y;
			switch (y) {
			case 1:
			{
				cout << "Введите фамилию: ";
				cin >> people.TBL[b].name;
			}
			break;
			case 2:
			{
				int flag = 0;
				cout << "Введите дату поступления: " << endl;
				cout << "Год: ";
				cin >> people.TBL[b].date.yy;
				while (flag != 1) {
					cout << "Месяц: ";
					cin >> people.TBL[b].date.mm;
					if (people.TBL[b].date.mm <= 12) flag = 1;
					else cout << "Неверный месяц" << endl;
				}
				flag = 0;
				while (flag != 1) { // Проверка правильности введеной даты (защита от выхода за границы дней и месяцев)
					cout << "День: ";
					cin >> people.TBL[b].date.dd;
					if (people.TBL[b].date.dd <= month[people.TBL[b].date.mm - 1]) flag = 1;
					if ((checkYear(people, b) == 1) && (people.TBL[b].date.mm == 2) && (people.TBL[b].date.dd <= 29)) flag = 1;
					if (flag == 0) cout << "Неверный день" << endl;
				}
				flag = 0;
			}
			break;
			case 3:
			{
				int flag = 0;
				cout << "Введите дату отчисления: " << endl;
				cout << "Год: ";
				cin >> people.TBL[b].date2.yy2;
				while (flag != 1) {
					cout << "Месяц: ";
					cin >> people.TBL[b].date2.mm2;
					if (people.TBL[b].date2.mm2 <= 12) flag = 1;
					else cout << "Неверный месяц" << endl;
				}
				flag = 0;
				while (flag != 1) { // Проверка правильности введеной даты (защита от выхода за границы дней и месяцев)
					cout << "День: ";
					cin >> people.TBL[b].date2.dd2;
					if (people.TBL[b].date2.dd2 <= month[people.TBL[b].date2.mm2 - 1]) flag = 1;
					if ((checkYear(people, b) == 1) && (people.TBL[b].date2.mm2 == 2) && (people.TBL[b].date2.dd2 <= 29)) flag = 1;
					if (flag == 0) cout << "Неверный день" << endl;
				}
				flag = 0;
			}
			break;
			case 0: exit = true; break;
			default: {
				cout << "Несуществующий пункт" << endl;
				break;
			}
			}
			cout << endl;
			outputONE(people, n, b);
			cout << endl;
		}
	}


	int main()
	{
		setlocale(0, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		table people;
		int item, n = 0;
		bool exit = false;
		while (exit != true) { //главный цикл
			printMenu();
			cin >> item;
			switch (item)
			{
			case 0: {exit = true; } break;
			case 1: {
				loadFile(people, n);
				cout << "Файл успешно загружен" << endl;
				cin.get();
				cin.get();
			}break;
			case 2: {
				SaveFile(people, n);
				cout << "Файл успешно сохранен" << endl;
				cin.get();
				cin.get();
			}break;
			case 3: {
				dobavitZapis(people, n);
			}break;
			case 4: {
				outputALL(people, n);
				cin.get();
				cin.get();
			}break;
			case 5: {
				searchMenu(people, n);
			}break;
			case 6: {
				del(people, n);
				cin.get();
				cin.get();
			}break;
			case 7: {
				redakt(people, n);
				cin.get();
				cin.get();
			}break;
			case 8: {
				sortMenu(people, n);
			}break;
			default: {
				cout << "Несуществующий пункт";
			}break;
			}
		}
	}