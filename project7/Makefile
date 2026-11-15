CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = runprog
OBJS = runprog.o cpu.o

.PHONY: all clean pristine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

runprog.o: runprog.cpp cpu.h stack.h
	$(CXX) $(CXXFLAGS) -c $<

cpu.o: cpu.cpp cpu.h stack.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o

pristine: clean
	rm -f $(TARGET)
