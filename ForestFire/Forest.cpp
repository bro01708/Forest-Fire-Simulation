#include "Forest.h"
#include <iostream>
#include <time.h>
#include <Windows.h>

Forest::Forest()
{
	//instantiates the manager
	mgr = Manager();
	//sets wind direction and speed to influence bias on ignition within a neighbourhood
	//loops through to set the object array
	SetupArray();
}

Forest::~Forest()
{
}

void Forest::SetupArray()
{
	mgr.ClearBiases();
	setwind();
	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			if (y == 0 || y == 20)//border top
			{
				forestArray[y][x] = new Border();
			}

			else if (x == 0 || x == 20)//border bottom
			{
				forestArray[y][x] = new Border();
			}

			else // all trees
			{
				forestArray[y][x] = new Tree(true, 3, x, y);
			}
		}
	}
	onFireList.clear();
	burnList.clear();
}
int Forest::GetXSize()
{
	return xSize;
}

int Forest::GetYSize()
{
	return ySize;
}

string Forest::GetDirection()
{
	return direction;
}



void Forest::BeginFire()//seeds the random to choose a random x,y coord to set on fire.
{
	srand(time(NULL));
	int x = rand() % 19 + 1;
	int y = rand() % 19 + 1;
	Ignite(x, y);
}




void Forest::Ignite(int p_x, int p_y)
{
	forestArray[p_y][p_x]->Ignite();
}

void Forest::Update()
{

	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			forestArray[y][x]->Update();
		}
	}
}

void Forest::DisplayForest()
{
	for (int y = 0; y < 21; y++)
	{
		for (int x = 0; x < 21; x++)
		{
			if (forestArray[y][x]->Display() == 'A') 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << forestArray[y][x]->Display() << ' ';
			}
			else if (forestArray[y][x]->Display() == 'X')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << forestArray[y][x]->Display() << ' ';
			}
			else if (forestArray[y][x]->Display() == '#')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << forestArray[y][x]->Display() << ' ';
			}
			else if (forestArray[y][x]->Display() == ' ')
			{
				cout << forestArray[y][x]->Display() << ' ';
			}
			
		}
		cout << endl;
	}
}

void Forest::GetNeighbours(int p_x, int p_y)
{

}

bool Forest::isFinished()
{
	if (onFireList.empty() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Forest::AdvanceFire()
{
	for each (pair<int, int> p in onFireList)
	{
		mgr.LoadNeighbourhood(p.first, p.second);
		mgr.BurnSelector();
		for each (pair<int, int> temp in mgr.GetBurnList())
		{
			burnList.push_back(temp);
		}
		
	}
	for each (pair<int, int> coord in burnList)
	{
		Ignite(coord.first, coord.second);
	}
	mgr.ClearBurnList(true);
}

void Forest::RefreshOnFireList()
{
	onFireList.clear();
	for each(Cell* c in forestArray)
	{
		if (c->Display() == 'X')
		{
			onFireList.push_back(pair<int,int>(c->GetX(), c->GetY()));
		}
	}
}

void Forest::setwind() 
{
	int x = rand() % 9;
	switch (x)
	{
	case 1:
		direction ="N";
		break;
	case 2:
		direction = "NE";
		break;
	case 3:
		direction = "E";
		break;
	case 4:
		direction = "SE";
		break;
	case 5:
		direction = "S";
		break;
	case 6:
		direction = "SW";
		break;
	case 7:
		direction = "W";
		break;
	case 8:
		direction = "NW";
		break;
	default:
		mgr.SetWindDir("none");
		break;
	}
	mgr.SetWindDir(direction);
}

