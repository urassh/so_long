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
	   $(SRC_DIR)/libft/ft_putstr.c \
	   $(SRC_DIR)/libft/ft_putnbr.c \
	   $(SRC_DIR)/libft/ft_strcmp.c \
	   $(SRC_DIR)/libft/ft_strdup.c \
	   $(SRC_DIR)/libft/ft_strchr.c \
	   $(SRC_DIR)/libft/ft_strjoin.c \
	   $(SRC_DIR)/libft/ft_strlen.c \
	   $(SRC_DIR)/utils/vector2d.c \
	   $(SRC_DIR)/utils/calculate_window_size.c \
	   $(SRC_DIR)/utils/find.c \
	   $(SRC_DIR)/controllers/game_loop.c \
	   $(SRC_DIR)/controllers/player_controller.c \
	   $(SRC_DIR)/models/player/player.c \
	   $(SRC_DIR)/models/player/player_collect.c \
	   $(SRC_DIR)/models/player/player_position.c \
	   $(SRC_DIR)/models/player/player_state.c \
	   $(SRC_DIR)/models/collectible/collectible_state.c \
	   $(SRC_DIR)/models/collectible/add_collectible.c \
	   $(SRC_DIR)/models/collectible/create_collect_state.c \
	   $(SRC_DIR)/models/map/map_model.c \
	   $(SRC_DIR)/models/map/map_loader.c \
	   $(SRC_DIR)/models/map/map_validator.c \
	   $(SRC_DIR)/models/map/validation/validate_rectangular.c \
	   $(SRC_DIR)/models/map/validation/validate_surrounded_by_walls.c \
	   $(SRC_DIR)/models/map/validation/validate_single_player.c \
	   $(SRC_DIR)/models/map/validation/validate_single_exit.c \
	   $(SRC_DIR)/models/map/validation/validate_collectibles_exist.c \
	   $(SRC_DIR)/models/map/validation/validate_clearable.c \
	   $(SRC_DIR)/models/map/validation/validate_valid_characters.c \
	   $(SRC_DIR)/models/game/game_state.c \
	   $(SRC_DIR)/models/game/game_status.c \
	   $(SRC_DIR)/models/game/move_count.c \
	   $(SRC_DIR)/models/game/event/push_game_events.c \
	   $(SRC_DIR)/models/game/load_game_assets.c \
	   $(SRC_DIR)/models/game/create_game.c \
	   $(SRC_DIR)/event/key_events.c \
	   $(SRC_DIR)/event/window_events.c \
	   $(SRC_DIR)/event/event_setup.c \
	   $(SRC_DIR)/event/game_events.c \
	   $(SRC_DIR)/views/renderer.c \
	   $(SRC_DIR)/views/texture.c \
	   $(SRC_DIR)/views/texture_loader.c \
	   $(SRC_DIR)/views/render_map.c \
	   $(SRC_DIR)/views/render_player.c \
	   $(SRC_DIR)/views/render_collectibles.c \
	   $(SRC_DIR)/views/render_exit.c \
	   $(SRC_DIR)/views/screen.c

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
