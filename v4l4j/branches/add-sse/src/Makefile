# If the env variable JDK_HOME is not defined,
# use the following one (works on Ubuntu with OpenJDK).
ifndef JDK_HOME
JDK_HOME := /usr/lib/jvm/java-6-openjdk
endif


#
# edit anything below at your own risk
#

# THE LOG SOURCE CAN BE CHANGED ON THE COMMAND LINE BY
# DEFINING THE V4L4J_LOG_SOURCE VARIABLE.
#
# for example: 
# V4L4J_LOG_SOURCE=63 ant clean all 
#
#LOG_CALLS         1
#LOG_LIBVIDEO      2
#LOG_MEMALLOC      4
#LOG_JPEG          8
#LOG_RGB           16
#LOG_V4L4J         32
#LOG_ALL           63
#V4L4J_LOG_SOURCE ?= 38
V4L4J_LOG_SOURCE ?= 63


ifneq ($(DEBUG),)
DBG := -DDEBUG -Wall -DLOG_SOURCE=$(V4L4J_LOG_SOURCE) -ggdb
else
OPTIMISATION := -O3
endif

LIBVIDEO_NAME := video
LIBVIDEO_PATH := ../libvideo


LIB := libv4l4j.so
OBJ := jpeg.o v4l4j_FrameGrabber.o v4l4j_ImageFormatList.o \
  v4l4j_DeviceInfo.o v4l4j_VideoDevice.o v4l4j_Control.o v4l4j_Tuner.o \
  v4l4j_ResolutionInfo.o v4l4j_FrameInterval.o

CC := gcc
INCLUDES := -I$(JDK_HOME)/include -I$(JDK_HOME)/include/linux/ \
  -I$(LIBVIDEO_PATH) -I.
CFLAGS := $(INCLUDES) $(DBG) $(OPTIMISATION) -fPIC

LD := gcc
LDFLAGS := -shared -ljpeg -L$(LIBVIDEO_PATH) -l$(LIBVIDEO_NAME)

all: $(LIB)

$(LIB): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(LIB)

test-debug:
	$(CC) $(INCLUDES) -DDEBUG -Wall -ggdb -DMAKETEST -c rgb.c
	$(CC) $(INCLUDES) -mssse3 -DDEBUG -Wall -ggdb -DMAKETEST -c jpeg.c
	$(LD) jpeg.o -ljpeg -o jpeg

test:
	$(CC) $(INCLUDES) -O3 -Wall -DMAKETEST -c rgb.c
	$(CC) $(INCLUDES) -mssse3 -msse2 -O3 -Wall -DMAKETEST -c jpeg.c
	$(LD) jpeg.o -ljpeg -o jpeg


clean:
	rm -f $(OBJ) $(LIB) ./*~ jpeg

.PHONY: all test clean
