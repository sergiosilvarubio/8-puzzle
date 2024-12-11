# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17
OUTPUT_DIR = output
TARGET = $(OUTPUT_DIR)/8-puzzle-game
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJ)
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -f $(OBJ) $(TARGET)
