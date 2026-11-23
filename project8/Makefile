CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: shapes

shapes: shapes.o shape.o
	$(CXX) $(CXXFLAGS) -o shapes shapes.o shape.o

shapes.o: shapes.cpp shape.h
	$(CXX) $(CXXFLAGS) -c shapes.cpp

shape.o: shape.cpp shape.h
	$(CXX) $(CXXFLAGS) -c shape.cpp

clean:
	rm -f *.o shapes

.PHONY: all clean
