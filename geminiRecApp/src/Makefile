TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library


# xxxRecord.h will be created from xxxRecord.dbd
DBDINC += genSubRecord
DBDINC += applyRecord
DBDINC += cadRecord
DBDINC += carRecord
DBDINC += sirRecord
DBDINC += menuCarstates
DBDINC += menuDirective
DBDINC += menuSimulation
DBDINC += cmdTimeoutRecord
DBDINC += loadRecord
DBDINC += lutinRecord
DBDINC += lutoutRecord
DBDINC += statusRecord


# install these .dbd files into <top>/dbd
DBD += genSubRecord.dbd
DBD += applyRecord.dbd
DBD += cadRecord.dbd
DBD += carRecord.dbd
DBD += sirRecord.dbd
DBD += menuCarstates.dbd
DBD += menuDirective.dbd
DBD += menuSimulation.dbd
DBD += cmdTimeoutRecord.dbd
DBD += loadRecord.dbd
DBD += lutinRecord.dbd
DBD += lutoutRecord.dbd
DBD += statusRecord.dbd
DBD += geminiRecords.dbd


# geminiRecords.dbd is made from all the individual .dbd files. 
geminiRecords_DBD += base.dbd
geminiRecords_DBD += genSubRecord.dbd
geminiRecords_DBD += applyRecord.dbd
geminiRecords_DBD += cadRecord.dbd
geminiRecords_DBD += carRecord.dbd
geminiRecords_DBD += sirRecord.dbd
geminiRecords_DBD += menuCarstates.dbd
geminiRecords_DBD += menuDirective.dbd
geminiRecords_DBD += menuSimulation.dbd
geminiRecords_DBD += cmdTimeoutRecord.dbd
geminiRecords_DBD += loadRecord.dbd
geminiRecords_DBD += lutinRecord.dbd
geminiRecords_DBD += lutoutRecord.dbd
geminiRecords_DBD += statusRecord.dbd

LIBRARY_IOC += geminiRecords
geminiRecords_SRCS += genSubRecord.c
geminiRecords_SRCS += applyRecord.c
geminiRecords_SRCS += cadRecord.c
geminiRecords_SRCS += carRecord.c
geminiRecords_SRCS += sirRecord.c
geminiRecords_SRCS += cmdTimeoutRecord.c
geminiRecords_SRCS += loadRecord.c
geminiRecords_SRCS += lutinRecord.c
geminiRecords_SRCS += lutoutRecord.c
geminiRecords_SRCS += statusRecord.c

geminiRecords_LIBS += $(EPICS_BASE_IOC_LIBS)

# The following are compiled and added to the Support library

#=============================
# build an ioc application

PROD_IOC = 
# <name>.dbd will be created from <name>Include.dbd
DBD += 

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd

# Add locally compiled object code

# The following adds support from base/src/vxWorks


# NOTES:
#      1)It is not possible to build sncExample both as a component of geminiRec
#        and standalone. You must choose only one.
#      2)To build sncExample SNCSEQ must be defined in <top>/configure/RELEASE

# The following builds sncExample as a component of geminiRec
#example_SRCS += sncExample.stt
#example_LIBS += seq pv


# The following builds sncExample as a standalone application
#PROD_HOST += sncExample
#sncExample_SNCFLAGS += +m
#sncExample_SRCS += sncExample.stt
#sncExample_LIBS += seq pv
#sncExample_LIBS += $(EPICS_BASE_HOST_LIBS)

#SCRIPTS += icd2sim.cmd

INC += cad.h
INC += lut.h

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

