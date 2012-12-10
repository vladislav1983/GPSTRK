#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/809998329/FSIO.o ${OBJECTDIR}/_ext/809998329/SD-SPI.o ${OBJECTDIR}/_ext/659858410/minIni.o ${OBJECTDIR}/_ext/1360937237/signal.o ${OBJECTDIR}/_ext/1360937237/alarm.o ${OBJECTDIR}/_ext/1360937237/kerneltimer.o ${OBJECTDIR}/_ext/1360937237/scheduler.o ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o ${OBJECTDIR}/_ext/1019077803/nmea_main.o ${OBJECTDIR}/_ext/1019077803/nmea_process.o ${OBJECTDIR}/_ext/1360937237/dio.o ${OBJECTDIR}/_ext/1360937237/gps_main.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/system.o ${OBJECTDIR}/_ext/1360937237/timer.o ${OBJECTDIR}/_ext/1360937237/traps.o ${OBJECTDIR}/_ext/1360937237/vuart.o ${OBJECTDIR}/_ext/1360937237/vtime.o ${OBJECTDIR}/_ext/1360937237/app_statemachine.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/809998329/FSIO.o.d ${OBJECTDIR}/_ext/809998329/SD-SPI.o.d ${OBJECTDIR}/_ext/659858410/minIni.o.d ${OBJECTDIR}/_ext/1360937237/signal.o.d ${OBJECTDIR}/_ext/1360937237/alarm.o.d ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d ${OBJECTDIR}/_ext/1360937237/scheduler.o.d ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d ${OBJECTDIR}/_ext/1019077803/nmea_main.o.d ${OBJECTDIR}/_ext/1019077803/nmea_process.o.d ${OBJECTDIR}/_ext/1360937237/dio.o.d ${OBJECTDIR}/_ext/1360937237/gps_main.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/system.o.d ${OBJECTDIR}/_ext/1360937237/timer.o.d ${OBJECTDIR}/_ext/1360937237/traps.o.d ${OBJECTDIR}/_ext/1360937237/vuart.o.d ${OBJECTDIR}/_ext/1360937237/vtime.o.d ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/809998329/FSIO.o ${OBJECTDIR}/_ext/809998329/SD-SPI.o ${OBJECTDIR}/_ext/659858410/minIni.o ${OBJECTDIR}/_ext/1360937237/signal.o ${OBJECTDIR}/_ext/1360937237/alarm.o ${OBJECTDIR}/_ext/1360937237/kerneltimer.o ${OBJECTDIR}/_ext/1360937237/scheduler.o ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o ${OBJECTDIR}/_ext/1019077803/nmea_main.o ${OBJECTDIR}/_ext/1019077803/nmea_process.o ${OBJECTDIR}/_ext/1360937237/dio.o ${OBJECTDIR}/_ext/1360937237/gps_main.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/system.o ${OBJECTDIR}/_ext/1360937237/timer.o ${OBJECTDIR}/_ext/1360937237/traps.o ${OBJECTDIR}/_ext/1360937237/vuart.o ${OBJECTDIR}/_ext/1360937237/vtime.o ${OBJECTDIR}/_ext/1360937237/app_statemachine.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA308
MP_LINKER_FILE_OPTION=,--script="..\src\p24FJ128GA308.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/809998329/FSIO.o: ../src/fs/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/809998329 
	@${RM} ${OBJECTDIR}/_ext/809998329/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/809998329/FSIO.o.ok ${OBJECTDIR}/_ext/809998329/FSIO.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/809998329/FSIO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/809998329/FSIO.o.d" -o ${OBJECTDIR}/_ext/809998329/FSIO.o ../src/fs/FSIO.c    -fast-math
	
${OBJECTDIR}/_ext/809998329/SD-SPI.o: ../src/fs/SD-SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/809998329 
	@${RM} ${OBJECTDIR}/_ext/809998329/SD-SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/809998329/SD-SPI.o.ok ${OBJECTDIR}/_ext/809998329/SD-SPI.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/809998329/SD-SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/809998329/SD-SPI.o.d" -o ${OBJECTDIR}/_ext/809998329/SD-SPI.o ../src/fs/SD-SPI.c    -fast-math
	
${OBJECTDIR}/_ext/659858410/minIni.o: ../src/ini/minIni.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659858410 
	@${RM} ${OBJECTDIR}/_ext/659858410/minIni.o.d 
	@${RM} ${OBJECTDIR}/_ext/659858410/minIni.o.ok ${OBJECTDIR}/_ext/659858410/minIni.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/659858410/minIni.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/659858410/minIni.o.d" -o ${OBJECTDIR}/_ext/659858410/minIni.o ../src/ini/minIni.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/signal.o: ../src/signal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/signal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/signal.o.ok ${OBJECTDIR}/_ext/1360937237/signal.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/signal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/signal.o.d" -o ${OBJECTDIR}/_ext/1360937237/signal.o ../src/signal.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/alarm.o: ../src/alarm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/alarm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/alarm.o.ok ${OBJECTDIR}/_ext/1360937237/alarm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/alarm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/alarm.o.d" -o ${OBJECTDIR}/_ext/1360937237/alarm.o ../src/alarm.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/kerneltimer.o: ../src/kerneltimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.ok ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d" -o ${OBJECTDIR}/_ext/1360937237/kerneltimer.o ../src/kerneltimer.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/scheduler.o: ../src/scheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/scheduler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/scheduler.o.ok ${OBJECTDIR}/_ext/1360937237/scheduler.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/scheduler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/scheduler.o.d" -o ${OBJECTDIR}/_ext/1360937237/scheduler.o ../src/scheduler.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o: ../src/nmea/nmea_gpgga.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o ../src/nmea/nmea_gpgga.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o: ../src/nmea/nmea_gprmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o ../src/nmea/nmea_gprmc.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o: ../src/nmea/nmea_gpvtg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o ../src/nmea/nmea_gpvtg.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_main.o: ../src/nmea/nmea_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_main.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_main.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_main.o ../src/nmea/nmea_main.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_process.o: ../src/nmea/nmea_process.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_process.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_process.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_process.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_process.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_process.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_process.o ../src/nmea/nmea_process.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/dio.o: ../src/dio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/dio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/dio.o.ok ${OBJECTDIR}/_ext/1360937237/dio.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/dio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/dio.o.d" -o ${OBJECTDIR}/_ext/1360937237/dio.o ../src/dio.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/gps_main.o: ../src/gps_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_main.o.ok ${OBJECTDIR}/_ext/1360937237/gps_main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gps_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/gps_main.o.d" -o ${OBJECTDIR}/_ext/1360937237/gps_main.o ../src/gps_main.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.ok ${OBJECTDIR}/_ext/1360937237/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/system.o: ../src/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/system.o.ok ${OBJECTDIR}/_ext/1360937237/system.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/system.o.d" -o ${OBJECTDIR}/_ext/1360937237/system.o ../src/system.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/timer.o: ../src/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer.o.ok ${OBJECTDIR}/_ext/1360937237/timer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer.o ../src/timer.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.ok ${OBJECTDIR}/_ext/1360937237/traps.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/traps.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d" -o ${OBJECTDIR}/_ext/1360937237/traps.o ../src/traps.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.ok ${OBJECTDIR}/_ext/1360937237/vuart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d" -o ${OBJECTDIR}/_ext/1360937237/vuart.o ../src/vuart.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/vtime.o: ../src/vtime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vtime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vtime.o.ok ${OBJECTDIR}/_ext/1360937237/vtime.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vtime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/vtime.o.d" -o ${OBJECTDIR}/_ext/1360937237/vtime.o ../src/vtime.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/app_statemachine.o: ../src/app_statemachine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.ok ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_statemachine.o ../src/app_statemachine.c    -fast-math
	
else
${OBJECTDIR}/_ext/809998329/FSIO.o: ../src/fs/FSIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/809998329 
	@${RM} ${OBJECTDIR}/_ext/809998329/FSIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/809998329/FSIO.o.ok ${OBJECTDIR}/_ext/809998329/FSIO.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/809998329/FSIO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/809998329/FSIO.o.d" -o ${OBJECTDIR}/_ext/809998329/FSIO.o ../src/fs/FSIO.c    -fast-math
	
${OBJECTDIR}/_ext/809998329/SD-SPI.o: ../src/fs/SD-SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/809998329 
	@${RM} ${OBJECTDIR}/_ext/809998329/SD-SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/809998329/SD-SPI.o.ok ${OBJECTDIR}/_ext/809998329/SD-SPI.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/809998329/SD-SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/809998329/SD-SPI.o.d" -o ${OBJECTDIR}/_ext/809998329/SD-SPI.o ../src/fs/SD-SPI.c    -fast-math
	
${OBJECTDIR}/_ext/659858410/minIni.o: ../src/ini/minIni.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659858410 
	@${RM} ${OBJECTDIR}/_ext/659858410/minIni.o.d 
	@${RM} ${OBJECTDIR}/_ext/659858410/minIni.o.ok ${OBJECTDIR}/_ext/659858410/minIni.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/659858410/minIni.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/659858410/minIni.o.d" -o ${OBJECTDIR}/_ext/659858410/minIni.o ../src/ini/minIni.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/signal.o: ../src/signal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/signal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/signal.o.ok ${OBJECTDIR}/_ext/1360937237/signal.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/signal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/signal.o.d" -o ${OBJECTDIR}/_ext/1360937237/signal.o ../src/signal.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/alarm.o: ../src/alarm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/alarm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/alarm.o.ok ${OBJECTDIR}/_ext/1360937237/alarm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/alarm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/alarm.o.d" -o ${OBJECTDIR}/_ext/1360937237/alarm.o ../src/alarm.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/kerneltimer.o: ../src/kerneltimer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.ok ${OBJECTDIR}/_ext/1360937237/kerneltimer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/kerneltimer.o.d" -o ${OBJECTDIR}/_ext/1360937237/kerneltimer.o ../src/kerneltimer.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/scheduler.o: ../src/scheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/scheduler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/scheduler.o.ok ${OBJECTDIR}/_ext/1360937237/scheduler.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/scheduler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/scheduler.o.d" -o ${OBJECTDIR}/_ext/1360937237/scheduler.o ../src/scheduler.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o: ../src/nmea/nmea_gpgga.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_gpgga.o ../src/nmea/nmea_gpgga.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o: ../src/nmea/nmea_gprmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_gprmc.o ../src/nmea/nmea_gprmc.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o: ../src/nmea/nmea_gpvtg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_gpvtg.o ../src/nmea/nmea_gpvtg.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_main.o: ../src/nmea/nmea_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_main.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_main.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_main.o ../src/nmea/nmea_main.c    -fast-math
	
${OBJECTDIR}/_ext/1019077803/nmea_process.o: ../src/nmea/nmea_process.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1019077803 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_process.o.d 
	@${RM} ${OBJECTDIR}/_ext/1019077803/nmea_process.o.ok ${OBJECTDIR}/_ext/1019077803/nmea_process.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1019077803/nmea_process.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1019077803/nmea_process.o.d" -o ${OBJECTDIR}/_ext/1019077803/nmea_process.o ../src/nmea/nmea_process.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/dio.o: ../src/dio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/dio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/dio.o.ok ${OBJECTDIR}/_ext/1360937237/dio.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/dio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/dio.o.d" -o ${OBJECTDIR}/_ext/1360937237/dio.o ../src/dio.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/gps_main.o: ../src/gps_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_main.o.ok ${OBJECTDIR}/_ext/1360937237/gps_main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gps_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/gps_main.o.d" -o ${OBJECTDIR}/_ext/1360937237/gps_main.o ../src/gps_main.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.ok ${OBJECTDIR}/_ext/1360937237/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/system.o: ../src/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/system.o.ok ${OBJECTDIR}/_ext/1360937237/system.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/system.o.d" -o ${OBJECTDIR}/_ext/1360937237/system.o ../src/system.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/timer.o: ../src/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer.o.ok ${OBJECTDIR}/_ext/1360937237/timer.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer.o ../src/timer.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.ok ${OBJECTDIR}/_ext/1360937237/traps.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/traps.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d" -o ${OBJECTDIR}/_ext/1360937237/traps.o ../src/traps.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.ok ${OBJECTDIR}/_ext/1360937237/vuart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d" -o ${OBJECTDIR}/_ext/1360937237/vuart.o ../src/vuart.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/vtime.o: ../src/vtime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vtime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vtime.o.ok ${OBJECTDIR}/_ext/1360937237/vtime.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vtime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/vtime.o.d" -o ${OBJECTDIR}/_ext/1360937237/vtime.o ../src/vtime.c    -fast-math
	
${OBJECTDIR}/_ext/1360937237/app_statemachine.o: ../src/app_statemachine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.ok ${OBJECTDIR}/_ext/1360937237/app_statemachine.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=coff -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../src/fs/MDD File System" -I"../src/fs" -I"../src" -I"../src/nmea" -I"../src/ini" -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/app_statemachine.o.d" -o ${OBJECTDIR}/_ext/1360937237/app_statemachine.o ../src/app_statemachine.c    -fast-math
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=coff -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -fast-math -Wl,--defsym=__MPLAB_BUILD=1,--heap=100,-L"../../../../../../Program Files/Microchip/MPLAB C30/lib",-L"../src",-Map="${DISTDIR}/GPSTRK10.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=coff -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -fast-math -Wl,--defsym=__MPLAB_BUILD=1,--heap=100,-L"../../../../../../Program Files/Microchip/MPLAB C30/lib",-L"../src",-Map="${DISTDIR}/GPSTRK10.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/GPSTRK10.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=coff
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
