CC = gcc
AR = ar
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
ARFLAGS = rcs
LDFLAGS = -lstdc++
OUT = libproperties.a
OBJDIR = obj
BUILDDIR = build
TESTDIR = tests

all: directories $(OUT)

clean:
	rm -R $(OBJDIR)
	rm -R $(BUILDDIR)

test: 
	$(CC) -o$(BUILDDIR)/propertiestest $(TESTDIR)/propertiestest.cpp -lproperties -lstdc++ -L$(BUILDDIR) -I.
	./$(BUILDDIR)/propertiestest
	$(CC) -o$(BUILDDIR)/groupstest $(TESTDIR)/groupstest.cpp -lproperties -lstdc++ -L$(BUILDDIR) -I.
	./$(BUILDDIR)/groupstest

directories: $(OBJDIR) $(BUILDDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OUT): additional.o properties.o group_properties.o
	$(AR) $(ARFLAGS) $(BUILDDIR)/$(OUT) $(OBJDIR)/additional.o $(OBJDIR)/group_properties.o $(OBJDIR)/properties.o

additional.o: additional.cpp
	$(CC) -c additional.cpp $(CXXFLAGS) -o $(OBJDIR)/additional.o
	
properties.o: properties.cpp
	$(CC) -c properties.cpp $(CXXFLAGS) -o $(OBJDIR)/properties.o 

group_properties.o: group_properties.cpp
	$(CC) -c group_properties.cpp $(CXXFLAGS) -o $(OBJDIR)/group_properties.o