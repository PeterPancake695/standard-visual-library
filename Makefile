ifeq ($(OS), Windows_NT)
    CXX = g++
    AR = ar
    CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -march=native -mtune=native -ftree-vectorize
    ARFLAGS = rcs
else
    CXX = g++
    AR = ar
    CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -march=native -mtune=native -ftree-vectorize
    ARFLAGS = rcs
endif

LIBRARY = libsvl.a
SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.cpp)
HDR = $(wildcard $(SRCDIR)/*.hpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(shell mkdir -p $(OBJDIR))

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
		$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HDR)
		mkdir -p $(dir $@)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(LIBRARY)
		rm -rf $(OBJDIR)

.PHONY: all clean

