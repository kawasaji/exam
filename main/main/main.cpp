// finance
#include <iostream>
#include <string>
#include <fstream>

#include "card.h"
#include "spends.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;


void addSpend();
void showAll();
void bubbleSort(int* array[], int size);

int capacity = 10, current = 0;
Spends* spends_n = new Spends[capacity];
int length = 3, k = 0;
creditCard* cards = new creditCard[length];

int main()
{
	

	// JSON

	Document doc;
	fstream file("cards.json", ios::in);
	string json;

	while (!file.eof())
	{
		string tmp;
		file >> tmp;

		json += tmp;
	}

	doc.Parse(json.c_str());

	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	doc.Accept(writer);

	for (size_t i = 0; i < 3; i++)
	{
		cards[i].ownerName = doc["cards"][i]["name"].GetString();
		cards[i].ownerSurname = doc["cards"][i]["surname"].GetString();
		cards[i].cardNumber = doc["cards"][i]["cardnumber"].GetString();
		cards[i].month = doc["cards"][i]["month"].GetString();
		cards[i].year = doc["cards"][i]["year"].GetString();
		cards[i].balance = doc["cards"][i]["balance"].GetInt();
	}

	
	// JSON

	while (true)
	{
		cout << "press any key..." << endl;
		cin.ignore();
		int choice = 0, tmp_number;
		int index = 0;

		
		cout << "\n\n[1] - Edit card (does not work)\n"
			<< "[2] - Print card\n"
			<< "[3] - Update balance\n"
			<< "[4] - Add spending\n"
			<< "[5] - Show all spends\n"
			<< "[6] - Clear console"
			<< "~# ";

		enum Menu
		{
			addcard = 1,
			printcard,
			addbalance,
			addspend,
			printspend,
			clear
		};

		cin >> choice;

		switch (choice)
		{
		case Menu::addcard:
			cout << "does not work" << endl;
			break;

		case Menu::printcard:
			system("cls");
			
			for (size_t i = 0; i < length; i++)
			{
				cout << i + 1 << ": ";
				string cardNumbers = cards[i].cardNumber = doc["cards"][i]["cardnumber"].GetString();
				for (size_t j = 0; j < cardNumbers.length(); j++)
				{
					if (j % 4 == 0 && j != 0)
						cout << ' ';

					cout << cardNumbers[j];
				}
				cout << endl;
			}
			cout << endl << "enter card`s index (1|2|3)\n~# ";
			cin >> index;

			cards[index - 1].print();
			break;
		case Menu::addbalance:
			

			for (size_t i = 0; i < length; i++)
			{
				cout << i + 1 << ": ";
				string cardNumbers = cards[i].cardNumber = doc["cards"][i]["cardnumber"].GetString();
				for (size_t j = 0; j < cardNumbers.length(); j++)
				{
					if (j % 4 == 0 && j != 0)
						cout << ' ';

					cout << cardNumbers[j];
				}
				cout << endl;
			}
			cout << endl << "enter card`s index (1|2|3)\n~# ";
			cin >> index;
			system("cls");
			cout << "Enter how much you want to replenish the balance\n~# ";
			cin >> tmp_number;
			cards[index - 1].increase(tmp_number);
			break;
		case Menu::addspend:
			addSpend();
			current++;
			break;
		case Menu::printspend:
			showAll();
			break;
		case Menu::clear:
			system("cls");
			break;
		default:
			break;
		}


	}
	cards[0].print();
	addSpend();
	current++;
	addSpend();
	current++;
	addSpend();
	current++;
	showAll();

}

void addSpend()
{
	if (capacity != current)
	{
		try
		{
			if (spends_n[current].day == nullptr)
			{
				Document doc;
				fstream file("cards.json", ios::in);
				string json;

				while (!file.eof())
				{
					string tmp;
					file >> tmp;

					json += tmp;
				}

				doc.Parse(json.c_str());

				StringBuffer buffer;
				Writer<StringBuffer> writer(buffer);
				doc.Accept(writer);

				for (size_t i = 0; i < length; i++)
							{
								cout << i + 1 << ": ";
								string cardNumbers = cards[i].cardNumber = doc["cards"][i]["cardnumber"].GetString();
								for (size_t j = 0; j < cardNumbers.length(); j++)
								{
									if (j % 4 == 0 && j != 0)
										cout << ' ';

									cout << cardNumbers[j];
								}
								cout << endl;
							}
				int index_tmp;
				cout << "enter which card you want to use\n~# ";
				cin >> index_tmp;
				spends_n[current].create();
				cards[index_tmp - 1].decrease(*spends_n[current].money);
			}
			else
			{
				//cout << "false";
				throw exception("Something went wrong");
			}
		}
		catch (exception& error)
		{
			cout << error.what() << endl;
			throw error;
		}

	}

	else
	{
		capacity = capacity + capacity / 2;
		Spends* spends_tmp = new Spends[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			spends_tmp[i] = spends_n[i];
		}
		delete[] spends_n;
		spends_n = spends_tmp;

	}
}

void showAll()
{
	
				int choice = 0; 
				int total = 0;
				int* day_amount = new int[current] {};
				int* month_amount = new int[current] {};
				int* year_amount = new int[current] {};
				enum typeOfSort
				{
					standard = 1,
					day,
					month,
					year
				};

				cout << "Sort by:" << endl
					<< "[1] - standard" << endl
					<< "[2] - day" << endl
					<< "[3] - month" << endl
					<< "[4] - year" << endl;

				cin >> choice;

				switch (choice)
				{
				case typeOfSort::standard:
					
					for (size_t i = 0; i < current; i++)
					{
						cout << i + 1 << ": " << *spends_n[i].day << "." << *spends_n[i].month << "." << *spends_n[i].year << " - " << spends_n[i].name << " "
							<< *spends_n[i].money << "$" << endl;
					}
					break;
				case typeOfSort::day:
					
					cout << "Sorting by day\n\n";
					for (size_t i = 0; i < current; i++)
						day_amount[i] = *spends_n[i].day;

					bubbleSort(&day_amount, current);

					
					for (size_t i = 0; i < current; i++)
					{
						for (size_t j = 0; j < current; j++)
						{
							if (*(day_amount + i) == *spends_n[j].day)
							{
								total += *spends_n[i].money;
								cout << *spends_n[i].day << "." << *spends_n[i].month << "." << *spends_n[i].year << " - " << spends_n[i].name << " "
									<< *spends_n[i].money << "$" << endl;
							}
							else
								continue;
						}
					}
					cout << "Total: " << total;

					break;

				case typeOfSort::month:
					
					cout << "Sorting by month\n\n";
					for (size_t i = 0; i < current; i++)
						month_amount[i] = *spends_n[i].month;

					bubbleSort(&month_amount, current);


					for (size_t i = 0; i < current; i++)
					{
						for (size_t j = 0; j < current; j++)
						{
							if (*(month_amount + i) == *spends_n[j].month)
							{
								total += *spends_n[i].money;
								cout << *spends_n[i].day << "." << *spends_n[i].month << "." << *spends_n[i].year << " - " << spends_n[i].name << " "
									<< *spends_n[i].money << "$" << endl;
							}
							else
								continue;
						}
					}
					cout << "Total: " << total;

					break;
				case typeOfSort::year:
					
					cout << "Sorting by month\n\n";
					for (size_t i = 0; i < current; i++)
						year_amount[i] = *spends_n[i].year;

					bubbleSort(&year_amount, current);


					for (size_t i = 0; i < current; i++)
					{
						for (size_t j = 0; j < current; j++)
						{
							if (*(year_amount + i) == *spends_n[j].year)
							{
								total += *spends_n[i].money;
								cout << *spends_n[i].day << "." << *spends_n[i].month << "." << *spends_n[i].year << " - " << spends_n[i].name << " "
									<< *spends_n[i].money << "$" << endl;
							}
							else
								continue;
						}
					}
					cout << "Total: " << total;

					break;
				default:
					break;
				}

				
			}
		
	

void bubbleSort(int* array[], int size) {
	for (int i = 0; i < size; i++) {
		int swaps = 0;
		for (int j = 0; j < size - i - 1; j++) {
			
				if (array[j] > array[j + 1]) {
					int temp;
					temp = *array[j];
					*array[j] = *array[j + 1];
					*array[j + 1] = temp;
					swaps = 1;
				}
			
		}
		if (!swaps)
			break;
	}
}