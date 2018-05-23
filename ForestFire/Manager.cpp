#include "Manager.h"

#include <ctime>

Manager::Manager()
{
	//sets the biases to default
	ClearBiases();
	//out of 100, defualt chance sets the point the roll has to be more than.
	defaultChance = 50;
	windStrength = 20;
}

void Manager::LoadNeighbourhood(int p_x, int p_y) // Sets the coordinates of surrounding cells relative to the center coordinate.
{
	//NW
	neighbourhood[0] = std::pair<int, int>(p_x - 1, p_y - 1);
	//N
	neighbourhood[1] = std::pair<int, int>(p_x, p_y - 1);
	//NE
	neighbourhood[2] = std::pair<int, int>(p_x + 1, p_y - 1);
	//W
	neighbourhood[3] = std::pair<int, int>(p_x - 1, p_y);
	//E
	neighbourhood[4] = std::pair<int, int>(p_x + 1, p_y);
	//SW
	neighbourhood[5] = std::pair<int, int>(p_x - 1, p_y + 1);
	//S
	neighbourhood[6] = std::pair<int, int>(p_x, p_y + 1);
	//SE
	neighbourhood[7] = std::pair<int, int>(p_x + 1, p_y + 1);
}

void Manager::BurnSelector()	// '-' = less chance, '+' = more chance , '=' = no difference

{
	if (windDir == "none") //executes if no wind
	{
		for each(std::pair<int, int> neighbour in neighbourhood)
		{
			int roll = rand() % 100 + 1;
			if (roll > defaultChance)
			{
				burnList.push_back(neighbour);
			}
		}
	}

	else //calculates bias
	{
		for (int i = 0; i < 8; i++)
		{
			int roll = rand() % 100 + 1;

			if (biases[i] == '-')//opposite wind dir
			{
				if (roll >(defaultChance + (windStrength + 25)))
				{
					burnList.push_back(neighbourhood[i]);
				}
			}

			 if (biases[i] == '=')//perpendicular to fire
			{
				if (roll > (defaultChance + (windStrength + 10)))
				{
					burnList.push_back(neighbourhood[i]);
				}
			}

			 if (biases[i] == '+')//with wind dir
			{
				 if (roll > (defaultChance - (windStrength + 10)))
				 {
					 
					 burnList.push_back(neighbourhood[i]);
				 }
			}
		}
	}
}

void Manager::ClearBiases()// resets biases to default
{
	for (int i = 0; i < 8; i++)
	{
		biases[i] = '-';
	}
}

void Manager::SetWindDir( std::string p_windDir) // assigns biases based on the neighbourhood and wind strenght/direction
{
	windDir = p_windDir;
	if (windDir == "NW") { biases[0] = '+'; biases[1] = '+'; biases[3] = '+'; biases[2] = '='; biases[5] = '='; }
	if (windDir == "N") { biases[0] = '+'; biases[1] = '+'; biases[2] = '+'; biases[3] = '='; biases[4] = '='; }
	if (windDir == "NE") { biases[1] = '+'; biases[2] = '+'; biases[4] = '+'; biases[0] = '='; biases[7] = '='; }
	if (windDir == "W") { biases[5] = '+'; biases[3] = '+'; biases[0] = '+'; biases[6] = '='; biases[1] = '='; }
	if (windDir == "E") { biases[2] = '+'; biases[4] = '+'; biases[7] = '+'; biases[6] = '='; biases[1] = '='; }
	if (windDir == "SW") { biases[6] = '+'; biases[5] = '+'; biases[3] = '+'; biases[0] = '='; biases[7] = '='; }
	if (windDir == "S") { biases[7] = '+'; biases[6] = '+'; biases[5] = '+'; biases[3] = '='; biases[4] = '='; }
	if (windDir == "SE") { biases[4] = '+'; biases[7] = '+'; biases[7] = '+'; biases[5] = '='; biases[2] = '='; }
}

void Manager::ClearBurnList(bool enable) //empties the list of coords that have passed the roll test
{
	if (enable == true) burnList.clear();
}

std::list<std::pair<int, int>> Manager::GetBurnList()
{
	return burnList;
}