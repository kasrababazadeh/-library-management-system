#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctime>

using namespace std;

void regist();
void login();
void library();
void SBWN();
void SBWW();
void SBWB();
void editBook();
void lendBook();
void report();
void SBD();
void SLB();
void STB();
void SBB();
void SBSN();

struct members
{
	string name;
	string lastName;
	int stn;
	string nNum;
};

struct books
{
	string name;
	string writter;
	int publication;
	int barcode;
};

void main()
{
	system("color 8e");
	char n;
	cout << "\n\t\t\t\t\t Welcome To Library Management System\n\n" << endl;
	do
	{
	cout << "\t\t\t\t1.Login\t\t\t\t\t\t2.Regist" << endl;
	cin >> n;
	switch (n)
	{
	case '1':
		login();
		break;
	case '2':
		regist();
		break;
	}
	}
	while (n!='1' || n!='2');
	cin.get();
	cin.ignore();
}
void regist()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t\t** Regist **\n\n";
	members M;
	ofstream Members;
	Members.open("D:\\project c++\\library management\\members.dat", ios::app);
	cout << "\t\t\t\t\t       You Aren`t Member Please Regist\n" << endl;
	cout << "\tEnter Your Name : ";
	cin >> M.name;
	cout << "\n\tEnter Your Last Name : ";
	cin >> M.lastName;
	cout << "\n\tEnter Your Student Number : ";
	cin >> M.stn;
	cout << "\n\tEnter Your National Number : ";
	cin >> M.nNum;
	Members << M.name << endl;
	Members << M.lastName << endl;
	Members << M.stn << endl;
	Members << M.nNum << endl;
	Members.close();
		library();
	cin.get();
	cin.ignore();
}
void login()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t\t** Login **\n\n";
	members m, M;
	ifstream Members;
	Members.open("D:\\project c++\\library management\\members.dat", ios::app);
	cout << "\tEnter Your Name : ";
	cin >> m.name;
	cout << "\n\tEnter Your Student Number : ";
	cin >> m.stn;
	while (!Members.eof())
	{
		Members >> M.name;
		Members >> M.lastName;
		Members >> M.stn;
		Members >> M.nNum;
		if (m.name == M.name && m.stn == M.stn)
			library();
	}
	Members.close();
	regist();
	cin.get();
	cin.ignore();
}
void addBook()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t\t** Add Book **";
	int number = 1;
	books B;
	cout << "\n\n\tEnter Your Book`s Name : ";
	cin >> B.name;
	cout << "\n\tEnter Your Book`s Writter : ";
	cin >> B.writter;
	cout << "\n\tEnter Your Book`s Publication`s Year : ";
	cin >> B.publication;
	cout << "\n\tEnter Your Book`s Bar Code : ";
	cin >> B.barcode;
	string bname, bwritter;
	int bpublication, bbarcode;
	fstream f1, f2;
	f1.open("D:\\project c++\\library management\\Books.dat", ios::in);
	f2.open("D:\\project c++\\library management\\Temp.dat", ios::app);
	while (f1 >> bname >> bwritter >> bpublication >> bbarcode >> number)
	{
		f1 >> bname;
		f1 >> bwritter;
		f1 >> bpublication;
		f1 >> bbarcode;
		f1 >> number;
		if (bname == B.name && bwritter == B.writter && bpublication == B.publication && bbarcode == B.barcode)
		{
			number = number + 1;
			f2 << bname << endl;
			f2 << bwritter << endl;
			f2 << bpublication << endl;
			f2 << bbarcode << endl;
			f2 << number << endl;
			number = number - 1;
		}
		else
		{
			f2 << bname << endl;
			f2 << bwritter << endl;
			f2 << bpublication << endl;
			f2 << bbarcode << endl;
			f2 << number << endl;
		}
	}
	if (bname != B.name && bwritter != B.writter && bpublication != B.publication && bbarcode != B.barcode)
	{
		f2 << B.name << endl;
		f2 << B.writter << endl;
		f2 << B.publication << endl;
		f2 << B.barcode << endl;
		f2 << number << endl;
	}
	f1.close();
	f2.close();
	f2.open("D:\\project c++\\library management\\Temp.dat", ios::in);
	f1.open("D:\\project c++\\library management\\Books.dat", ios::out);
	while (f2 >> bname >> bwritter >> bpublication >> bbarcode >> number)
	{
		f2 >> bname;
		f2 >> bwritter;
		f2 >> bpublication;
		f2 >> bbarcode;
		f2 >> number;
		f1 << bname << endl;
		f1 << bwritter << endl;
		f1 << bpublication << endl;
		f1 << bbarcode << endl;
		f1 << number << endl;
	}
	f2.close();
	f1.close();
	library();
	cin.get();
	cin.ignore();
}
void searchBook()
{
	system("color 8e");
	system("cls");
	cout << "\n\n\t\t\t\t\t\t** Search Book **\n";
	char n;
	cout << "\n\tHow You Want To Search For Your Book : " << endl;
	cout << "\n\t1.With Name\n\n\t2.With Writter\n\n\t3.With Bar Code" << endl;
	cin >> n;
	switch (n)
	{
	case '1':
		SBWN();
		break;
	case '2':
		SBWW();
		break;
	case '3':
		SBWB();
		break;
	default:
		break;
	}
	library();
	cin.get();
	cin.ignore();
}
void SBWN()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t** Search Book With Name **\n";
	int number;
	char s;
	string name;
	books B;
	ifstream Books;
	Books.open("D:\\project c++\\library management\\Books.dat", ios::app);
	cout << "\n\tEnter Your Book`s Name : ";
	cin >> name;
	while (!Books.eof())
	{
		Books >> B.name;
		Books >> B.writter;
		Books >> B.publication;
		Books >> B.barcode;
		Books >> number;
		if (B.name == name)
		{
			cout << "\n\tYour Book`s Name Is : " << B.name << endl;
			cout << "\n\tYour Book`s Writter Is : " << B.writter << endl;
			cout << "\n\tYour Book`s Publication Year Is : " << B.publication << endl;
			cout << "\n\tYour Book`s Bar Code Is : " << B.barcode << endl;
			cout << "\n\tNumber Of This Book Is : " << number << endl;
			cout << "\n\t1.Go Back To Library\n\n\t2.Exit" << endl;
			cin >> s;
			switch (s)
			{
			case '1':
				library();
				break;
			case '2':
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	Books.close();
	cin.get();
	cin.ignore();
}
void SBWW()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t** Search Book With Writter **\n";
	int number;
	char s;
	string writter;
	books B;
	ifstream Books;
	Books.open("D:\\project c++\\library management\\Books.dat", ios::app);
	cout << "\n\tEnter Your Book`s Writter : ";
	cin >> writter;
	while (!Books.eof())
	{
		Books >> B.name;
		Books >> B.writter;
		Books >> B.publication;
		Books >> B.barcode;
		Books >> number;
		if (B.writter == writter)
		{
			cout << "\n\tYour Book`s Name Is : " << B.name << endl;
			cout << "\n\tYour Book`s Writter Is : " << B.writter << endl;
			cout << "\n\tYour Book`s Publication Year Is : " << B.publication << endl;
			cout << "\n\tYour Book`s Bar Code Is : " << B.barcode << endl;
			cout << "\n\tNumber Of This Book Is : " << number << endl;
			cout << "\n\t1.Go Back To Library\n\n\t2.Exit" << endl;
			cin >> s;
			switch (s)
			{
			case '1':
				library();
				break;
			case '2':
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	Books.close();
	cin.get();
	cin.ignore();
}
void SBWB()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t** Search Book With Bar Code **\n";
	int number;
	char s;
	int barcode;
	books B;
	ifstream Books;
	Books.open("D:\\project c++\\library management\\Books.dat", ios::app);
	cout << "\n\tEnter Your Book`s Bar Code : ";
	cin >> barcode;
	while (!Books.eof())
	{
		Books >> B.name;
		Books >> B.writter;
		Books >> B.publication;
		Books >> B.barcode;
		Books >> number;
		if (B.barcode == barcode)
		{
			cout << "\n\tYour Book`s Name Is : " << B.name << endl;
			cout << "\n\tYour Book`s Writter Is : " << B.writter << endl;
			cout << "\n\tYour Book`s Publication Year Is : " << B.publication << endl;
			cout << "\n\tYour Book`s Bar Code Is : " << B.barcode << endl;
			cout << "\n\tNumber Of This Book Is : " << number << endl;
			cout << "\n\t1.Go Back To Library\n\n\t2.Exit" << endl;
			cin >> s;
			switch (s)
			{
			case '1':
				library();
				break;
			case '2':
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	Books.close();
	cin.get();
	cin.ignore();
}
void searchMember()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t   ** Search Member **\n";
	string name;
	char s;
	members M;
	ifstream Members;
	Members.open("D:\\project c++\\library management\\members.dat", ios::app);
	cout << "\n\tEnter The Name : ";
	cin >> name;
	while (!Members.eof())
	{
		Members >> M.name;
		Members >> M.lastName;
		Members >> M.stn;
		Members >> M.nNum;
		if (name == M.name)
		{
			cout << "\n\tStudent Name : " << M.name << endl;
			cout << "\n\tStudent Last Name : " << M.lastName << endl;
			cout << "\n\tStudent Number : " << M.stn << endl;
			cout << "\n\tStudent Natoinal Number : " << M.nNum << endl;
			cout << "\n\t1.Go Back To Library\n\n\t2.Exit" << endl;
			cin >> s;
			switch (s)
			{
			case '1':
				library();
				break;
			case '2':
				exit(0);
				break;
			default:
				break;
			}
		}
	}
	Members.close();
	cin.get();
	cin.ignore();
}
void editBook()
{
	system("cls");
	system("color 8e");
	char n;
	cout << "\n\n\t\t\t\t\t\t\t** Edit Book **\n";
	int barcode, number;
	cout << "\n\tEnter The Book`s Bar Code : ";
	cin >> barcode;
	books B;
	fstream f1, f2;
	f1.open("D:\\project c++\\library management\\Books.dat", ios::in);
	f2.open("D:\\project c++\\library management\\Temp.dat", ios::app);
	while (f1 >> B.name >> B.writter >> B.publication >> B.barcode >> number)
	{
		f1 >> B.name;
		f1 >> B.writter;
		f1 >> B.publication;
		f1 >> B.barcode;
		f1 >> number;
		if (B.barcode == barcode)
		{
			cout << "\n\tEnter Your Book`s Name : ";
			cin >> B.name;
			cout << "\n\tEnter Your Book`s Writter : ";
			cin >> B.writter;
			cout << "\n\tEnter Your Book`s Publication`s Year : ";
			cin >> B.publication;
			cout << "\n\tEnter Your Book`s Bar Code : ";
			cin >> B.barcode;
		}
		f2 << B.name << endl;
		f2 << B.writter << endl;
		f2 << B.publication << endl;
		f2 << B.barcode << endl;
		f2 << number << endl;
	}
	f1.close();
	f2.close();
	f2.open("D:\\project c++\\library management\\Temp.dat", ios::in);
	f1.open("D:\\project c++\\library management\\Books.dat", ios::out);
	while (f2 >> B.name >> B.writter >> B.publication >> B.barcode >> number)
	{
		f2 >> B.name;
		f2 >> B.writter;
		f2 >> B.publication;
		f2 >> B.barcode;
		f2 >> number;
		f1 << B.name << endl;
		f1 << B.writter << endl;
		f1 << B.publication << endl;
		f1 << B.barcode << endl;
		f1 << number << endl;
	}
	f2.close();
	f1.close();
	cout << "\n\n\t1.Go Back To Library\n\n\t2.Exit\n";
	cin >> n;
	switch (n)
	{
	case '1':
		library();
		break;
	case '2':
		exit(0);
		break;
	default:
		exit(0);
		break;
	}
	cin.get();
	cin.ignore();
}
void lendBook()
{
	system("cls");
	system("color 8e");
	cout << "\n\n\t\t\t\t\t\t\t** Lend Book **\n";
	int year, month, day;
	books b,B;
	int number,stn,barcode;
	cout << "\n\tEnter Book`s Name : ";
	cin >> B.name;
	fstream f1, f2, f3;
	f1.open("D:\\project c++\\library management\\Books.dat", ios::in);
	f2.open("D:\\project c++\\library management\\Temp.dat", ios::app);
	while (f1 >> b.name >> b.writter >> b.publication >> b.barcode >> number)
	{
		f1 >> b.name;
		f1 >> b.writter;
		f1 >> b.publication;
		f1 >> b.barcode;
		f1 >> number;
		if (b.name == B.name)
		{
			number = number - 1;
			f2 << b.name << endl;
			f2 << b.writter << endl;
			f2 << b.publication << endl;
			f2 << b.barcode << endl;
			f2 << number << endl;
			barcode = b.barcode;
			number = number + 1;
		}
		else
		{
			f2 << b.name << endl;
			f2 << b.writter << endl;
			f2 << b.publication << endl;
			f2 << b.barcode << endl;
			f2 << number << endl;
		}
	}
	f1.close();
	f2.close();
	f2.open("D:\\project c++\\library management\\Temp.dat", ios::in);
	f1.open("D:\\project c++\\library management\\Books.dat", ios::out);
	while (f2 >> b.name >> b.writter >> b.publication >> b.barcode >> number)
	{
		f2 >> b.name;
		f2 >> b.writter;
		f2 >> b.publication;
		f2 >> b.barcode;
		f2 >> number;
		f1 << b.name << endl;
		f1 << b.writter << endl;
		f1 << b.publication << endl;
		f1 << b.barcode << endl;
		f1 << number << endl;
	}
	f2.close();
	f1.close();
	f3.open("D:\\project c++\\library management\\Lend Books.dat", ios::app);
	cout << "\n\tEnter Your Student Number : ";
	cin >> stn;
	cout << "\n\tEnter Year : ";
	cin >> year;
	cout << "\n\tEnter Month : ";
	cin >> month;
	cout << "\n\tEnter Day : ";
	cin >> day;
	f3 << barcode << endl;
	f3 << stn << endl;
	f3 << year << "/";
	f3 << month << "/";
	f3 << day << endl;
	f3 << year << "/";
	f3 << month << "/";
	f3 << day + 7 << endl;
	library();
	cin.get();
	cin.ignore();
}
void SBD()
{
	system("cls");
	char n;
	cout << "\n\n\t\t\t\t\t\t** Search By Date **\n";
	cout << "\n\t1.Show Lend Books\n\n\t2.Show Return Books";
	cin >> n;
	switch (n)
	{
	case '1':
		SLB();
		break;
	case '2':
		STB();
		break;
	default:
		break;
	}
	cin.get();
	cin.ignore();
}
void SLB()
{
	system("cls");
	int barcode, stn, number, publication, Barcode, stno;
	string date, date1, date2, name, writter, Name, lastname, national;
	char n;
	string r1, r2, r3, r4;
	cout << "\n\n\t\t\t\t\t\t** Show Lend Book By Date **";
	cout << "\n\tEnter Date(year/month/day) : ";
	cin >> date;
	fstream f1, f2, f3;
	f1.open("D:\\project c++\\library management\\Lend Books.dat", ios::in);
	while (!f1.eof())
	{
		f1 >> barcode;
		f1 >> stn;
		f1 >> date1;
		f1 >> date2;
		if (date == date1)
		{
			r1 = date1;
			f2.open("D:\\project c++\\library management\\Books.dat", ios::in);
			while (!f2.eof())
			{
				f2 >> name;
				f2 >> writter;
				f2 >> publication;
				f2 >> Barcode;
				f2 >> number;
				if (barcode == Barcode)
				{
					r2 = name;
					f3.open("D:\\project c++\\library management\\members.dat", ios::in);
					while (!f3.eof())
					{
						f3 >> Name;
						f3 >> lastname;
						f3 >> stno;
						f3 >> national;
						if (stn == stno)
						{
							r3 = Name;
							r4 = lastname;
							cout << "\n\t" << r2 << " Lent By " << r3 << " " << r4 << " In " << r1;
							cout << "\n\n\t1.Go Back To Library\n\n\t2.Exit\n";
							cin >> n;
							switch (n)
							{
							case '1':
								library();
								break;
							case '2':
								exit(0);
								break;
							default:
								exit(0);
								break;
							}
						}
					}
					f3.close();
				}
			}
			f2.close();
		}
	}
	f1.close();
	cin.get();
	cin.ignore();
}
void STB()
{
	system("cls");
	int barcode, stn, number, publication, Barcode, stno;
	string date, date1, date2, name, writter, Name, lastname, national;
	char n;
	string r1, r2, r3, r4;
	cout << "\n\n\t\t\t\t\t\t** Show Lend Book By Date **";
	cout << "\n\tEnter Date(year/month/day) : ";
	cin >> date;
	fstream f1, f2, f3;
	f1.open("D:\\project c++\\library management\\Lend Books.dat", ios::in);
	while (!f1.eof())
	{
		f1 >> barcode;
		f1 >> stn;
		f1 >> date1;
		f1 >> date2;
		if (date == date2)
		{
			r1 = date2;
			f2.open("D:\\project c++\\library management\\Books.dat", ios::in);
			while (!f2.eof())
			{
				f2 >> name;
				f2 >> writter;
				f2 >> publication;
				f2 >> Barcode;
				f2 >> number;
				if (barcode == Barcode)
				{
					r2 = name;
					f3.open("D:\\project c++\\library management\\members.dat", ios::in);
					while (!f3.eof())
					{
						f3 >> Name;
						f3 >> lastname;
						f3 >> stno;
						f3 >> national;
						if (stn == stno)
						{
							r3 = Name;
							r4 = lastname;
							cout << "\n\t" << r2 << " Should Return By " << r3 << " " << r4 << " In " << r1;
							cout << "\n\n\t1.Go Back To Library\n\n\t2.Exit\n";
							cin >> n;
							switch (n)
							{
							case '1':
								library();
								break;
							case '2':
								exit(0);
								break;
							default:
								exit(0);
								break;
							}
						}
					}
					f3.close();
				}
			}
			f2.close();
		}
	}
	f1.close();
	cin.get();
	cin.ignore();
}
void SBB()
{
	system("cls");
	int barcode, code, stn, stno;
	string date1, date2, name, lastname, national;
	char n;
	cout << "\n\n\t\t\t\t\t\t** Report By Bar Code **\n";
	cout << "\n\tEnter Book`s Bar Code : ";
	cin >> barcode;
	fstream f1,f2;
	f1.open("D:\\project c++\\library management\\Lend Books.dat", ios::in);
	while (!f1.eof())
	{
		f1 >> code;
		f1 >> stn;
		f1 >> date1;
		f1 >> date2;
		if (code == barcode)
		{
			f2.open("D:\\project c++\\library management\\members.dat", ios::in);
			while (!f2.eof())
			{
				f2 >> name;
				f2 >> lastname;
				f2 >> stno;
				f2 >> national;
				if (stn == stno)
				{
					cout << "\t" << name << " " << lastname <<" Lent This Book\n";
					cout << "\n\t1.Go Back To Library\n\t2.Exit";
					cin >> n;
					switch (n)
					{
					case '1':
						library();
						break;
					case '2':
						exit(0);
						break;
					default:
						exit(0);
						break;
					}
				}
			}
			f2.close();
		}
	}
	f1.close();
	cin.get();
	cin.ignore();
}
void SBSN()
{
	system("cls");
	int stn, stno, date, Barcode, number, barcode;
	string date1, date2, name, writter;
	char n;
	cout << "\n\n\t\t\t\t\t\t** Report By Student Number **\n";
	cout << "\n\tEnter Your Student Number : ";
	cin >> stn;
	fstream f1, f2;
	f1.open("D:\\project c++\\library management\\Lend Books.dat", ios::in);
	while (!f1.eof())
	{
		f1 >> barcode;
		f1 >> stno;
		f1 >> date1;
		f1 >> date2;
		if (stn == stno)
		{
			f2.open("D:\\project c++\\library management\\Books.dat", ios::in);
			while (!f2.eof())
			{
				f2 >> name;
				f2 >> writter;
				f2 >> date;
				f2 >> Barcode;
				f2 >> number;
				if (Barcode == barcode)
				{
					cout << "\n\tLent " << name << " In " << date1;
					cout << "\n\n\t1.Go Back To Library\n\t2.Exit\n";
					cin >> n;
					switch (n)
					{
					case '1':
						library();
						break;
					case '2':
						exit(0);
						break;
					default:
						exit(0);
						break;
					}
				}
			}
			f2.close();
		}
	}
	f1.close();
	cin.get();
	cin.ignore();
}
void report()
{
	system("cls");
	system("color 8e");
	char n;
	cout << "\n\n\t\t\t\t\t\t\t** Report **\n";
	cout << "\n\t1.By Date\n\n\t2.By Bar Code\n\n\t3.By Student Number\n";
	cin >> n;
	switch (n)
	{
	case '1':
		SBD();
		break;
	case '2':
		SBB();
		break;
	case '3':
		SBSN();
		break;
	default:
		break;
	}
	cin.get();
	cin.ignore();
}
void library()
{
	system("cls");
	system("color 8e");
	char n;
	cout << "\n\n\t\t\t\t\t\t** Welcome To Library **\n" << endl;
	cout << "\n\tWhat You Want To Do : " << endl;
	cout << "\n\t1.Add Book\n\n\t2.Lend Book\n\n\t3.Search Book\n\n\t4.Search Members\n\n\t5.Edit Book\n\n\t6.Report" << endl;
	cin >> n;
	switch (n)
	{
	case '1':
		addBook();
		break;
	case '2':
		lendBook();
		break;
	case '3':
		searchBook();
		break;
	case '4':
		searchMember();
		break;
	case '5':
		editBook();
		break;
	case '6':
		report();
		break;
	default:
		exit(0);
		break;
	}
	cin.get();
	cin.ignore();
}

