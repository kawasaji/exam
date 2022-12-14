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

	/*fstream file("notes.json");
	json data = json::parse(file);*/

	/*json ex3 = {
		{"happy", true},
		{"pi", 3.141},
	};*/

	/*Document doc;
	fstream file("data.json", ios::in);
	string json;*/

	

	int length = 3, k = 0;
	creditCard* cards = new creditCard[length];

	// JSON

	Document doc;
	fstream file("notes.json", ios::in);
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

	//cards[0].age = doc["age"].GetInt();
	cards[0].ownerName = doc["name"].GetString();
	cards[0].ownerSurname = doc["surname"].GetString();

	// JSON


	while (true)
	{
		cout << "press any key..." << endl;
		cin.ignore();
		int choice = 0;
		cout << "[1] - Add new card\n"
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
					cards[k].create();
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
			cout << "enter card`s index (1|2|3)\n~# ";
			cin >> index;
			cards[index].print();
		}

	}

}

