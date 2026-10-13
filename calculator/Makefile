.PHONY: all clean

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = calc
SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)
