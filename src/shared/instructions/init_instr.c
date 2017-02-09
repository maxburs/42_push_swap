/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:17:48 by mburson           #+#    #+#             */
/*   Updated: 2017/02/08 20:17:50 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_instr(t_state *state)
{
	state->op_func[0] = &exec_sa;
	state->op_func[1] = exec_sb;
	state->op_func[2] = exec_ss;
	state->op_func[3] = exec_pa;
	state->op_func[4] = exec_pb;
	state->op_func[5] = exec_ra;
	state->op_func[6] = exec_rb;
	state->op_func[7] = exec_rr;
	state->op_func[8] = exec_rra;
	state->op_func[9] = exec_rrb;
	state->op_func[10] = exec_rrr;
	state->op_func[11] = NULL;
	state->op[0] = "sa";
	state->op[1] = "sb";
	state->op[2] = "ss";
	state->op[3] = "pa";
	state->op[4] = "pb";
	state->op[5] = "ra";
	state->op[6] = "rb";
	state->op[7] = "rr";
	state->op[8] = "rra";
	state->op[9] = "rrb";
	state->op[10] = "rrr";
	state->op[11] = NULL;
}
