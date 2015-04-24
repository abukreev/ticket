CXX=g++
SRCDIR=src
OBJDIR=obj
BINDIR=bin
CXXFLAGS= -g -c -Wall -I$(SRCDIR) -Icommfrac/include
LDFLAGS=
LIBCOMMFRAC=commfrac/lib/libcommfrac.a
SOURCE_FILES=main.cpp args.cpp digitstonumbers.cpp calculate.cpp numtext.cpp config.cpp results.cpp 
SOURCES=$(patsubst %.cpp,$(SRCDIR)/%.cpp,$(SOURCE_FILES))
OBJECT_FILES=$(patsubst %.cpp,%.o,$(SOURCE_FILES))
OBJECTS=$(patsubst %.o,$(OBJDIR)/%.o,$(OBJECT_FILES))

EXECUTABLE=$(BINDIR)/ticket

all: $(SOURCES) $(LIBCOMMFRAC) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJDIR) $(OBJECTS) $(BINDIR)
	$(CXX) $(LDFLAGS) $(OBJECTS) $(LIBCOMMFRAC) -o $@

$(LIBCOMMFRAC):
	cd commfrac && make -f Makefile.lib

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -f $(OBJECTS)
	cd commfrac && make -f Makefile.lib clean
