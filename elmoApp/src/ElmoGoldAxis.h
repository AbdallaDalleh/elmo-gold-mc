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
    asynStatus move(double position, int relative, double minVelocity, double maxVelocity, double acceleration);
    asynStatus stop(double acceleration);
    asynStatus poll(bool* moving);
    asynStatus setPosition(double position);

private:
    ElmoGoldController* controller;

friend class ElmoGoldController;
};

#endif

