NAME = libft.a

OBJS_BOOL = \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \

OBJS_CONVERT = \
	ft_absolute.o \
	ft_atoi.o \
	ft_itoa.o \
	ft_itoa_base.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_utf_16_32.o \
	ft_utf_16_8.o \
	ft_utf_32_8.o \

OBJS_LIST =  \
	ft_lstadd.o \
	ft_lstbadd.o \
	ft_lstdel.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_lstprint.o \

OBJS_LISTM = \
	ft_lstmadd_b.o \
	ft_lstmnew.o \

OBJS_LSTR = \
	ft_lstr_add.o \
	ft_lstr_finish.o \
	ft_lstr_new.o \
	ft_lstr_print.o \

OBJS_MEMORY = \
	ft_memalloc.o \
	ft_memccpy.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memdel.o \
	ft_memdup.o \
	ft_memmove.o \
	ft_memset.o \

OBJS_OTHER = \
	ft_numlen.o \
	ft_numlen_un.o \

OBJS_PUT = \
	ft_putchar.o \
	ft_putchar_fd.o \
	ft_putendl.o \
	ft_putendl_fd.o \
	ft_putnbr.o \
	ft_putnbr_fd.o \
	ft_putstr.o \
	ft_putstr_fd.o \
	ft_putstrw.o \

OBJS_STRING = \
	ft_bzero.o \
	ft_strcat.o \
	ft_strchr.o \
	ft_strchri.o \
	ft_strclr.o \
	ft_strcmp.o \
	ft_strcpy.o \
	ft_strdel.o \
	ft_strdup.o \
	ft_strequ.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlen.o \
	ft_strlenw.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strncat.o \
	ft_strnchr.o \
	ft_strncmp.o \
	ft_strncpy.o \
	ft_strndup.o \
	ft_strnequ.o \
	ft_strnew.o \
	ft_strnstr.o \
	ft_strplace.o \
	ft_strrchr.o \
	ft_strsplit.o \
	ft_strsplitf.o \
	ft_strstr.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_wrdcnt.o \

OBJS = \
	$(addprefix ./bool/,$(OBJS_BOOL)) \
	$(addprefix ./convert/,$(OBJS_CONVERT)) \
	$(addprefix ./list/,$(OBJS_LIST)) \
	$(addprefix ./listm/,$(OBJS_LISTM)) \
	$(addprefix ./lstr/,$(OBJS_LSTR)) \
	$(addprefix ./memory/,$(OBJS_MEMORY)) \
	$(addprefix ./other/,$(OBJS_OTHER)) \
	$(addprefix ./put/,$(OBJS_PUT)) \
	$(addprefix ./string/,$(OBJS_STRING)) \

CFLAGS = -Wall -Wextra
ifndef WNOERROR
	CFLAGS += -Werror
endif
ifdef DEBUG
	CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	gcc $(CFLAGS) -I . -c -o $@ $<

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean debug
