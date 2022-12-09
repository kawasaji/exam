// finance
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class creditCard
{
public:
	creditCard()
	{
		system("cls");
		cout << "--- Create new card ---\n\n[1] - credit card\n[2] - debit card\n(1|2)~# ";
		cin >> typeOfCard;
		system("cls");
		cout << "--- Create new card ---\n\nenter cardholder name\n~# ";
		cin >> ownerName;
		system("cls");
		cout << "--- Create new card ---\n\nenter cardholder surname\n~# ";
		cin >> ownerSurname;
		system("cls");
		cout << "--- Create new card ---\n\nenter card`s number\n~# ";
		cin >> cardNumber;
		system("cls");
		cout << "--- Create new card ---\n\nenter month expires\n~# ";
		cin >> month;
		system("cls");
		cout << "--- Create new card ---\n\nenter year expires\n~# ";
		cin >> month;

	}

private:
	bool typeOfCard;
	string ownerName;
	string ownerSurname;
	string cardNumber;
	int month;
	int year;
};


int main()
{
	creditCard lol{};
}

