TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#=============================
# Build a support module called <APPNAME>

LIBRARY_IOC += geminiRec

# <APPNAME>.dbd will be created and installed
DBD += geminiRec.dbd

# geminiRec.dbd will be made up from these files:
geminiRec_DBD += base.dbd
# List local .dbd files here
# geminiRec_DBD += xxx.dbd

# Include dbd files for external support modules:
# geminiRec_DBD += genSubRecord.dbd

# specify all source files to be compiled
# including sequencer (.st) source files
#geminiRec_SRCS += xxx.c
#geminiRec_SRCS += xxx.st

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

