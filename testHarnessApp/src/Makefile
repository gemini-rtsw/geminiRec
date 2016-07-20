TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# build a support library
SCRIPTS_HOST += ../GeminiRecordTests.adl
SCRIPTS_HOST += ../gemRecordsTest.sh

LIBRARY_IOC += testGeminiRecs

#LIBSRCS += testGeminiRecs.c
#LIBSRCS += testDisplay.c
#LIBSRCS += testConfig.c
#LIBSRCS += testInterlock.c
#LIBSRCS += testSeqInit.st
testGeminiRecs_SRCS += testGeminiRecs.c
testGeminiRecs_SRCS += testDisplay.c
testGeminiRecs_SRCS += testConfig.c
testGeminiRecs_SRCS += testInterlock.c

testGeminiRecs_LIBS += slalib xy240 $(EPICS_BASE_IOC_LIBS)

DBD += testGeminiRecs.dbd
#testGeminiRecs_DBD += base.dbd
testGeminiRecs_DBD += geminiRecords.dbd
testGeminiRecs_DBD += testRecs.dbd
testGeminiRecs_DBD += xy240.dbd

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
#
