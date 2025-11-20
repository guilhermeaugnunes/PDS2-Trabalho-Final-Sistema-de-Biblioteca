# 1. Variáveis
CC=g++
CFLAGS=-std=c++11 -Wall -g

# 2. Diretórios
INCLUDE_DIR=./include
SRC_DIR=./src
BUILD_DIR=./build

# 3. Executável final
TARGET=$(BUILD_DIR)/meu_teste

# 4. Fontes (Pega TODOS os .cpp da pasta src automaticamente)
SOURCES=$(wildcard $(SRC_DIR)/*.cpp)

# 5. Objetos (Troca .cpp por .o e muda a pasta)
OBJS=$(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# 6. Includes
CPPFLAGS=-I$(INCLUDE_DIR)

# 7. Regras Principais
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJS)
	@echo "LN -> Linkando o executável..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilação Genérica (.cpp -> .o)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "CC -> Compilando $<..."
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# --- AQUI ESTÁ O SEU RUN ---
# Depende de $(TARGET), ou seja, se algo mudou, ele recompila antes de rodar.
run: $(TARGET)
	@echo "EX -> Executando..."
	./$(TARGET)

# Limpeza
clean:
	@echo "RM -> Limpando..."
	rm -f $(TARGET) $(BUILD_DIR)/*.o