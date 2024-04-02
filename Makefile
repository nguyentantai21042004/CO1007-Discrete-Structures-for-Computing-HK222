CXX = g++
CXXFLAGS = -Wall -Wextra
VPATH = build

all: build/bin/run

build/bin/run: main.o calculateLogic.o calculateMath.o convertLogic.o convertMath.o
	mkdir -p build/bin
	$(CXX) $(CXXFLAGS) $^ -o $@

build/main.o: main.cpp calculate.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/calculateLogic.o: calculateLogic.cpp calculate.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/calculateMath.o: calculateMath.cpp calculate.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/convertLogic.o: convertLogic.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/convertMath.o: convertMath.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rvf build

.PHONY: run
run: build/bin/run
	./build/bin/run
