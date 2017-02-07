CHECKER = checker

PUSH_SWAP = push_swap

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

CHECKER_SRC = \
	$(addprefix ./src/, \
		add_arguments.c \
		checker.c \
		verbose.c \
		execute_instructions.c \
		get_instructions.c \
		solve_check.c \
		free.c \
		$(addprefix instructions/, \
			instr_sa_sb_ss.c \
			instr_pa_pb.c \
			instr_ra_rb_rr.c \
			instr_rra_rrb_rrr.c \
		) \
	)

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PUSH_SWAP_SRC = \
	$(addprefix ./src/, \
		push_swap.c \
		verbose.c \
		add_arguments.c \
		free.c \
		execute_instructions.c \
		solve_check.c \
		$(addprefix solve/, \
			hybrid_sort.c \
			solve.c \
			state.c \
			find_n_smallest.c \
			order_map.c \
			$(addprefix merge_sort/, \
				merge_misc.c \
				merge_sort.c \
				merge_chunks.c \
			) \
		) \
		$(addprefix instructions/, \
			instr_sa_sb_ss.c \
			instr_pa_pb.c \
			instr_ra_rb_rr.c \
			instr_rra_rrb_rrr.c \
		) \
	)

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

HEADERS = -I ./src -I ./libft

CFLAGS = -Wall -Wextra -Werror

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(CHECKER_OBJ)
	gcc $(CFLAGS) -o $@ $^

$(PUSH_SWAP): $(LIBFT) $(PUSH_SWAP_OBJ)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(LIBFT): $(LIBFT_DIR)**/*.c
	@echo building libft
	cd ./libft && $(MAKE)

clean:
	rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	cd ./libft && $(MAKE) fclean
fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all

.PHONY: all clean fclean