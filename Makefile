ifeq ($(OS), Windows_NT)
  CXX = g++
  CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -march=native -mtune=native -ftree-vectorize -DSVL_BUILD_LIB -I ./vendor/spdlog/include
  LIBRARY = libsvl.dll
  LDFLAGS = -shared
  INSTALL =	
else
  CXX = g++
  CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -march=native -mtune=native -ftree-vectorize -fPIC -DSVL_BUILD_LIB -I ./vendor/spdlog/include
  LIBRARY = libsvl.so
  LDFLAGS = -shared
  INSTALL = sudo cp libsvl.so /usr/lib/libsvl.so
endif

SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.cpp)
HDR = $(wildcard $(SRCDIR)/*.hpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(shell mkdir -p $(OBJDIR))

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HDR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(LIBRARY)
	rm -rf $(OBJDIR)

install: all
	$(INSTALL)

.PHONY: all clean install

