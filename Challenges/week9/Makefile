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

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< 