#ifndef FOREST_H
#define FOREST_H

#include <list>
#include "Cell.h"
#include "Manager.h"

using namespace std;

class Forest
{
private:
	Cell* forestArray[21][21];
	Manager mgr;
	string direction;
	int xSize;
	int ySize;
	std::list<pair<int, int>> onFireList;
	std::list<pair<int, int>> burnList;
public:
	Forest();
	~Forest();
	void SetupArray();
	void setwind();
	int GetXSize();
	int GetYSize();
	string GetDirection();
	void Ignite(int p_x, int p_y);
	void Update();
	void DisplayForest();
	void GetNeighbours(int p_x, int p_y);
	bool isFinished();
	void AdvanceFire();
	void BeginFire();
	void RefreshOnFireList();
};

#endif