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

#define UNUSED(x) (void)(x)

extern int	g_flags;

int		add_arguments(int argc, char **argv, t_list **a);
int		execute_instructions(t_list **a, t_list **b, char **instr);
int		solve_check(t_list *a, t_list *b);
int		get_instructions(char ***instr_return);

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

#endif
