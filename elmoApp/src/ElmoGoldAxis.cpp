
#include "ElmoGoldController.h"

ElmoGoldAxis::ElmoGoldAxis(ElmoGoldController* _controller, int axis_number)
    : asynMotorAxis(_controller, axis_number),
      controller(_controller)
{

}

asynStatus ElmoGoldAxis::move(double position, int relative, double minVelocity, double maxVelocity, double acceleration)
{
    if(relative)
        sprintf(controller->outString_, "PR=%d", position);
    else
        sprintf(controller->outString_, "PA=%d", position);
    controller->writeController();
    sprintf(controller->outString_, "BG");
    controller->writeController();

    return asynSuccess;
}

asynStatus ElmoGoldAxis::stop(double acceleration)
{
    int status;

    sprintf(controller->outString_, "SD=%d", (int) acceleration);
    status = controller->writeController();
    if(status != asynSuccess)
        return status;

    sprintf(controller->outString_, "ST");
    status = controller->writeController();
    if(status != asynSuccess)
        return status;

    return asynSuccess;
}

asynStatus ElmoGoldAxis::setPosition(double position)
{
    int status;

    sprintf(controller->outString_, "PA=%f", position);
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::poll(bool* moving)
{
    int status;

    sprintf(controller->outString_, "FP");
    controller->writeReadController();
    setDoubleParam(controller->motorPosition_, atof(controller->inString_));
}

