
#include "ElmoGoldController.h"

ElmoGoldController::ElmoGoldController(const char* port_name, const char* asyn_name, int axes_count, double moving_poll_period, double idle_poll_period)
    : asynMotorController(
            port_name,
            axes_count,
            ELMO_GOLD_PARAMETERS,
            0,
            0,
            ASYN_CANBLOCK | ASYN_MULTIDEVICE, 
            1,
            0, 0)
{
    int status;
    int axis;
    ElmoGoldAxis* elmoAxis;

    status = pasynOctetSyncIO->connect(asyn_name, 0, &pasynUserController_, NULL);
    if(status != asynSuccess) {
        // TODO: Could not connect to controller.
        return;
    }

    for(axis = 0; axis < axes_count; axis++) {
        elmoAxis = new ElmoGoldAxis(this, axis);
    }

    createParam(ELMO_GOLD_CPU_USAGE, asynParamInt32, &cpuUsage);

    startPoller(moving_poll_period / 1000.0, idle_poll_period / 1000.0, 2);
}

ElmoGoldAxis* ElmoGoldController::getAxis(asynUser* asyn_user)
{
    return static_cast<ElmoGoldAxis*>(asynMotorController::getAxis(asyn_user));
}

ElmoGoldAxis* ElmoGoldController::getAxis(int axis)
{
    return static_cast<ElmoGoldAxis*>(asynMotorController::getAxis(axis));
}

asynStatus ElmoGoldController::poll()
{
    asynStatus status;
    int usage;

    sprintf(this->outString_, "CU");
    status = this->writeReadController();
    if(status != asynSuccess)
        setIntegerParam(motorStatusProblem_, 1);
    else {
        usage = atoi(this->inString_);
        setIntegerParam(cpuUsage, usage);
    }

    callParamCallbacks();
    return status;
}

