OBJS = smartArray.o smartArrayTester.o

CC=clang

CFLAGS=-std=c99 -g -Wall -Werror -Wconversion -pedantic

smartArrayTester: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o smartArrayTester

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

test: smartArrayTester
	valgrind --quiet --leak-check=full --track-origins=yes ./smartArrayTester

clean:
	rm -f *.o smartArrayTester
