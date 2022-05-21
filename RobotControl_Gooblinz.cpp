#include "pch.h"
#include <debugapi.h>
#include "RobotControl_Gooblinz.h"
#include <vector>
#include <algorithm>

/*MEDLEMMAR:   Filip Karlsson Dahlgren
               Nils Wikström
               Marcus Bohm
*/


using namespace std;
using namespace Gooblinz;
Dir lastround, lastlastround;
int rundor = 1;
int banana = -5;
int lastbanana = -5;

Gooblinz::RobotControl::RobotControl()
{
	robot_bitmap_row = 1;          // Pick a unique monster icon for your robot!
	robot_bitmap_col = 33;
	team_name = L"Gooblinz";
}

Command Gooblinz::RobotControl::do_command(const Info& info)
{

	OutputDebugString(L"Nu körs do_command()\n"); 
	if (info.last_event == Event::COLLISION)
		OutputDebugString(L"Krockade i förra rundan!\n");

	int d = rand() % 8;
	Dir dir = static_cast<Dir>(d);
	bool move = 1;
	int n = 0;
	int check = -1;
	vector<int> walls = { -50 };
	Action act = Action::STEP;
	rundor = rundor - 1;

	walls.push_back(banana);

	if (lastround == Dir::NW) 
	{
		if (lastbanana == 1)
		{
			walls.push_back(4);
		}
		else if (lastbanana == 3)
		{
			walls.push_back(6);
		}
	}
	else if (lastround == Dir::N) 
	{
		if (lastbanana == 0)
		{
			walls.push_back(3);
		}
		else if (lastbanana == 2)
		{
			walls.push_back(4);
		}

	}
	else if (lastround == Dir::NE) 
	{
		if (lastbanana == 1)
		{
			walls.push_back(3);
		}
		else if (lastbanana == 4)
		{
			walls.push_back(6);
		}
	}
	else if (lastround == Dir::W) 
	{
		if (lastbanana == 0)
		{
			walls.push_back(1);
		}
		else if (lastbanana == 5)
		{
			walls.push_back(6);
		}

	}
	else if (lastround == Dir::E) 
	{
		if (lastbanana == 2)
		{
			walls.push_back(1);
		}
		else if (lastbanana == 7)
		{
			walls.push_back(6);
		}

	}
	else if (lastround == Dir::SW) 
	{
		if (lastbanana == 3)
		{
			walls.push_back(1);
		}
		else if (lastbanana == 6)
		{
			walls.push_back(4);
		}

	}
	else if (lastround == Dir::S) 
	{
		if (lastbanana == 5)
		{
			walls.push_back(3);
		}
		else if (lastbanana == 7)
		{
			walls.push_back(4);
		}

	}
	else if (lastround == Dir::SE) 
	{
		if (lastbanana == 6)
		{
			walls.push_back(3);
		}
		else if (lastbanana == 4)
		{
			walls.push_back(1);
		}

	}
	

	//stoppar roboten från att gå i samma riktning som förrförra rundan
	if (lastlastround == Dir::NW) {
		walls.push_back(4);
		walls.push_back(6);
		walls.push_back(7);
	}
	else if (lastlastround == Dir::N) {
		walls.push_back(5);
		walls.push_back(6);
		walls.push_back(7);
	}
	else if (lastlastround == Dir::NE) {
		walls.push_back(3);
		walls.push_back(5);
		walls.push_back(6);
	}
	else if (lastlastround == Dir::W) {
		walls.push_back(2);
		walls.push_back(4);
		walls.push_back(7);
	}
	else if (lastlastround == Dir::E) {
		walls.push_back(0);
		walls.push_back(3);
		walls.push_back(5);
	}
	else if (lastlastround == Dir::SW) {
		walls.push_back(1);
		walls.push_back(2);
		walls.push_back(4);
	}
	else if (lastlastround == Dir::S) {
		walls.push_back(0);
		walls.push_back(1);
		walls.push_back(2);
	}
	else if (lastlastround == Dir::SE) {
		walls.push_back(0);
		walls.push_back(1);
		walls.push_back(3);
	}




	//stoppar roboten från att gå i samma riktning som förra rundan
	if (lastround == Dir::NW) {
		walls.push_back(4);
		walls.push_back(6);
		walls.push_back(7);
	}
	else if (lastround == Dir::N) {
		walls.push_back(5);
		walls.push_back(6);
		walls.push_back(7);
	}
	else if (lastround == Dir::NE) {
		walls.push_back(3);
		walls.push_back(5);
		walls.push_back(6);
	}
	else if (lastround == Dir::W) {
		walls.push_back(2);
		walls.push_back(4);
		walls.push_back(7);
	}
	else if (lastround == Dir::E) {
		walls.push_back(0);
		walls.push_back(3);
		walls.push_back(5);
	}
	else if (lastround == Dir::SW) {
		walls.push_back(1);
		walls.push_back(2);
		walls.push_back(4);
	}
	else if (lastround == Dir::S) {
		walls.push_back(0);
		walls.push_back(1);
		walls.push_back(2);
	}
	else if (lastround == Dir::SE) {
		walls.push_back(0);
		walls.push_back(1);
		walls.push_back(3);
	}


	




	//Kollar alla directions och letar efter väggar, traps och spelare. Hittar den någon push_backas koordinaten till vectorn 'walls'
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




	//Genererar en direction som inte går in i en vägg, spelare eller trap som baseras på vectorn 'walls'
	while (move) {

		/*
		Ibland fastnar roboten i ett hörn, så för att förhindrahinen evig loop tvingar man roboten att röra sig efter ett stort antal
		*/
		n++;
		if (n > 200) {
			if (lastround == Dir::NW) {
				dir = Dir::SE;
			}
			else if (lastround == Dir::N) {
				dir = Dir::S;
			}
			else if (lastround == Dir::NE) {
				dir = Dir::SW;
			}
			else if (lastround == Dir::W) {
				dir = Dir::E;
			}
			else if (lastround == Dir::E) {
				dir = Dir::W;
			}
			else if (lastround == Dir::SW) {
				dir = Dir::NE;
			}
			else if (lastround == Dir::S) {
				dir = Dir::N;
			}
			else if (lastround == Dir::SE) {
				dir = Dir::NW;
			}
			lastround = dir;
			lastlastround = lastround;
			move = false;
		}

		for (int i = 0; i < walls.size(); i++)
		{
			if (walls[i] == d)
			{
				check = i;
				break;
			}
		}
		if (walls.empty() || walls[check] != d)
		{
			move = false;
		
			if(d==0)
				dir = Dir::NW;

			else if (d == 1)
				dir = Dir::N;
			
			else if (d == 2)
				dir = Dir::NE;
			
			else if (d == 3)
				dir = Dir::W;
			
			else if (d == 4)
				dir = Dir::E;
			
			else if (d == 5)
				dir = Dir::SW;
			
			else if (d == 6)
				dir = Dir::S;
			
			else if (d == 7)
				dir = Dir::SE;
		}
		else
		{
			d = rand() % 8;
		}
	}
	
	//Letar efter en robot, hittar den robot så ändrar den STEP till PLACE_TRAP
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
			{
				continue;
			}
			else
			{
				if ((info.neighbor_cells[i][j] == Cell_content::ROBOT) && rundor <= 0)
				{
					act = Action::PLACE_TRAP;
					rundor = 3;
				}
			}
		}
	}

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
						act = Action::STEP;
						break;
					case 1:
						dir = Dir::N;
						act = Action::STEP;
						break;
					case 2:
						dir = Dir::NE;
						act = Action::STEP;
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
						act = Action::STEP;
						break;;
					case 1:
						break;;
					case 2:
						dir = Dir::E;
						act = Action::STEP;
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
						act = Action::STEP;
						break;
					case 1:
						dir = Dir::S;
						act = Action::STEP;
						break;
					case 2:
						dir = Dir::SE;
						act = Action::STEP;
						break;
					default:
						break;
					}
				}
			}
		}
	}



	//Lagrar förra rundans banankoordinater
	lastbanana = banana;

	//sparar plats för placerad banan
	if (act == Action::PLACE_TRAP)
	{
		if (dir == Dir::NW)
		{
			banana = 0;
			OutputDebugString(L"hejhej");
		}
		else if (dir == Dir::N)
		{
			banana = 1;
			OutputDebugString(L"hejhej banna");
		}
		else if (dir == Dir::NE)
		{
			banana = 2;
			OutputDebugString(L"hejhej banan");
		}
		else if (dir == Dir::W)
		{
			banana = 3;
			OutputDebugString(L"hejhej banana");
		}
		else if (dir == Dir::E)
		{
			banana = 4;
			OutputDebugString(L"hejhej banannana");
		}
		else if (dir == Dir::SW)
		{
			banana = 5;
			OutputDebugString(L"hejhej bananananananana");
		}
		else if (dir == Dir::S)
		{
			banana = 6;
			OutputDebugString(L"hejhej banananananananananananan");
		}
		else if (dir == Dir::SE)
		{
			banana = 7;
			OutputDebugString(L"hejhej banananananananananananananananannanana");
		}
	}
	else
	{
		banana = -5;
	}


	//lagrar förrförra rundans koordinater
	lastlastround = lastround;

	//lagrar förra rundans koordinater;
	lastround = dir;

	return Command{ act,dir };
}