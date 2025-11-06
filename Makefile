# 1. Variáveis para o compilador e flags
CC=g++
CFLAGS=-std=c++11 -Wall

INCLUDE_DIR=./include
SRC_DIR=./src
BUILD_DIR=./build

TARGET=$(BUILD_DIR)/meu_teste

SOURCES=$(SRC_DIR)/main.cpp $(SRC_DIR)/Usuario.cpp $(SRC_DIR)/Aluno.cpp $(SRC_DIR)/Professor.cpp

OBJS=$(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CPPFLAGS=-I$(INCLUDE_DIR)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "LN -> Linkando o executável..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "CC -> Compilando $<..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "RM -> Removendo arquivos de build..."
	rm -f $(TARGET) $(BUILD_DIR)/*.o