#
# OMNeT++/OMNEST Makefile for GraduationFinal
#
# This file was generated with the command:
#  opp_makemake -f --deep -IC:/Users/5537/src/veins-1/src/veins/modules/messages -IC:/Users/5537/src/veins-1/src -IC:/Users/5537/src/veins-1/src/veins/base/utils -IC:/Users/5537/src/veins-1/src/veins -IC:/Users/5537/src/veins-1/src/veins/modules/application/ieee80211p -LC:/Users/5537/src/veins-1/out/$$\(CONFIGNAME\)/src -lveins -KVEÝNS_PROJ=C:/Users/5537/src/veins-1
#

# Name of target to be created (-o option)
TARGET = GraduationFinal$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(VEÝNS_PROJ)/src/veins/modules/messages \
    -I$(VEÝNS_PROJ)/src \
    -I$(VEÝNS_PROJ)/src/veins/base/utils \
    -I$(VEÝNS_PROJ)/src/veins \
    -I$(VEÝNS_PROJ)/src/veins/modules/application/ieee80211p \
    -I. \
    -Iapplayer \
    -Imessage

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(VEÝNS_PROJ)/out/$(CONFIGNAME)/src  -lveins
LIBS += -Wl,-rpath,`abspath $(VEÝNS_PROJ)/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/applayer/applayerfile.o $O/message/messageFile.o $O/message/messageFile_m.o

# Message files
MSGFILES = \
    message/messageFile.msg

# Other makefile variables (-K)
VEÝNS_PROJ=C:/Users/5537/src/veins-1

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f GraduationFinal GraduationFinal.exe libGraduationFinal.so libGraduationFinal.a libGraduationFinal.dll libGraduationFinal.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f applayer/*_m.cc applayer/*_m.h
	$(Q)-rm -f message/*_m.cc message/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc applayer/*.cc message/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/applayer/applayerfile.o: applayer/applayerfile.cc \
	applayer/applayerfile.h \
	message/messageFile.h \
	$(VEÝNS_PROJ)/src/veins/base/connectionManager/BaseConnectionManager.h \
	$(VEÝNS_PROJ)/src/veins/base/connectionManager/ChannelAccess.h \
	$(VEÝNS_PROJ)/src/veins/base/connectionManager/NicEntry.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BaseApplLayer.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BaseBattery.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BaseLayer.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BaseMobility.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BaseModule.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BaseWorldUtility.h \
	$(VEÝNS_PROJ)/src/veins/base/modules/BatteryAccess.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/Coord.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/FWMath.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/FindModule.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/HostState.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/MiXiMDefs.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/Move.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/NetwToMacControlInfo.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/PassedMessage.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/SimpleAddress.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/miximkerneldefs.h \
	$(VEÝNS_PROJ)/src/veins/modules/application/ieee80211p/BaseWaveApplLayer.h \
	$(VEÝNS_PROJ)/src/veins/modules/mac/ieee80211p/WaveAppToMac1609_4Interface.h \
	$(VEÝNS_PROJ)/src/veins/modules/messages/WaveShortMessage_m.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCIBuffer.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCIColor.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCICommandInterface.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCIConnection.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCICoord.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCIMobility.h \
	$(VEÝNS_PROJ)/src/veins/modules/mobility/traci/TraCIScenarioManager.h \
	$(VEÝNS_PROJ)/src/veins/modules/obstacle/Obstacle.h \
	$(VEÝNS_PROJ)/src/veins/modules/obstacle/ObstacleControl.h \
	$(VEÝNS_PROJ)/src/veins/modules/utility/Consts80211p.h \
	$(VEÝNS_PROJ)/src/veins/modules/world/annotations/AnnotationManager.h
$O/message/messageFile.o: message/messageFile.cc \
	message/messageFile.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/Coord.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/FWMath.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/MiXiMDefs.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/miximkerneldefs.h \
	$(VEÝNS_PROJ)/src/veins/modules/messages/WaveShortMessage_m.h
$O/message/messageFile_m.o: message/messageFile_m.cc \
	message/messageFile_m.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/Coord.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/FWMath.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/MiXiMDefs.h \
	$(VEÝNS_PROJ)/src/veins/base/utils/miximkerneldefs.h \
	$(VEÝNS_PROJ)/src/veins/modules/messages/WaveShortMessage_m.h

