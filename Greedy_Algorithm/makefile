CC = g++
CFLAGS = -c
INCLUDE = -I./lib
OBJECTS = main.o coin.o changeMachine.o
EXECUTABLE = main

all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: src/main.cc lib/coin.h lib/changeMachine.h lib/utils.h
	$(CC) $(CFLAGS) $(INCLUDE) src/main.cc

coin.o: src/coin.cc lib/coin.h
	$(CC) $(CFLAGS) $(INCLUDE) src/coin.cc

changeMachine.o: src/changeMachine.cc lib/changeMachine.h
	$(CC) $(CFLAGS) $(INCLUDE) src/changeMachine.cc

clean:
	rm -f $(OBJECTS)