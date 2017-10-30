CC=gcc

CFLAGS=-Wall -Wextra -g3
LFLAGS=

OBJS=main.o mm.o queue.o stack.o
DEPS=mm.h queue.h stack.h
LIBS=

BIN=test

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

clean:
	rm -f $(OBJS) $(BIN)
