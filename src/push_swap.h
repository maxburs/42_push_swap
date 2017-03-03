/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:44:36 by mburson           #+#    #+#             */
/*   Updated: 2017/01/29 22:44:38 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# define BUFF_SIZE 8

# define FLAG_VERBOSE 0x1

# define STACK_A 1
# define STACK_B 0

# define UNUSED(x) (void)(x)

/*
** sa : swap a - swap the first 2 elements at the top of stack a. Do nothing
**         if there is only one or ** no elements).
** sb : swap b - swap the first 2 elements at the top of stack b. Do nothing
**         if there is only one or ** no elements).
** ss : sa and sb at the same time.
** pa : push a - take the first element at the top of b and put it at the top
**         of a. Do nothing if b is empty.
** pb : push b - take the first element at the top of a and put it at the top
**         of b. Do nothing if a is empty.
** ra : rotate a - shift up all elements of stack a by 1. The first element
**         becomes the last one.
** rb : rotate b - shift up all elements of stack b by 1. The first element
**         becomes the last one.
** rr : ra and rb at the same time.
** rra : reverse rotate a - shift down all elements of stack a by 1. The flast
**          element becomes the ** first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1. The flast
**          element becomes the ** first one.
** rrr : rra and rrb at the same time.
*/
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct				s_state
{
	t_list		**instr;
	t_list		**a;
	t_list		**b;
	_Bool		verbose;
	int			(*op_func[12])(t_list **a, t_list **b);
	char		*op[12];
}							t_state;

int							execute_instructions(t_state *state, t_list **a,
									t_list **b, char **instr);
void						init_instr(t_state *state);
int							get_instructions(char ***instr_return,
								_Bool verbose);
void						sort_3(t_state *state, int stack_type);

/*
** solve_check.c
*/
int							solve_check(t_list *a, t_list *b);
int							stack_in_order(t_list *stack);

/*
** add_arguments.c
*/
int							add_arguments(int argc, char **argv, t_list **a,
								_Bool *verbose);

/*
** free.c
*/
void						free_instructions(char ***instr);
void						free_stack(t_list **stack);

/*
** instructions/
*/
int							exec_sa(t_list **a, t_list **b);
int							exec_sb(t_list **a, t_list **b);
int							exec_ss(t_list **a, t_list **b);
int							exec_pa(t_list **a, t_list **b);
int							exec_pb(t_list **a, t_list **b);
int							exec_ra(t_list **a, t_list **b);
int							exec_rb(t_list **a, t_list **b);
int							exec_rr(t_list **a, t_list **b);
int							exec_rra(t_list **a, t_list **b);
int							exec_rrb(t_list **a, t_list **b);
int							exec_rrr(t_list **a, t_list **b);

/*
** verbose.c (-v)
*/
void						print_starting_stack(t_list *stack, _Bool verbose);
void						print_instructions(char **instr, _Bool verbose);
void						print_stacks(t_list *a, t_list *b, _Bool verbose);
void						print_instr_res(t_list **a, t_list **b,
								char const *instr, _Bool verbose);
void						print_stack(t_list *stack, _Bool verbose);

/*
** solve/
*/
t_list						*find_n_smallest(t_list *stack, int n);
int							nth_smallest(t_list *stack, int n);

/*
** solve.c
*/
int							top_of_stack(t_state *state, int stack_type);
int							next_in_stack(t_state *state, int stack_type);
t_list						**stack_of_type(t_state *state, int stack_type);
int							solve(t_state *state);

/*
** state_manip.c
*/
int							exec_instr(t_state *state, int instr);
int							exec_n_instr(t_state *state, int instr, int n);

/*
** state_search.c
*/
int							path_to_smallest(t_state *state, int stack_type);
int							last_in_stack(t_state *state, int stack_type);
int							path_to_end(t_state *state, int stack_type);
int							find_smallest(t_state *state, int stack_type);
int							find_biggest(t_state *state, int stack_type);

/*
** list.c
*/
int							lst_is_order(t_list *stack, int smallest);
int							lst_fnd_sml(t_list *stack);
int							lst_fnd_big(t_list *stack);
t_list						*ft_lst_last(t_list *stack);
int							lst_size(t_list *stack);

/*
** insertion_sort/
*/
typedef enum				e_direction
{
	FORWARD,
	BACKWARD
}							t_dir;

/*
** a path is made up of an offset on stack a and an offset on stack b
*/

typedef struct				s_path
{
	size_t		a_len;
	t_dir		a_dir;
	size_t		b_len;
	t_dir		b_dir;
}							t_path;

typedef struct				s_paths_meta
{
	size_t		best_op_time;
	t_path		best_path;
	t_path		new_path;
	size_t		a_forward;
	size_t		a_backward;
	size_t		b_forward;
	size_t		b_backward;
}							t_paths_meta;

int							insertion_sort(t_state *state);
t_path						find_best_path(t_state *state);
void						how_to_insert(t_list *stack, int insert_me,
								size_t *forward_path, size_t *backwards_path);
void						print_path(t_path path);

#endif
