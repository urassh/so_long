NAME = so_long

ASSETS_DIR = assets
INCLUDES_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = minilibx_opengl_20191021

HEADERS = 

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR) -I$(MLX_DIR)
# macOS用のフラグ
LIBFLAGS_MACOS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# Linux用のフラグ
LIBFLAGS_LINUX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# OSを検出
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LIBFLAGS = $(LIBFLAGS_MACOS)
else
	LIBFLAGS = $(LIBFLAGS_LINUX)
endif

SRCS = $(SRC_DIR)/main.c \
	   $(SRC_DIR)/libft/ft_get_next_line.c \
	   $(SRC_DIR)/libft/ft_calloc.c \
	   $(SRC_DIR)/libft/ft_strcmp.c \
	   $(SRC_DIR)/libft/ft_strdup.c \
	   $(SRC_DIR)/libft/ft_strchr.c \
	   $(SRC_DIR)/libft/ft_strjoin.c \
	   $(SRC_DIR)/libft/ft_strlen.c \
	   $(SRC_DIR)/map/load_map.c \
	   $(SRC_DIR)/map/free_map.c \
	   $(SRC_DIR)/map/init_map.c \
	   $(SRC_DIR)/map/validate_map.c \
	   $(SRC_DIR)/map/duplicate_map.c \
	   $(SRC_DIR)/map/rules/validate_rectangular.c \
	   $(SRC_DIR)/map/rules/validate_surrounded_by_walls.c \
	   $(SRC_DIR)/map/rules/validate_single_player.c \
	   $(SRC_DIR)/map/rules/validate_single_exit.c \
	   $(SRC_DIR)/map/rules/validate_collectibles_exist.c \
	   $(SRC_DIR)/map/rules/validate_clearable.c \
	   $(SRC_DIR)/map/rules/validate_valid_characters.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(MLX_DIR)/libmlx.a:
	@echo "$(YELLOW)Building minilibx...$(NC)"
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN)Minilibx built successfully!$(NC)"

$(NAME): $(MLX_DIR)/libmlx.a $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@cc $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

%:
	@:

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "$(RED)Removing object files...$(NC)"; \
		rm -rf $(OBJ_DIR); \
		echo "$(GREEN) Object files removed!$(NC)"; \
	fi
	@echo "$(YELLOW)Cleaning minilibx...$(NC)"
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "$(GREEN)Minilibx cleaned!$(NC)"

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)Removing $(NAME)...$(NC)"; \
		rm -f $(NAME); \
		echo "$(GREEN) $(NAME) removed!$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re

.PRECIOUS: $(OBJ_DIR)/%.o
