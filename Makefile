CC = gcc
AR = ar
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
ARFLAGS = rcs
LDFLAGS = -lstdc++
OUT = libproperty.a
OBJDIR = obj
BUILDDIR = build

all: directories $(OUT)

clean:
	rm -R $(OBJDIR)
	rm -R $(BUILDDIR)

directories: $(OBJDIR) $(BUILDDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OUT): properties.o group_properties.o
	$(AR) $(ARFLAGS) $(BUILDDIR)/$(OUT) $(OBJDIR)/properties.o $(OBJDIR)/group_properties.o

properties.o: properties.cpp
	$(CC) -c properties.cpp $(CXXFLAGS) -o $(OBJDIR)/properties.o 

group_properties.o: group_properties.cpp
	$(CC) -c group_properties.cpp $(CXXFLAGS) -o $(OBJDIR)/group_properties.o