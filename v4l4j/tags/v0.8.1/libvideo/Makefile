# change the value of LOG_LEVEL to alter the king of debug statements
# to be printed
#
# THE LOG SOURCE & LEVEL CAN BE CHANGED ON THE COMMAND LINE BY
# DEFINING THE LIBVIDEO_LOG_LEVEL OR LIBVIDEO_LOG_SOURCE VARIABLES.
#
# for example: 
# LIBVIDEO_LOG_LEVEL=16 LIBVIDEO_LOG_SOURCE=127 ant clean all 
#
# LOG_LEVEL_INFO            1
# LOG_LEVEL_DEBUG           2
# LOG_LEVEL_DEBUG1          4
# LOG_LEVEL_DEBUG2          8
# LOG_LEVEL_ERR             16
# LOG_LEVEL_ALL             31
ifneq ($(LIBVIDEO_LOG_LEVEL),)
LOG_LEVEL=$(LIBVIDEO_LOG_LEVEL)
else
#LOG_LEVEL=23
LOG_LEVEL=31
endif


# change the value of LOG_SOURCE to control which parts of v4l4j will
# print debug statements
#
# LOG_SOURCE_VIDEO_DEVICE   1
# LOG_SOURCE_QUERY          2
# LOG_SOURCE_CAPTURE        4
# LOG_SOURCE_CONTROL        8
# LOG_SOURCE_MEMALLOC       16
# LOG_SOURCE_CTRL_PROBE     32
# LOG_SOURCE_TUNER          64
# LOG_SOURCE_ALL            127
ifneq ($(LIBVIDEO_LOG_SOURCE),)
LOG_SOURCE=$(LIBVIDEO_LOG_SOURCE)
else
#LOG_SOURCE=63
LOG_SOURCE=127
endif


#
# edit anything below at your own risk
#


ifneq ($(DEBUG),)
DBG=-DDEBUG -ggdb -Wall -DLIBVIDEO_LOG_LEVEL=$(LOG_LEVEL) -DLIBVIDEO_LOG_SOURCE=$(LOG_SOURCE)
else
OPTIMISATION=-O3
endif

VERSION_MAJOR=0
VERSION_MINOR=8

LIBV4LCONVERT_DIR=libv4lconvert
LIBV4LCONVERT_AR=libv4lconvert.a
LIBV4LCONVERT_NAME=v4lconvert

LIB=libvideo.a
TESTOBJ=test-capture.o dump-capture.o list-caps.o
OBJ=v4l2-input.o v4l1-input.o libvideo.o pwc-probe.o gspca-probe.o qc-probe.o fps-param-probe.o v4l1-query.o v4l2-query.o v4l1-tuner.o v4l2-tuner.o palettes.o

CC=gcc
CFLAGS=$(DBG) -DVER_MAJ=$(VERSION_MAJOR) -DVER_MIN=$(VERSION_MINOR) $(OPTIMISATION) -fPIC -I.

LD=gcc
LDFLAGS=

all: $(LIBV4LCONVERT_AR) $(LIB)

$(LIBV4LCONVERT_AR):
	LINKTYPE=static make -C $(LIBV4LCONVERT_DIR)
	cp $(LIBV4LCONVERT_DIR)/$(LIBV4LCONVERT_AR) .

$(LIB): version.h $(OBJ)
	ar rc $(LIB) $(OBJ) ; ranlib $(LIB)

version.h:
	@sh svn-version.sh

test: version.h $(TESTOBJ) $(LIB) $(LIBV4LCONVERT_AR)
	$(LD) $(LDFLAGS) test-capture.o $(OBJ) -L. -l$(LIBV4LCONVERT_NAME) -o test-capture
	$(LD) $(LDFLAGS) list-caps.o $(OBJ) -L. -l$(LIBV4LCONVERT_NAME) -o list-caps
	$(LD) $(LDFLAGS) dump-capture.o $(OBJ) -L. -l$(LIBV4LCONVERT_NAME) -o dump-capture

clean:
	make -C $(LIBV4LCONVERT_DIR) clean
	rm -f $(OBJ) $(BIN) $(LIB) $(TESTOBJ) $(LIBV4LCONVERT_AR) ./*.o list-caps test-capture dump-capture ./*~
