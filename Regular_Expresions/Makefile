CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

main: main.o analyzer.o loop.o comment.o variable.o
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@rm -f *.o
	@clear

main.o: ./src/main.cc ./lib/analyzer.h 
	@$(CXX) -c ./src/main.cc

analyzer.o: ./src/analyzer.cc ./lib/loop.h ./lib/variable.h ./lib/comment.h
	@$(CXX) -c ./src/analyzer.cc

loop.o: ./src/loop.cc
	@$(CXX) -c ./src/loop.cc

variable.o: ./src/loop.cc
	@$(CXX) -c ./src/variable.cc

comment.o: ./src/loop.cc
	@$(CXX) -c ./src/comment.cc
	
.PHONY: clean
clean :
	@rm -f *.o
	@clear