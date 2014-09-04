CXX=g++
CXXFLAGS=-c -Wall -I. 
LDFLAGS=
SOURCES=main.cpp args.cpp digitstonumbers.cpp calculate.cpp types.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ticket

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
