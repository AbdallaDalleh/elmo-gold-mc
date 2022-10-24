
#include <asynPortDriver.h>
#include <epicsExport.h>
#include <iocsh.h>
#include <ElmoGoldController.h>

extern "C" int ElmoGoldCreateController(const char* portName, const char* asynName, int axisCount, int movingPollPeriod, int idlePollPeriod)
{
    new ElmoGoldController(portName, asynName, axisCount, movingPollPeriod, idlePollPeriod);
    return asynSuccess;
}

static const iocshArg arg0 = {"Port Name",  iocshArgString};
static const iocshArg arg1 = {"Asyn Name",  iocshArgString};
static const iocshArg arg2 = {"Axis Count", iocshArgInt};
static const iocshArg arg3 = {"Moving Poll Period (ms)", iocshArgInt};
static const iocshArg arg4 = {"Idle Poll Period (ms) ",  iocshArgInt};

static const iocshArg* const functionArgs[] = {&arg0, &arg1, &arg2, &arg3, &arg4};

static const iocshFuncDef functionDefinition = {"ElmoGoldCreateController", 5, functionArgs};
static void  functionCall(const iocshArgBuf* args)
{
    ElmoGoldCreateController(args[0].sval, args[1].sval, args[2].ival, args[3].ival, args[4].ival);
}

static void  ElmoGoldRegister()
{
    iocshRegister(&functionDefinition, functionCall);
}

extern "C" {
    epicsExportRegistrar(ElmoGoldRegister);
}

