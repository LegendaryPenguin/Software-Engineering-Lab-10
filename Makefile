# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Executable and source files
TARGET = Main
OBJS = Main.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile Main.cpp to Main.o
Main.o: Main.cpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -c -o Main.o Main.cpp

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
