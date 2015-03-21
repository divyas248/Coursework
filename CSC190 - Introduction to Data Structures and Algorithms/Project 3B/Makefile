OBJS = HashTable.o HashTableTester.o

OUTPUT = hashTableTester

CC=gcc

CFLAGS=-std=c99 -g -Wall -Werror -Wconversion -pedantic

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

test: $(OUTPUT)
	valgrind --quiet --leak-check=full --track-origins=yes ./$(OUTPUT) <input.txt> output2.txt diff output.txt output2.txt

clean:
	rm -f *.o $(OUTPUT)
