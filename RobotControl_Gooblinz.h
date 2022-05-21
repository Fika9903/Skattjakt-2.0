#pragma once
#include "RobotInterface.h"

namespace Gooblinz {

	class RobotControl :
		public RobotInterface
	{
	public:
		RobotControl();

		Command do_command(const Info &info) override;
	};

}

