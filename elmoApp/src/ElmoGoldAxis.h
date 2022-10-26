#ifndef __ELMO_AXIS__
#define __ELMO_AXIS__

#include <iostream>

#include "asynMotorController.h"
#include "asynMotorAxis.h"
#include "motor.h"

using std::cout;
using std::endl;

class ElmoGoldAxis : public asynMotorAxis
{
public:
    ElmoGoldAxis(class ElmoGoldController* _controller, int axis_number);
    asynStatus move(double position, int relative, double minVelocity, double maxVelocity, double acceleration);
    asynStatus moveVelocity(double minVelocity, double maxVelocity, double acceleration);
    asynStatus stop(double acceleration);
    asynStatus poll(bool* moving);
    asynStatus setPosition(double position);
    asynStatus setEncoderPosition(double position);
    asynStatus setHighLimit(double highLimit);
    asynStatus setLowLimit(double lowLimit);
    asynStatus setPGain(double pGain);
    asynStatus setIGain(double iGain);

private:
    ElmoGoldController* controller;

friend class ElmoGoldController;
};

#endif

