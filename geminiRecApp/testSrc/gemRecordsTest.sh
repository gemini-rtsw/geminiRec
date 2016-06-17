#!/bin/csh -f

setenv EPICS_CA_ADDR_LIST 10.1.2.171

medm -x -macro "top=grt:" /gem_sw/work/R3.14.12.4/support/geminiRec/bin/linux-x86_64/GeminiRecordTests.adl

