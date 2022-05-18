#include "pch.h"
#include <debugapi.h>
#include "RobotControl_player1.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace Player1;

Player1::RobotControl::RobotControl()
{
	robot_bitmap_row = 1;          // Pick a unique monster icon for your robot!
	robot_bitmap_col = 33;
	team_name = L"Legion > cataclysm";
}

Command Player1::RobotControl::do_command(const Info& info)
{
	OutputDebugString(L"Nu körs do_command()\n");
	if (info.last_event == Event::COLLISION)
		OutputDebugString(L"Krockade i förra rundan!\n");

	int d = rand() % 8;
	Dir dir = static_cast<Dir>(d);
	bool move = 1;
	int n = 1;
	vector<int> walls;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((info.neighbor_cells[i][j] == Cell_content::WALL || info.neighbor_cells[i][j] == Cell_content::TRAP) || info.neighbor_cells[i][j] == Cell_content::ROBOT) {

				if (i == 0)
				{
					switch (j)
					{
					case 0:
						walls.push_back(0);
						break;
					case 1:
						walls.push_back(1);
						break;
					case 2:
						walls.push_back(2);
						break;
					default:
						break;
					}
				}

				if (i == 1)
				{
					switch (j) {
					case 0:
						walls.push_back(3);
						break;
					case 1:
						continue;
					case 2:
						walls.push_back(4);
						break;
					default:
						break;
					}
				}

				if (i == 2)
				{
					switch (j) {
					case 0:
						walls.push_back(5);
						break;
					case 1:
						walls.push_back(6);
						break;
					case 2:
						walls.push_back(7);
						break;
					default:
						break;
					}
				}
			}
		}
	}

	/*while (move) {
		for (int i = 0; i < walls.size(); i++) {
			if (d == walls[i])
		}
	}*/


	int& targetValue = d;

	auto it = find(walls.begin(), walls.end(), targetValue);


	while (move)
	{

		for (int i = 0; i < walls.size(); i++)
		{
			if (walls[i] != d)
				n = n + 1;
		}
		if (n == walls.size())
		{
			move = false;
			switch (d)
			{
			case0:
				dir = Dir::N;
			case 1:
				dir = Dir::E;
			case 2:
				dir = Dir::S;
			case 3:
				dir = Dir::W;
			case 4:
				dir = Dir::NE;
			case 5:
				dir = Dir::SE;
			case 6:
				dir = Dir::SW;
			case 7:
				dir = Dir::NW;
			}
		}
		int d = rand() % 8;
		n = 0;
		/*if (it != walls.end())
		{
		}
		else
		{
			move = 0;
		}*/
	}

	dir = static_cast<Dir>(d);

	/*while (move)
	{
		int d = rand() % 8;
		Dir dir = static_cast<Dir>(d);
		int n = 0;
		int random_num = 1;
		int random_num1 = 1;

		for (int i = 0; i < walls.size(); i++)
		{
			if (walls[i] == d)
			{
				n = 1;
			}
		}

		if (n == 0)
		{
			move = false;
		}
	}*/



	//Kod för att hitta skatter
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if ((info.neighbor_cells[i][j]) == (Cell_content::TREASURE))
			{
				if (i == 0)
				{
					switch (j) {
					case 0:
						dir = Dir::NW;
						break;
					case 1:
						dir = Dir::N;
						break;
					case 2:
						dir = Dir::NE;
						break;
					default:
						break;
					}

				}

				else if (i == 1)
				{
					switch (j) {
					case 0:
						dir = Dir::W;
						break;;
					case 1:
						break;;
					case 2:
						dir = Dir::E;
						break;
					default:
						break;
					}
				}

				else if (i == 2)
				{
					switch (j) {
					case 0:
						dir = Dir::SW;
						break;
					case 1:
						dir = Dir::S;
						break;
					case 2:
						dir = Dir::SE;
						break;
					default:
						break;
					}
				}

				/*switch (i)
				{

				case 0:

					switch (j) {
					case 0:
						dir = Dir::NW;
						break;
					case 1:
						dir = Dir::N;
						break;
					case 2:
						dir = Dir::NE;
						break;
					default:
						break;
					}

				case 1:
					switch (j) {
					case 0:
						dir = Dir::W;
						break;;
					case 1:
						break;;
					case 2:
						dir = Dir::E;
						break;
					default:
						break;
					}

				case 2:

					switch (j) {
					case 0:
						dir = Dir::SW;
						break;
					case 1:
						dir = Dir::S;
						break;
					case 2:
						dir = Dir::SE;
						break;
					default:
						break;
					}

				default:
					break;
				}*/
			}
		}
	}

	//int d = rand() % 8;
	//dir dir = static_cast<Dir>(d);
	Action act = Action::STEP;
	if (rand() % 20 == 0)
		act = Action::PLACE_TRAP;
	return Command{ act,dir };
}