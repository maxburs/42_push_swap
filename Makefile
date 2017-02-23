# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 16:04:54 by mburson           #+#    #+#              #
#    Updated: 2017/02/18 16:04:58 by mburson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

CHECKER_SRC = \
	$(addprefix ./src/, \
		$(addprefix shared/, \
			add_arguments.c \
			free.c \
			solve_check.c \
			verbose.c \
			$(addprefix instructions/, \
				instr_sa_sb_ss.c \
				instr_pa_pb.c \
				instr_ra_rb_rr.c \
				instr_rra_rrb_rrr.c \
				init_instr.c \
			) \
		) \
		$(addprefix checker/, \
			checker.c \
			get_instructions.c \
			execute_instructions.c \
		) \
	)

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PUSH_SWAP_SRC = \
	$(addprefix ./src/, \
		$(addprefix shared/, \
			add_arguments.c \
			free.c \
			solve_check.c \
			verbose.c \
			$(addprefix instructions/, \
				instr_sa_sb_ss.c \
				instr_pa_pb.c \
				instr_ra_rb_rr.c \
				instr_rra_rrb_rrr.c \
				init_instr.c \
			) \
		) \
		$(addprefix push_swap/, \
			find_n_smallest.c \
			small_hybrid_sort.c \
			list.c \
			push_swap.c \
			solve.c \
			state_manip.c \
			state_search.c \
			$(addprefix insertion_sort/, \
				insertion_sort.c \
				find_best_path.c \
				how_to_insert.c \
			) \
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

$(LIBFT): force
	@echo building libft
	cd ./libft && $(MAKE)

force:
	@true

clean:
	rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	cd ./libft && $(MAKE) fclean
fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all

.PHONY: all clean fclean re
