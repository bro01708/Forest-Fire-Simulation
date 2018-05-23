#include "Forest.h"
#include<iostream>
#include<Windows.h>

void cls() 
{
	COORD pos; 
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	Forest f = Forest();
	f.BeginFire();
	f.DisplayForest();
	f.Update();
	cout << "Wind Direction : " << f.GetDirection() << ' ' << endl;
	system("pause");
	while (true)
	{
		cls();
		f.RefreshOnFireList();
		f.AdvanceFire();
		f.Update();
		f.DisplayForest();
		cout << "Wind Direction : " << f.GetDirection() << ' ' << endl;
		system("pause");
		if (f.isFinished()) {
			f.SetupArray();
			f.BeginFire();
			f.Update();
		}
		
	}
	return 0;
}
