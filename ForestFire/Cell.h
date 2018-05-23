#ifndef CELL_H
#define CELL_H

class Cell //abstract class, has some methods just so that the tree methods can be accessed from referencing the array
{
protected:
	char displaySymbol;
	int x;
	int y;
public:
	Cell();
	virtual void Update();
	virtual char Display();
	virtual void Ignite();
	int GetX();
	int GetY();
};

class Tree : public Cell
{
private:
	bool isAlive;
	bool onFire;
	int life; 
public:
	Tree();
	Tree(bool p_isAlive, int p_life, int p_x, int p_y);
	void Update();// decrements life if on fire and updates display char
	bool getState();//returns if alive
	int getLife();//returns life left
	char Display();//returns display character
	void Ignite();//sets the onfire to true
};

class Border : public Cell
{
public:
	Border();
	char Display();
};

#endif