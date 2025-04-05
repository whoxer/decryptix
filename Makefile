# Compilador
CXX := g++
# Flags de compilação
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
# Flags de depuração
DEBUG_FLAGS := -g -O0 -DDEBUG
# Flags de release
RELEASE_FLAGS := -O3 -DNDEBUG

# Nome do executável
DEBUG_TARGET := bin/debug
RELEASE_TARGET := bin/release

# Diretórios
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Arquivos fonte e objetos
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Regra padrão
all: release

# Regra para build de debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(DEBUG_TARGET)

# Regra para build de release
release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(RELEASE_TARGET)

$(DEBUG_TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(RELEASE_TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para documentação (Doxygen)
docs:
	doxygen docs/Doxyfile

# Regra para rodar o debugger
run-debug: debug
	gdb $(DEBUG_TARGET)

# Limpar build
clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

.PHONY: all debug release docs clean run-debug