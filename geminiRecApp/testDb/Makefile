TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
vpath %.sym ..
vpath %.db $(SYS_DB_PATHS)

# Install database files created from .sch files
# using TDCT (or just install .db files) into <top>/db.
# TDCT_CFG can be redefined here if needed
TDCT_CFG = ../tdct.cfg

# Create and install (or just install) into <top>/db
# databases, templates, substitutions like this
DB += $(wildcard ../*.sym)
DEPSCHS = $(wildcard ../*.sch)

DB += testTop.db
DB += testSadTop.db

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
$(COMMON_DIR)/%.db: %.db
	cp $< $@

