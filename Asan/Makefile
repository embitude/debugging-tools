CC := gcc
CFLAGS := -w -g -fsanitize=address -fno-omit-frame-pointer
LDFLAGS :=

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
TGTS := $(SRCS:.c=)

all: ${TGTS}

.depend: ${SRCS}
	${CC} -MM ${CFLAGS} $^ > $@

%:%.c
	${CC} ${CFLAGS} $^ -o $@
clean:
	${RM} ${TGTS} ${OBJS} .depend

ifneq (${MAKECMDGOALS},clean)
-include .depend
endif
