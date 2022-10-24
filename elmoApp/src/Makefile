TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library

LIBRARY_IOC += elmo

DBD += elmo.dbd

# ELMO Gold Drives support
elmo_SRCS += ElmoGoldController.cpp
elmo_SRCS += ElmoGoldAxis.cpp
elmo_SRCS += ElmoGoldRegister.cpp

elmo_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

