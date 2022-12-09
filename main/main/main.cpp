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
		try
		{
			system("cls");
			cout << "--- Create new card ---\n\n[0] - credit card\n[1] - debit card\n(0|1)~# ";
			cin >> typeOfCard;
	

			system("cls");
			cout << "--- Create new card ---\n\nenter cardholder name\n~# ";
			cin >> ownerName;
			

			system("cls");
			cout << "--- Create new card ---\n\nenter cardholder surname\n~# ";
			cin >> ownerSurname;


			system("cls");
			cout << "--- Create new card ---\n\nenter card`s number, length must be 16\n~# ";
			cin >> cardNumber;

			if (cardNumber.length() < 16 || cardNumber.length() > 16)
			{
				throw exception("length error, length must be 16");
			}
			system("cls");
			cout << "--- Create new card ---\n\nenter month expires\n~# ";
			cin >> month;
			system("cls");
			cout << "--- Create new card ---\n\nenter year expires\n~# ";
			cin >> month;
		}
		catch (exception& error)
		{
			cout << error.what() << endl;
		}
		

	}

	void print()
	{
		system("cls");
		cout << char(218);
		for (size_t i = 0; i < 30; i++)
		{
			cout << char(196);
		} 
		cout << char(191) << endl;
		cout << "|                              |" << endl;
		cout << "| Bank of baku               " << "•" << " |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "| ";
		for (size_t i = 0; i < cardNumber.length(); i++)
		{
			if (i % 4 == 0 && i != 0)
			{
				cout << ' ';
			}
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
	}	

private:
	bool typeOfCard;
	string ownerName;
	string ownerSurname;
	string cardNumber;
	string month;
	string year;
};


int main()
{

	int length = 10, k = 0;

	creditCard lol{};

	lol.print();

}

