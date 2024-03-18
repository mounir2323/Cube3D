NAME            =    libft.a
CC                =    gcc
CFLAGS            =    -Wall -Wextra -Werror

SRCS			=	ft_isalpha.c    ft_isprint.c    ft_strlen.c     ft_tolower.c\
					ft_bzero.c      ft_isascii.c    ft_memset.c     ft_strrchr.c    ft_toupper.c\
					ft_putchar_fd.c	ft_putstr_fd.c  ft_putendl_fd.c	ft_strlcat.c	ft_memcpy.c\
					ft_isalnum.c    ft_isdigit.c    ft_strchr.c     ft_strlcpy.c 	ft_substr.c\
					ft_memmove.c	ft_memchr.c		ft_strncmp.c	ft_memcmp.c		ft_calloc.c\
					ft_strjoin.c	ft_atoi.c		ft_strdup.c		ft_strnstr.c	ft_strmapi.c\
					ft_striteri.c	ft_itoa.c		ft_putnbr_fd.c	ft_strtrim.c	ft_split.c\
					ft_strlong.c	ft_strcmp.c		ft_strnchr.c

SRCS_BONUS  =	ft_lstnew.c		ft_lstadd_back.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c\
				ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c		ft_lstmap.c		



OBJS            = $(SRCS:.c=.o)

OBJS_BONUS            = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

re: fclean all

$(OBJS): %.o:%.c ft_*.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o:%.c ft_*.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)

.PHONY: all bonus fclean clean re
