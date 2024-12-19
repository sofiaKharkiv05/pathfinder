PATHFINDER = pathfinder

CFLAGS  = -std=c11 -Wall -Wextra -Werror -Wpedantic
CC      = clang

SRC_DIR  = src
INC_DIR  = inc
OBJ_DIR  = obj

INC      = $(INC_DIR)/pathfinder.h
SRC      = $(wildcard $(SRC_DIR)/*.c)
OBJ      = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB_DIR  = libmx
LIB_MX   = $(LIB_DIR)/libmx.a

all: install

install: $(LIB_MX) $(PATHFINDER)

$(PATHFINDER): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIB_DIR) -lmx -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@mkdir -p $(OBJ_DIR) 
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIB_DIR)/inc

$(LIB_MX):
	@make -sC $(LIB_DIR)

clean:
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) uninstall
	@rm -rf $(OBJ_DIR) $(PATHFINDER)

reinstall: uninstall all




