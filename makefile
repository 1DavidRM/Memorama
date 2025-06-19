# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/memorama

# SFML flags
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Lista explícita de archivos fuente
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Ventana.cpp $(SRC_DIR)/Ficha.cpp $(SRC_DIR)/Puntaje.cpp $(SRC_DIR)/Tiempo.cpp $(SRC_DIR)/Interfaz.cpp

# Regla principal
all: $(BIN_DIR) $(TARGET)

# Compilar el ejecutable (todo en un solo comando)
comp: $(BIN_DIR) $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_FLAGS)

# Ejecutar el programa
run: all
	./$(TARGET)

# Limpiar archivos generados
clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: all clean run
