# Nome do executável
TARGET = main

# Compilador e flags
CC = gcc
CFLAGS = -Wall -std=c99

# Diretórios
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Bibliotecas e flags específicas da Raylib
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

# Arquivos fontes e objetos
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Regra principal
$(BINDIR)/$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Regra para compilar os arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Limpar tudo (incluindo o executável)
distclean: clean
	rm -rf $(BINDIR)/$(TARGET)

# Regra para compilar e rodar o programa
run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)
