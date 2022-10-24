#ifndef __ELMO_MC__
#define __ELMO_MC__

#include <cstdlib>

#include <iocsh.h>
#include <epicsThread.h>
#include <asynOctetSyncIO.h>
#include <epicsExport.h>

#include "ElmoGoldAxis.h"

#define ELMO_GOLD_PARAMETERS    1

#define ELMO_GOLD_CPU_USAGE      "ElmoGold_CPU_USAGE"

class ElmoGoldController : public asynMotorController
{
public:
    ElmoGoldController(const char* port_name, const char* asyn_name, int axis_count, double moving_poll, double idle_poll);
    ElmoGoldAxis* getAxis(asynUser* asyn_user);
    ElmoGoldAxis* getAxis(int axis);
    asynStatus poll();

    friend class ElmoGoldAxis;

protected:
    int cpuUsage;
};

#endif
