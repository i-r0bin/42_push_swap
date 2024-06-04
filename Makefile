S = src/
O = obj/
I = ./
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIB = -L$(LIBFT_PATH) -lft
INC = -I$(LIBFT_PATH) -I$I

SRC = \
	$Spush_swap.c \
	$Sstack_utils.c \
	$Sstack_init.c \
	$Sstack_init_utils.c \
	$Ssort.c \
	$Ssort_utils.c \
	$Ssort_ab.c \
	$Ssort_ab_utils.c \
	$Ssort_ba.c \
	$Ssort_ba_utils.c \
	$Shandle_error.c \
	$Spush.c \
	$Srev_rotate.c \
	$Srotate.c \
	$Sswap.c 

OBJ = $(SRC:$S%.c=$O%.o)

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
RMDIR = rmdir

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$O:
	mkdir -p $@

$(OBJ): | $O

$O%.o: $S%.c
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)
	$(RMDIR) $O

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re