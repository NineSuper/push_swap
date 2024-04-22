INC=/usr/include
INCLIB=$(INC)/../lib

NAME = push_swap
SRC = push_swap.c error.c ft_swap.c ft_push_b.c ft_push_a.c ft_rotate.c ft_reverse.c ft_algo.c ft_big_algo.c
OBJ = $(SRC:.c=.o)
CC = gcc

FLAGS = -Wall -Werror -Wextra

# ------------------------------ Colors ------------------------------

BOLD_PURPLE     =       \033[1;35m

BOLD_CYAN       =       \033[1;36m

BOLD_YELLOW     =       \033[1;33m

NO_COLOR        =       \033[0m

# ------------------------------ Messages ------------------------------

COMP_START      =       echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Debut de compilation...\n"

EXE_READY       =       echo "\n📟 Compilation de push_swap reussi !\n"

CLEANED         =       echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Suppression de tous les .o et les filchiers \n"

FCLEANED        =       echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Suppression des fichiers .o et de l'executable \n"

NORM			= 		echo "\n📢 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme de tous les fichiers en .c !\n$(BOLD_PURPLE)"

NORM_H			=		echo "\n📣 $(BOLD_CYAN)NORMINETTE: $(BOLD_YELLOW)Verification de la norme du .h\n$(BOLD_PURPLE)"

# ------------------------------ Rules ------------------------------
MAKEFLAGS += --silent

$(NAME): comp_start $(OBJ)
	@$(CC) $(OBJ) libft/ft_printf/*.c libft/libft/*.c libft/gnl/*.c -o $(NAME)
	@$(EXE_READY)

all: $(NAME) norminette

norminette:
	$(NORM)
	norminette *.c libft/ft_printf/*.c libft/gnl/*.c libft/libft/*.c
	$(NORM_H)
	norminette -R CheckDefine push_swap.h libft/ft_printf/ft_printf.h libft/gnl/get_next_line.h libft/libft/libft.h
	echo "\n"

comp_start:
	@$(COMP_START)

clean:
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean: clean
	$(FCLEANED)

re: clean all
