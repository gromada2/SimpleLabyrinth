// SimpleLabyrinth.cpp : Defines the entry point for the console application.
//

#include "map.h"
#include <iostream>

using namespace std;
int main()
{
	int SizeTyped;
	char Command;
	for(bool Continue = true;Continue == true;)
	{
		SizeTyped = 0;
		cout << "Type labyrinth size > 0";
		cout << endl;
		while(SizeTyped<1)
		{
			cin >> SizeTyped;              //Игрок вводит размер лабиринта
		}
		map *GameMap = new map(SizeTyped);
		//map GameMap(SizeTyped);            //Игрой управляет class map
		GameMap->Round();
		delete GameMap;
		cout << "try again - y, exit - n";
		cout << endl;
		for(bool i = false;i == false;)
		{
			cin >> Command;
			switch (Command)
			{
				case 'y' :
				i = true;
				break;

				case 'n' :
				i = true;
				Continue = false;
				break;
			}
		}
	}
	return 0;
}

