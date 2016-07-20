# Makefile,v 1.1 2000/09/27 16:06:50 jba Exp

TOP = .
include $(TOP)/configure/CONFIG
DIRS += configure
DIRS += geminiRecApp
DIRS += testHarnessApp
include $(TOP)/configure/RULES_TOP


