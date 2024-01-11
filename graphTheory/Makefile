# Compiler and flags
CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Wextra

# Executable name
EXEC = HW4

# List of source files
SRC_FILES = Graph.cpp HW4.cpp

# Derive object files from source files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES)

# Rule to build object files from source files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ_FILES) $(EXEC)