CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

printtest: main.o printcounter.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp printcounter.h
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp

printcounter.o: printcounter.cpp printcounter.h
	$(CXX) $(CXXFLAGS) -c -o $@ printcounter.cpp

.PHONY: clean
clean:
	rm -f main.o printcounter.o printtest
