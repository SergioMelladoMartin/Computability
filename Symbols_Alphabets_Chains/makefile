CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

main: main.o alphabet.o symbol.o chain.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: ./src/main.cc ./lib/alphabet.h ./lib/chain.h ./lib/symbol.h 
	$(CXX) -c ./src/main.cc

symbol.o: ./src/symbol.cc 
	$(CXX) -c ./src/symbol.cc

alphabet.o: ./src/alphabet.cc ./lib/symbol.h 
	$(CXX) -c ./src/alphabet.cc

chain.o: ./src/chain.cc ./lib/symbol.h ./lib/alphabet.h
	$(CXX) -c ./src/chain.cc
	
.PHONY: clean

clean :
	@rm -f *.o
