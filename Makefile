SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}

all: options tm

options:
	@echo tm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

tm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

.PHONY: all options
