CC = gcc
CFLAGS = -std=c99
EXEC = doorAccess doorAccess_file doorAccessRef doorAccessRef_func

all: ${EXEC}

%: %.c
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm doorAccess doorAccess_file doorAccessRef doorAccessRef_func