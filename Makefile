NAME     					= cub3D
CFLAGS   					= -Iincludes -g -Werror -Wextra -Wall
LIBFT 						= ./libs/libft/libft.a
MLX_PATH					=	libs/MLX42/build/libmlx42.a
GLFW_LIBS					= -lglfw
SRC_DIR  					= src
OBJ_DIR  					= obj

MAIN_SRCS 					= main.c
PARSING_SRCS				= parsing_module/parsing.c parsing_module/get_colors.c parsing_module/read_map.c \
									parsing_module/read_map2.c parsing_module/check_map_validity.c
CLEAN_MEMORY_SRCS			= clean_memory_module/clean_memory.c
LAUNCH_GAME_SRCS			= launch_game_module/launch_game.c ray_cast/ray_cast.c init/init.c tex/tex.c \
							ray_cast/draw.c ray_cast/utils_draw.c  ray_cast/utils.c \
							 hook_and_move/hook_move.c hook_and_move/handel_keys.c				
GNL_SRCS					= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c		
UTILS_SRCS					= utils/utils.c

MAIN_OBJS 					= $(patsubst %.c, $(OBJ_DIR)/%.o, $(MAIN_SRCS))
PARSING_OBJS 				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(PARSING_SRCS))
CLEAN_MEMORY_OBJS 			= $(patsubst %.c, $(OBJ_DIR)/%.o, $(CLEAN_MEMORY_SRCS))
LAUNCH_GAME_OBJS			= $(patsubst %.c, $(OBJ_DIR)/%.o, $(LAUNCH_GAME_SRCS))
GNL_OBJS					= $(patsubst %.c, $(OBJ_DIR)/%.o, $(GNL_SRCS))
UTILS_OBJS					= $(patsubst %.c, $(OBJ_DIR)/%.o, $(UTILS_SRCS))

OBJ      					= $(MAIN_OBJS) $(PARSING_OBJS) $(CLEAN_MEMORY_OBJS) $(LAUNCH_GAME_OBJS) $(GNL_OBJS) $(UTILS_OBJS)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	@make -C ./libs/libft --silent
	@make -C ./libs/MLX42/build --silent
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) ${MLX_PATH} $(GLFW_LIBS)

clean:
	@clear
	@make clean -C ./libs/libft --silent
	@rm -rf $(OBJ_DIR)

install:
	cd libs && git clone https://github.com/codam-coding-college/MLX42.git MLX42
	@cd libs/MLX42 && cmake -B build && cmake --build build -j4

fclean: clean
	@make fclean -C ./libs/libft --silent
	@rm -f /libs/MLX42
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
