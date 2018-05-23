#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <list>

class Manager
{
private:
	int defaultChance;
	int windStrength;
	std::string windDir;
	std::pair<int, int> neighbourhood[8];
	char biases[8];
	std::list<std::pair<int, int>> burnList;

public:
	Manager();

	void LoadNeighbourhood(int p_x, int p_y);

	void BurnSelector();

	void ClearBiases();

	void SetWindDir(std::string p_windDir);

	void ClearBurnList(bool enable);

	std::list<std::pair<int, int>> GetBurnList();
};

#endif