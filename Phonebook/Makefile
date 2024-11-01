CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = main.cpp phonebook.cpp EncryptionMethods.cpp Login.cpp Records.cpp Bypass.cpp Menu.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = phonebookApp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
