CC := gcc
CFLAGS := -g -w -fno-stack-protector
LDFLAGS := -lm

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
TGTS := $(SRCS:.c=)

all: ${TGTS}

%: %.c
	${CC} $< ${CFLAGS} ${LDFLAGS} -o $@

.depend: ${SRCS}
	${CC} -MM ${CFLAGS} $^ > $@

clean:
	${RM} ${TGTS} ${OBJS} .depend

ifneq (${MAKECMDGOALS},clean)
-include .depend
endif
