CC = gcc
CFLAGS = -std=c99
EXEC = readHum

all: ${EXEC}

%: %.c
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm readHum