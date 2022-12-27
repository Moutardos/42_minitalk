CC = cc
AR= ar
NAME = libft.a
SRC = ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c\
ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c ft_split.c ft_strdup.c\
ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_tolower.c\
ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c\
ft_memset.c  ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c ft_striteri.c ft_strlcat.c\
ft_strlen.c  ft_strncmp.c ft_strrchr.c ft_substr.c  ft_toupper.c ft_isspace.c\
ft_itob.c ft_itohexa.c ft_strlow.c ft_strup.c ft_cinstr.c ft_strmap.c ft_striter.c\
ft_puthex_fd.c ft_putnbru_fd.c ft_pow.c ft_printf/ft_printf.c ft_printf/convert.c
OBJ = $(SRC:.c=.o)
BONUS = ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c\
ft_lstmap.c ft_lstiter.c ft_lstlast.c ft_lstsize.c
BONUS_OBJ = $(BONUS:.c=.o)
RM = rm -f
LIBFLAGS = -rc
CFLAGS = -Wall -Wextra -Werror -o

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $@ -c $<

$(NAME) : $(OBJ)
	$(AR) $(LIBFLAGS) $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)
	
fclean : clean
	$(RM) $(NAME)
	$(RM) test

re: fclean all

bonus: $(BONUS_OBJ)
	$(AR) $(LIBFLAGS) $(NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re test bonus so
