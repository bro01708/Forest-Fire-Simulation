#include "Cell.h"

// Cell
Cell::Cell() {}
void Cell::Update() {}
void Cell::Ignite() {}
char Cell::Display() { return displaySymbol; }
int Cell::GetX() { return x; }
int Cell::GetY() { return y; }

//Tree
Tree::Tree() {}
Tree::Tree(bool p_isAlive, int p_life, int p_x, int p_y)
{
	x = p_x;
	y = p_y;
	isAlive = p_isAlive;
	life = p_life;
	onFire = false;
	displaySymbol = 'A';
}

void Tree::Update() // decrements life if on fire and updates display char
{
	if (onFire)
	{
		life--;
		if (life == 0)
		{
			isAlive = false;
			onFire = false;
		}
	}

	if (isAlive)
	{
		if (onFire)
		{
			displaySymbol = 'X';
		}
		else 
			displaySymbol = 'A';
	}
	else
	{
		displaySymbol = ' ';
	}
}

bool Tree::getState()
{
	return isAlive;
}

int Tree::getLife()
{
	return life;
}
char Tree::Display()
{
	return displaySymbol;
}
void Tree::Ignite()
{
	onFire = true;
}

//Border
Border::Border() {}

char Border::Display()
{
	return '#';
}