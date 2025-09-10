NAME = so_long

ASSETS_DIR = assets
INCLUDES_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

HEADERS = 

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR)

SRCS = $(SRC_DIR)/main.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@cc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) $(NAME) created successfully!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@

%:
	@:

clean:
	@if [ -d $(OBJDIR) ]; then \
		echo "$(RED)Removing object files...$(NC)"; \
		rm -rf $(OBJDIR); \
		echo "$(GREEN) Object files removed!$(NC)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)Removing $(NAME)...$(NC)"; \
		rm -f $(NAME); \
		echo "$(GREEN) $(NAME) removed!$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re

.PRECIOUS: $(OBJDIR)/%.o
