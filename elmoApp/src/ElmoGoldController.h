#ifndef __ELMO_MC__
#define __ELMO_MC__

#include <iocsh.h>
#include <epicsThread.h>
#include <asynOctetSyncIO.h>
#include <epicsExport.h>

#include "ElmoGoldAxis.h"

class ElmoGoldController : public asynMotorController
{
public:
    ElmoGoldController(const char* port_name, const char* asyn_name, int axis_count, double moving_poll, double idle_poll);

    friend class ElmoGoldAxis;
};

#endif
