CXX = g++
CXXFLAGS = -g -Wall -Werror

TARGET = tic-tac-toe

all: $(TARGET)

$(TARGET): $(TARGET).cpp
					  $(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
						$(RM) $(TARGET)