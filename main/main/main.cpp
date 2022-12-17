// finance
#include <iostream>
#include <string>
#include <fstream>
#include "card.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
//#include <nlohmann/json.hpp>
using namespace std;
using namespace rapidjson;
//using json = nlohmann::json;
//using namespace nlohmann::literals;

int main()
{
	int length = 3, k = 0;
	creditCard* cards = new creditCard[length];

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
		int choice = 0;
		cout << "[1] - Edit card\n"
			<< "[2] - Print card\n"
			<< "[3] - Update balance\n"
			<< "[4] - Remove from balance\n"
			<< "~# ";

		cin >> choice;

		if (choice == 1)
		{
			if (k > 3)
			{
				cout << "i can't add new card." << endl;
			}
			else
			{
				try
				{
					cards[k].edit(k);
					//doc["cards"][k]["name"].SetString(cards[k].ownerName);
					/*doc["cards"][0]["balance"].SetInt(12);
					doc["cards"][0]["balance"].SetInt(12);
					doc["cards"][0]["balance"].SetInt(12);*/
				}
				
				
				catch (exception& error)
				{
					cout << error.what() << endl;
					//break;
				}
				k++;
			}
		}
		else if (choice == 2)
		{
			int index = 0;
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
		}

	}

}

