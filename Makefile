DEBUG	=	1

NAME	=	fdf
INC_DIR	=	src
SRC_DIR	=	src
OBJ_DIR	=	obj
INC	  	=	$(addprefix $(INC_DIR)/,	fdf.h)
SRC	  	=	$(addprefix $(SRC_DIR)/,	main.c		\
																		render.c	\
																		get_next_line/get_next_line_utils.c	\
																		get_next_line/get_next_line.c)
OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_A =	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror -O3
CINC	=	-I./libft -I./minilibx
LFLAGS	=	-O3
LLIB	=	-L./libft -lft -L./minilibx -lmlx -lm -lXext -lX11

ifeq ($(DEBUG), 1)
	CFLAGS	+=	-g3 -fsanitize=address
	LFLAGS	+=	-g3 -fsanitize=address
endif

all: libft $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) $(LLIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CINC) -c $< -o $@

libft:
	make -C ./libft

run:
	@clear
	@make -s
	@./fdf ./maps/test_maps/42.fdf

re: fclean all

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

print:
	@echo "\n-------------------- FILES --------------------\n"
	@echo "NAME		$(NAME:%=\n%)\n"
	@echo "INC		$(INC:%=\n%)\n"
	@echo "SRC		$(SRC:%=\n%)\n"
	@echo "OBJ		$(OBJ:%=\n%)\n"
	@echo "\n-------------------- FLAGS --------------------\n"
	@echo "LLIB		$(LLIB:%=\n%)\n"
	@echo "LFLAGS	$(LFLAGS:%=\n%)\n"
	@echo "CFLAGS	$(CFLAGS:%=\n%)\n"
	@echo "CINC		$(CINC:%=\n%)\n"

.PHONY: all libft re clean fclean print
