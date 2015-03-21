OBJS = stack.o stackTester.o

OUTPUT = stackTester

CC=clang

CFLAGS=-std=c99 -g -Wall -Werror -Wconversion -pedantic

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

test: $(OUTPUT)
	valgrind --quiet --leak-check=full --track-origins=yes ./$(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)

