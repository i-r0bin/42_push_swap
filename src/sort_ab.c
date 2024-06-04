/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:16:56 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:16:56 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_target_ab(t_list **a, t_list **b, t_list *target)
{
	if (*(int *)(target->content + 4) == 0)
		exec_rr_ab(a, b, target);
	else if (*(int *)(target->content + 4) == 1)
		exec_rrr_ab(a, b, target);
	else if (*(int *)(target->content + 4) == 2)
		exec_rrarb_ab(a, b, target);
	else if (*(int *)(target->content + 4) == 3)
		exec_rarrb_ab(a, b, target);
	*(int *)(target->content + 4) = -1;
}

void	exec_rr_ab(t_list **a, t_list **b, t_list *target)
{
	while (*a != target && find_pos_b(b, *(int *)(target->content)) > 0)
		rr(a, b);
	while (*a != target)
		ra(a);
	while (find_pos_b(b, *(int *)(target->content)) > 0)
		rb(b);
	pb(a, b);
}

void	exec_rrr_ab(t_list **a, t_list **b, t_list *target)
{
	while (*a != target && find_pos_b(b, *(int *)(target->content)) > 0)
		rrr(a, b);
	while (*a != target)
		rra(a);
	while (find_pos_b(b, *(int *)(target->content)) > 0)
		rrb(b);
	pb(a, b);
}

void	exec_rrarb_ab(t_list **a, t_list **b, t_list *target)
{
	while (*a != target)
		rra(a);
	while (find_pos_b(b, *(int *)(target->content)) > 0)
		rb(b);
	pb(a, b);
}

void	exec_rarrb_ab(t_list **a, t_list **b, t_list *target)
{
	while (*a != target)
		ra(a);
	while (find_pos_b(b, *(int *)(target->content)) > 0)
		rrb(b);
	pb(a, b);
}
