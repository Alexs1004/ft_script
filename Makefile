NAME        = ft_script
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinc -Ilibft

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/pty.c \
              $(SRC_DIR)/terminal.c \
              $(SRC_DIR)/multiplex.c \
              $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/exec.c \
			  $(SRC_DIR)/signal.c

OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re