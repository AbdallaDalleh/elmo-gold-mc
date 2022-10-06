#ifndef __ELMO_AXIS__
#define __ELMO_AXIS__

#include <iostream>

#include "asynMotorController.h"
#include "asynMotorAxis.h"

using std::cout;
using std::endl;

class ElmoGoldAxis : public asynMotorAxis
{
public:
    ElmoGoldAxis(class ElmoGoldController* _controller, int axis_number);

private:
    ElmoGoldController* controller;

friend class ElmoGoldController;
};

#endif

