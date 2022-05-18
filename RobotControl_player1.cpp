#include "pch.h"
#include <debugapi.h>
#include "RobotControl_player1.h"
#include <vector>

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
	int n = 0;
	vector<int> walls;

	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (info.neighbor_cells[i][j] == Cell_content::WALL || info.neighbor_cells[i][j] == Cell_content::TRAP || info.neighbor_cells[i][j] == Cell_content::ROBOT) {
				switch (i) {
				case 0:

					switch (j) {
					case 0:
						walls.push_back(0);
					case 1:
						walls.push_back(1);
					case 2:
						walls.push_back(2);
					default:
						break;
					}

				case 1:

					switch (j) {
					case 0:
						walls.push_back(3);
					case 1:
						continue;
					case 2:
						walls.push_back(4);
					default:
						break;
					}

				case 2:

					switch (j) {
					case 0:
						walls.push_back(5);
					case 1:
						walls.push_back(6);
					case 2:
						walls.push_back(7);
					default:
						break;
					}

				default:
					break;
				}
			}
		}
	}*/

	/*while (move) {
		for (int i = 0; i < walls.size(); i++) {
			if (d == walls[i])

		}
	}*/


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			if (info.neighbor_cells[i][j] == Cell_content::TREASURE) {
				switch (i) {
				case 0:

					switch (j) {
					case 0:
						dir = Dir::NW;
					case 1:
						dir = Dir::N;
					case 2:
						dir = Dir::NE;
					default:
						break;
					}

				case 1:

					switch (j) {
					case 0:
						dir = Dir::W;
					case 1:
						continue;
					case 2:
						dir = Dir::E;
					default:
						break;
					}

				case 2:

					switch (j) {
					case 0:
						dir = Dir::SW;
					case 1:
						dir = Dir::S;
					case 2:
						dir = Dir::SE;
					default:
						break;
					}

				default:
					break;
				}
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
