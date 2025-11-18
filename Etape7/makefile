# === Répertoires ===
SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin

# === Fichiers ===
TARGET = $(BIN)/Test7
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

# === Compilation ===
CXX = g++
CXXFLAGS = -Wall -D DEBUG -I $(INC)

# === Règle principale ===
all: $(BIN) $(OBJ) $(TARGET)

# === Lien final ===
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Compilation terminée : $@"
	@echo ""

# === Compilation des .cpp -> .o ===
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compilé : $<"
	@echo ""

clean:
	rm -f $(OBJ)/*.o

clobber: clean
	rm -f $(TARGET)
