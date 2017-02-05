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

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>

# define BUFF_SIZE 8

# define FLAG_VERBOSE 0x1

# define UNUSED(x) (void)(x)

/*
** sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or ** no elements).
** sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or ** no elements).
** ss : sa and sb at the same time.
** pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
** pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
** ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
** rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
** rr : ra and rb at the same time.
** rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the ** first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the ** first one.
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


typedef struct	s_state
{
	t_list	**instr;
	t_list	**a;
	t_list	**b;
}				t_state;

extern int					g_flags;
extern const char * const 	g_instr[];
extern int (* const			g_func[])(t_list **a, t_list **b);

int		execute_instructions(t_list **a, t_list **b, char **instr);
int		get_instructions(char ***instr_return);

/*
** solve_check.c
*/
int		solve_check(t_list *a, t_list *b);
int		stack_in_order(t_list *stack);

/*
** add_arguments.c
*/
int		add_arguments(int argc, char **argv, t_list **a);

/*
** /solve/
*/
int		solve(t_list **instr, t_list **a, t_list **b);
int		path_to_smallest(t_list *stack);
int		find_smallest(t_list *stack);

/*
** free.c
*/
void	free_instructions(char ***instr);
void	free_stack(t_list **stack);

/*
** ./instructions/
*/
int		exec_sa(t_list **a, t_list **b);
int		exec_sb(t_list **a, t_list **b);
int		exec_ss(t_list **a, t_list **b);
int		exec_pa(t_list **a, t_list **b);
int		exec_pb(t_list **a, t_list **b);
int		exec_ra(t_list **a, t_list **b);
int		exec_rb(t_list **a, t_list **b);
int		exec_rr(t_list **a, t_list **b);
int		exec_rra(t_list **a, t_list **b);
int		exec_rrb(t_list **a, t_list **b);
int		exec_rrr(t_list **a, t_list **b);

/*
** verbose.c (-v)
*/
void	print_starting_stack(t_list *stack);
void	print_instructions(char **instr);
void	print_stacks(t_list *a, t_list *b);
void	print_instr_res(t_list **a, t_list **b, char const *instr);

#endif
