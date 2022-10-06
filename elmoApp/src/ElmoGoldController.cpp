
#include "ElmoGoldController.h"

ElmoGoldController::ElmoGoldController(const char* port_name, const char* asyn_name, int axes_count, double moving_poll_period, double idle_poll_period)
    : asynMotorController(
            port_name,
            axes_count,
            0,
            0,
            0,
            ASYN_CANBLOCK | ASYN_MULTIDEVICE, 
            1,
            0, 0)
{

}

