


#include "map.h"
#include<time.h>
using namespace std;
map::map(int SizeTyped)
{
	Size=SizeTyped;
	FullSize = Size + 2;                      // Размер включая стенки
	MapInfo.resize(FullSize);
	for (int i = 0; i < FullSize; ++i)
	{
		MapInfo[i].resize(FullSize);
	}

	GenerateMap();



}


map::~map(void)
{
}


	void map::DrawMap()                   //Отрисовка поля
	{
		for(int x = 0; x < FullSize; x++)
		{
			for (int y = 0; y < FullSize; y++)
			{
				cout << MapInfo[y][x];
			}
			cout << endl;
		}
	}




void map::Round()        //Упраляющий метод игры
{
	cout << "Movement : w - up, s - down, a - left, d - right";
	cout << endl;
	cout << "Make your way to the right side";
	cout << endl;
	DrawMap();
	while (XCor < Size)
	{
		PlayerMovement();
		DrawMap();
	}
	cout << "You win";
	cout << endl;
}


void map::PlayerMovement()                     // Движение на одну клетку 
{
	MapInfo[XCor][YCor] = 'O';
	for(bool i = false; i == false;)
	{
		cin >> Command;
		switch ( Command )
		{
			case 'w':
			YCor--;
			if (CheckIfWall() == true)
			{
			i = true;
			}
			else
			{
				YCor++;
			}
			break;

			case 's':
			YCor++;
			if (CheckIfWall() == true)
			{
				i = true;
			}
			else
			{
				YCor--;
			}
			break;

			case 'd':
			XCor++;
			if (CheckIfWall() == true)
			{
				i = true;
			}
			else
			{
				XCor--;
			}
			break;

			case 'a':
			XCor--;
			if (CheckIfWall() == true)
			{
				i = true;
			}
			else
			{
				XCor++;
			}
			break;


		}



	}
	MapInfo[XCor][YCor] = 'P';

}

bool map::CheckIfWall()                        //  Проверка на возможность движения 
{
	if (MapInfo[XCor][YCor] == '#')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void map::GenerateMap()                       //Генерация поля
{
	//srand(time(NULL));
	srand(static_cast<unsigned int>(time(0)));

	for(int Border = 0;Border < FullSize;Border++)               //Стенки поля
	{
		MapInfo[Border][0] = '#';
		MapInfo[Border][Size + 1] = '#';
		MapInfo[0][Border] = '#';
		MapInfo[Size + 1][Border] = '#';
	}

	XCor = 1;                                                       //Координаты игрока
	YCor = 1;
	MapInfo[XCor][YCor] = 'P';



	for (int y = 2; y < Size + 1; y++)                                 //Первый столбец лабиринта без стен
	{
		MapInfo[1][y] = 'O'; 
	}

	for(int x = 2; x < Size + 1; x++)
	{
		PathExist = false;
		for (int y = 1; y < Size + 1; y++)
		{

			if(MapInfo[x - 1][y] == 'O')                                   // Если есть путь, есть шанс его продолжить
			{
				Command = rand() % 100 + 1;
				if (Command > 15)
				{

					MapInfo[x][y] = 'O';

					if (MapInfo[x][y + 1] != '#')
					{
						MapInfo[x][y + 1] = 'O';
					}


					PathExist = true;                           // Нужно убедиться, что хотя бы один путь существует
				}
				else
				{
					MapInfo[x][y] = '#';
				}
			}
			else if (MapInfo[x][y] != 'O')
			{
				MapInfo[x][y] = '#';
			}



		}


			if (PathExist == false)
			{
				for (int y = 1; y < Size + 1; y++)
				{
					MapInfo[x][y] = 'X';                         //Временный символ
				}
				x--;                                             //Генерируем еще раз 
			}
		
	}




}



