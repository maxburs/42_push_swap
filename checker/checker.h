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

extern int	g_flags;

int		add_arguments(int argc, char **argv, t_list **a);
int		execute_instructions(t_list **a, t_list **b, char **instr);
int		solve_check(t_list *a, t_list *b);
int		get_instructions(char ***instr_return);


void	print_stack(t_list *stack);
void	print_instructions(char **instr);

#endif
