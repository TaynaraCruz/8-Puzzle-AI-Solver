CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := puzzle

SOURCES := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*/*.cpp)
OBJECTS := $(SOURCES:%.cpp=$(BUILDDIR)/%.o)
CFLAGS := -g -Wall -O3 -std=c++11 -Wno-unused-result

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean