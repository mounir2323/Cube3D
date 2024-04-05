NAME		=	CUBE3D
CC			=	cc
AR			=	ar rcs
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g -I/path/to/minilibx -Iincludes -O3 -ffast-math
GLFW_FLAGS	=	-ldl -lglfw 
LIBFT_PATH	=	libs/libft/libft.a
MLX_PATH	=	libs/MLX42/build/libmlx42.a
# SRC			=	main.c src/init.c test.c ft_getmap.c src/raycast.c src/mytest.c
SRC			=	main.c 
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR		=	obj

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@${CC} ${OBJ} -o ${NAME} ${LIBFT_PATH} ${MLX_PATH}  ${CFLAGS} ${GLFW_FLAGS}
	@echo "\033[31m------------------***༺ (\033[31m\033[32mCUBE 3D Compiled!\033[31m)༻***------------------\n\033[0m"

$(MLX_PATH):
	@cd ./libs/MLX42 && cmake -S . -B build && cmake --build build -j4
	@echo "\033[31m------------------***༺ (\033[31m\033[32mMLX Generated!\033[31m)༻***------------------\n\033[0m"
	clear

$(LIBFT_PATH):
	@make -C ./libs/libft --silent

clean:
	rm -rf $(OBJ_DIR)
	@make -C ./libs/libft clean --silent
	# @make -C ./libs/MLX42/build clean --silent
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: all install clean fclean re
