CHECKER = checker.out

PUSH_SWAP = push_swap.out

LIBFT = ./libft/libft.a

CHECKER_SRC = \
	$(addprefix ./checker/, \
		add_arguments.c \
		checker.c \
		debug.c \
		execute_instructions.c \
		solve_check.c \
	)

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

HEADERS = -I ./checker -I ./push_swap -I ./libft

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(CHECKER_OBJ)
	gcc $(CFLAGS) -o $@ $^

$(PUSH_SWAP): $(LIBFT)
	@echo "no push_swap yet :("

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(LIBFT):
	@echo building libft
	cd ./libft && $(MAKE)

clean:
	rm -f $(CHECKER_OBJ)
	cd ./libft && $(MAKE) fclean
fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all

.PHONY: all clean fclean ./libft/libft.a