NAME = so_long

ASSETS_DIR = assets
INCLUDES_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR)

SRCS = $(SRC_DIR)/main.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)