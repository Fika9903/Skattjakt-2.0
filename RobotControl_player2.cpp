#include "pch.h"
#include "RobotControl_player2.h"

using namespace Player2;

Player2::RobotControl::RobotControl()
{
	robot_bitmap_row = 15;          // Pick a unique monster icon for your robot!
	robot_bitmap_col = 15;
	team_name = L"John Cena";
}

Command Player2::RobotControl::do_command(const Info &info)
{
	int d = rand() % 8;
	Dir dir = static_cast<Dir>(d);
	// dir = Dir::NE;
	Action act = Action::STEP;
	if (rand() % 20 == 0)
		act = Action::PLACE_TRAP;
	return Command{act,dir};
}
