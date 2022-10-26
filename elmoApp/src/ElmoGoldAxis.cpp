
#include "ElmoGoldController.h"

ElmoGoldAxis::ElmoGoldAxis(ElmoGoldController* _controller, int axis_number)
    : asynMotorAxis(_controller, axis_number),
      controller(_controller)
{

}

asynStatus ElmoGoldAxis::move(double position, int relative, double minVelocity, double maxVelocity, double acceleration)
{
    if(relative)
        sprintf(controller->outString_, "PR=%ld;BG;", NINT(position));
    else
        sprintf(controller->outString_, "PA=%ld;BG;", NINT(position));
    controller->writeController();

    return asynSuccess;
}

asynStatus ElmoGoldAxis::moveVelocity(double minVelocity, double maxVelocity, double acceleration)
{
    long iAccel = NINT(acceleration);
    
    sprintf(controller->outString_, "AC=%ld;DC=%ld;JV=%ld;FS=%ld;", iAccel, iAccel, NINT(minVelocity), NINT(maxVelocity));
    controller->writeController();
    
    sprintf(controller->outString_, "BG");
    controller->writeController();

    return asynSuccess;
}

asynStatus ElmoGoldAxis::stop(double acceleration)
{
    asynStatus status;

    sprintf(controller->outString_, "SD=%ld", NINT(acceleration));
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
    asynStatus status;

    sprintf(controller->outString_, "PX=%ld", NINT(position));
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::setEncoderPosition(double position)
{
    asynStatus status;

    sprintf(controller->outString_, "FP=%ld", NINT(position));
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::setHighLimit(double highLimit)
{
    asynStatus status;

    sprintf(controller->outString_, "VH[3]=%ld", NINT(highLimit));
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::setLowLimit(double lowLimit)
{
    asynStatus status;

    sprintf(controller->outString_, "VL[3]=%ld", NINT(lowLimit));
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::setPGain(double pGain)
{
    asynStatus status;

    sprintf(controller->outString_, "KP[1]=%f", pGain);
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::setIGain(double iGain)
{
    asynStatus status;

    sprintf(controller->outString_, "KI[1]=%f", iGain);
    status = controller->writeController();
    return status;
}

asynStatus ElmoGoldAxis::poll(bool* moving)
{
    asynStatus status;

    sprintf(controller->outString_, "PA");
    controller->writeReadController();
    setDoubleParam(controller->motorPosition_, atof(controller->inString_));

    sprintf(controller->outString_, "PX");
    controller->writeReadController();
    setDoubleParam(controller->motorEncoderPosition_, atof(controller->inString_));
}

