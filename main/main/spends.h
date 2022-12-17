#pragma once
#include <iostream>
#include <string>
using namespace std;


	class Spends
	{
	public:
		Spends() = default;

		void create()
		{
			int tmp_d, tmp_m, tmp_y, tmp_c;
			string tmp_s;

			cout << "enter day ~# ";
			cin >> tmp_d;
			day = new int{ tmp_d };

			cin.ignore();

			cout << "enter month ~# ";
			cin >> tmp_m;
			month = new int{ tmp_m };

			cin.ignore();

			cout << "enter year ~# ";
			cin >> tmp_y;
			year = new int{ tmp_y };

			cin.ignore();

			cout << "enter how much money you spent\n~# ";
			cin >> tmp_c;
			money = new int{ tmp_c };

			cin.ignore();

			cout << "enter what you spent the money on\n~# ";
			cin >> tmp_s;
			name = tmp_s;

			cin.ignore();
		}


		int* day = nullptr;
		int* month = nullptr;
		int* year = nullptr;

		string name;

		int* money = nullptr;
	private:


	};

	


