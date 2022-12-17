#pragma once

#include <iostream>
#include <string>
using namespace std;


class creditCard
{
public:

	creditCard() = default;

	creditCard(int typeOfCard, string ownerName, string ownerSurname, string cardNumber, string month, string year)
	{
		this->typeOfCard = typeOfCard;
		this->ownerName = ownerName;
		this->ownerSurname = ownerSurname;
		this->cardNumber = cardNumber;
		this->month = month;
		this->year = year;
	}

	void edit(int index)
	{
		try
		{
			system("cls");
			cout << "--- Edit card ---\n\n[0] - credit card\n[1] - debit card\n(0|1)~# ";
			cin >> typeOfCard;
			if (cin.fail() || cin.bad())
			{
				throw exception("incorrect input");
			}

			system("cls");
			cout << "--- Edit card ---\n\nenter cardholder name\n~# ";
			cin >> ownerName;

			system("cls");
			cout << "--- Edit card ---\n\nenter cardholder surname\n~# ";
			cin >> ownerSurname;


			system("cls");
			cout << "--- Edit card ---\n\nenter card`s number, length must be 16\n~# ";
			cin >> cardNumber;

			if (cardNumber.length() < 16 || cardNumber.length() > 16)
			{
				throw exception("length error, length must be 16");
			}
			system("cls");
			cout << "--- Edit card ---\n\nenter month expires\n~# ";
			cin >> month;
			system("cls");
			cout << "--- Edit card ---\n\nenter year expires\n~# ";
			cin >> year;

		}
		catch (exception& error)
		{
			//cout << error.what() << endl;
			throw error;
		}
	}

	void print()
	{
		system("cls");
		cout << char(218);
		for (size_t i = 0; i < 30; i++)
			cout << char(196);
		cout << char(191) << endl;
		cout << "|                              |";
		if (typeOfCard == 0)
			cout << "\tType - credit" << endl;
		
		else
			cout << "\tType - debit" << endl;
		
		cout << "| Bank of baku               " << "X" << " |" << "\t" << ownerName << endl;
		cout << "|                              |" << "\t" << ownerSurname << endl;
		cout << "|                              |" << "\tBalance - " << balance << "$" << endl;
		cout << "| ";
		for (size_t i = 0; i < cardNumber.length(); i++)
		{
			if (i % 4 == 0 && i != 0)
				cout << ' ';
		
			cout << cardNumber[i];
		}
		cout << "          |" << endl;
		cout << "| ";
		int numm;
		numm = stoi(month);
		
		if (numm < 10)
		{
			cout << "0" << month << "\\" << year;
		}
		else
		{
			cout << month << "\\" << year;
		}
		cout << "                        |" << endl;
		cout << "|                              |" << endl;
		cout << char(192);
		for (size_t i = 0; i < 30; i++)
		{
			cout << char(196);
		}
		cout << char(217) << endl;
	}

	void increase(int num)
	{
		system("cls");
		cout << "Old balance - " << balance << "$" << endl;
		this->balance += num;
		cout << "New balance - " << balance << "$" << endl;
	}

	void decrease(int num)
	{

	}
	int typeOfCard;
	string ownerName;
	string ownerSurname;
	string cardNumber;
	string month;
	string year;
	int balance = 0;
private:
	/*int typeOfCard;
	string ownerName;
	string ownerSurname;
	string cardNumber;
	string month;
	string year;
	int balance = 0;*/
};