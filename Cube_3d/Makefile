NAME		=	CUBE3D
CC			=	cc
AR			=	ar rcs
RM			=	rm -rf
# CFLAGS		=	-Wall -Wextra -Werror -g -Iincludes
CFLAGS		=	-Wall -Wextra -Werror -g -I/path/to/minilibx -Iincludes
GLFW_FLAGS	=	-ldl -lglfw -L /Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib
LIBFT_PATH	=	libs/libft/libft.a
MLX_PATH	=	libs/MLX42/build/libmlx42.a
SRC			=	test.c
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

install_brew:
	@echo "\033[36m***༺ (\036[36m\033[36minstalling brew...\033[36m)༻***\n\033[0m"
	@rm -rf $$HOME/.brew && rm -rf $$HOME/goinfre/.brew && \
	git clone --depth=1 https://github.com/Homebrew/brew $$HOME/goinfre/.brew && \
	echo 'export PATH=$$HOME/goinfre/.brew/bin:$$PATH' >> $$HOME/.zshrc && \
	source $$HOME/.zshrc && brew update

install_glfw:
	@echo "\033[36m***༺ (\036[36m\033[36minstalling GLFW...\033[36m)༻***\n\033[0m"
	brew install glfw

install: install_brew install_glfw

clean:
	rm -rf $(OBJ_DIR)
	@make -C ./libs/libft clean --silent
	@make -C ./libs/ft_printf clean --silent
	@make -C ./libs/MLX42/build clean --silent
	clear

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

.PHONY: all install clean fclean re
