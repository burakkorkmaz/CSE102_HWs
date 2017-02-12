CC = gcc
CFLAGS = -c -ansi -Wall -pedantic -errors
LIBS = -lm -lnsl
FILENAME = hw12

all: $(FILENAME) clean run
	
$(FILENAME): $(FILENAME).o
	$(CC) $(FILENAME).o -o hw

$(FILENAME).o: $(FILENAME).c
	$(CC) $(CFLAGS) $(FILENAME).c

clean:
	rm -rf *.o
	
run: 
	./hw
