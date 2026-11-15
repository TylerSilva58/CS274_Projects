CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
PROGRAMS = challenge7_1 challenge7_3 challenge7_4 challenge7_5_demo

.PHONY: all clean test printtest
all: $(PROGRAMS) printtest

challenge7_1: challenge7_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

challenge7_3: challenge7_3.cpp stack.h
	$(CXX) $(CXXFLAGS) -o $@ $<

challenge7_4: challenge7_4.cpp stack7_4.h
	$(CXX) $(CXXFLAGS) -o $@ $<

challenge7_5_demo: challenge7_5.cpp stack7_5.h
	$(CXX) $(CXXFLAGS) -o $@ $<

printtest:
	$(MAKE) -C challenge7_2

test: all
	./challenge7_1
	./challenge7_2/printtest
	./challenge7_3
	./challenge7_4
	./challenge7_5_demo

clean:
	rm -f $(PROGRAMS)
	$(MAKE) -C challenge7_2 clean
