
#include "ElmoGoldController.h"

ElmoGoldAxis::ElmoGoldAxis(ElmoGoldController* _controller, int axis_number)
    : asynMotorAxis(_controller, axis_number),
      controller(_controller)
{

}

