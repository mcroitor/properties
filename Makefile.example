CC = gcc
AR = ar
DEBUG = # -g -Wall
CXXFLAGS = -O2 -std=c++14 $(DEBUG)
CFLAGS = -O2 $(DEBUG)
ARFLAGS = rcs
LDFLAGS = -lstdc++ -lm
OUT = libproperties.a
OBJDIR = obj
BUILDDIR = build

all: directories $(OUT)

directories: $(OBJDIR) $(BUILDDIR)

clean:
	rm -r $(OBJDIR)
	rm -r $(BUILDDIR)

test: $(OUT)
	$(CC) -c tests/propertiestest.cpp $(CXXFLAGS) -o $(OBJDIR)/propertiestest.o
	$(CC) $(OBJDIR)/propertiestest.o $(OBJDIR)/properties.o -o $(BUILDDIR)/propertiestest $(LDFLAGS)
	$(BUILDDIR)/propertiestest

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OUT):  properties.o
	$(AR) $(ARFLAGS) $(BUILDDIR)/$(OUT) $(OBJDIR)/properties.o


properties.o: properties.cpp
	$(CC) -c properties.cpp $(CXXFLAGS) -o $(OBJDIR)/properties.o
