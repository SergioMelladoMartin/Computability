CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

main: main.o alphabet.o symbol.o chain.o state.o NFA.o
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@rm -f *.o

main.o: ./src/main.cc ./lib/alphabet.h ./lib/chain.h ./lib/symbol.h
	@$(CXX) -c ./src/main.cc

symbol.o: ./src/symbol.cc 
	@$(CXX) -c ./src/symbol.cc

alphabet.o: ./src/alphabet.cc ./lib/symbol.h 
	@$(CXX) -c ./src/alphabet.cc

chain.o: ./src/chain.cc ./lib/symbol.h ./lib/alphabet.h
	@$(CXX) -c ./src/chain.cc

state.o: ./src/state.cc ./lib/symbol.h ./lib/alphabet.h
	@$(CXX) -c ./src/state.cc

NFA.o: ./src/NFA.cc ./lib/symbol.h ./lib/alphabet.h ./lib/state.h
	@$(CXX) -c ./src/NFA.cc

.PHONY: clean

clean :
	@rm -f *.o