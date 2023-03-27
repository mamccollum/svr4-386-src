#	Copyright (c) 1990 UNIX System Laboratories, Inc.
#	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T
#	  All Rights Reserved

#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF
#	UNIX System Laboratories, Inc.
#	The copyright notice above does not evidence any
#	actual or intended publication of such source code.

#	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T
#	  All Rights Reserved

#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
#	The copyright notice above does not evidence any
#	actual or intended publication of such source code.


#ident	"@(#)dd:dd.mk	1.5.4.3"

#	Makefile for dd 

ROOT =

DIR = $(ROOT)/usr/bin

INS = install

INC = $(ROOT)/usr/include

LDFLAGS = -s 

CFLAGS = -O -I$(INC)

STRIP = strip

SIZE = size

#top#
# Generated by makefile 1.47

MAKEFILE = dd.mk


MAINS = dd dd.arch

OBJECTS =  dd.o

SOURCES =  dd.c

ALL:		$(MAINS)

dd:		dd.o 
	$(CC) $(CFLAGS)  -o dd  dd.o   $(LDFLAGS) $(PERFLIBS)

#	Now create an archive lib version to replace shlib version at
#	end of installation. Needed to allow sysdump after system panic.
dd.arch:		dd.o 
	$(CC) $(CFLAGS)  -o dd.arch dd.o   $(LDFLAGS) $(ROOTLIBS)

dd.o:		 $(INC)/stdio.h $(INC)/signal.h \
		 $(INC)/sys/signal.h $(INC)/sys/param.h \
		 $(INC)/sys/types.h $(INC)/sys/sysmacros.h \
		 $(INC)/sys/stat.h $(INC)/unistd.h $(INC)/stdlib.h

GLOBALINCS = $(INC)/signal.h $(INC)/stdio.h \
	$(INC)/sys/param.h $(INC)/sys/signal.h \
	$(INC)/sys/sysmacros.h $(INC)/sys/types.h \
		 $(INC)/sys/stat.h $(INC)/unistd.h $(INC)/stdlib.h


clean:
	rm -f $(OBJECTS)

clobber:
	rm -f $(OBJECTS) $(MAINS)

newmakefile:
	makefile -m -f $(MAKEFILE)  -s INC $(INC)
#bottom#

all : ALL

install: ALL
	$(INS) -f $(DIR) -m 0555 -u bin -g bin dd
	$(INS) -f $(DIR) -m 0555 -u bin -g bin dd.arch

size: ALL
	$(SIZE) $(MAINS)

strip: ALL
	$(STRIP) $(MAINS)

#	These targets are useful but optional

partslist:
	@echo $(MAKEFILE) $(SOURCES) $(LOCALINCS)  |  tr ' ' '\012'  |  sort

productdir:
	@echo $(DIR) | tr ' ' '\012' | sort

product:
	@echo $(MAINS)  |  tr ' ' '\012'  | \
	sed 's;^;$(DIR)/;'

srcaudit:
	@fileaudit $(MAKEFILE) $(LOCALINCS) $(SOURCES) -o $(OBJECTS) $(MAINS)
