OBJS = linkedList.o linkedListTester.o

CC=gcc

CFLAGS=-std=c99 -g -Wall -Werror -Wconversion -pedantic -lreadline

linkedListTester: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o linkedListTester

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

test: linkedListTester
	valgrind --quiet --leak-check=full --track-origins=yes ./linkedListTester

clean:
	rm -f *.o linkedListTester
