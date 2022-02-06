
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);
	GotoXY(x, y - 5);
	cout << "  ########  ";
	GotoXY(x, y - 4);
	cout << "##        ##";
	GotoXY(x, y - 3);
	cout << "############";
	GotoXY(x, y - 2);
	cout << "#          #";
	GotoXY(x, y - 1);
	cout << "#          #";
	GotoXY(x, y);
	cout << "############";
}

void HouseBuilderA::Draw() const
{
	MyTools::SetColor(CC_Yellow);
	/*GotoXY(x, y - 5);
	cout << "  ########  ";
	GotoXY(x, y - 4);
	cout << "##        ##";
	GotoXY(x, y - 3);
	cout << "############";
	GotoXY(x, y - 2);
	cout << "#          #";
	GotoXY(x, y - 1);
	cout << "#          #";
	GotoXY(x, y);
	cout << "############";*/
	for (int i = 1; i < 7; i++) {
		GotoXY(x, y - (6 - i));
		for (int j = 1; j < 13; j++) {
			cout << look[i][j];
		}
	}
}
HouseBuilderA::HouseBuilderA() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 14; j++) {
			look[i][j] = ' ';
		}
	}

	for (int i = 1; i < 13; i++) {
		if (i > 2 && i < 11) look[1][i] = '#';
	}
	for (int i = 1; i < 13; i++) {
		if (i < 3 || i > 11) look[2][i] = '#';
	}
	for (int i = 1; i < 13; i++) {
		look[3][i] = '#';
	}
	look[4][1] = '#';
	look[4][12] = '#';
	look[5][1] = '#';
	look[5][12] = '#';
	for (int i = 1; i < 13; i++) {
		look[6][i] = '#';
	}
}