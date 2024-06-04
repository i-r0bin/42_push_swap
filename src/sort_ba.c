/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:15 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:17:15 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_target_ba(t_list **a, t_list **b, t_list *target)
{
	if (*(int *)(target->content + 4) == 0)
		exec_rr_ba(a, b, target);
	else if (*(int *)(target->content + 4) == 1)
		exec_rrr_ba(a, b, target);
	else if (*(int *)(target->content + 4) == 2)
		exec_rrarb_ba(a, b, target);
	else if (*(int *)(target->content + 4) == 3)
		exec_rarrb_ba(a, b, target);
	*(int *)(target->content + 4) = -1;
}

void	exec_rr_ba(t_list **a, t_list **b, t_list *target)
{
	int	n;

	n = *(int *)(target->content);
	while (*(int *)(*b)->content != n && find_pos_a(a, n) > 0)
		rr(a, b);
	while (*(int *)(*b)->content != n)
		rb(b);
	while (find_pos_a(a, n) > 0)
		ra(a);
	pa(a, b);
}

void	exec_rrr_ba(t_list **a, t_list **b, t_list *target)
{
	int	n;

	n = *(int *)(target->content);
	while (*(int *)(*b)->content != n && find_pos_a(a, n) > 0)
		rrr(a, b);
	while (*(int *)(*b)->content != n)
		rrb(b);
	while (find_pos_a(a, n) > 0)
		rra(a);
	pa(a, b);
}

void	exec_rrarb_ba(t_list **a, t_list **b, t_list *target)
{
	int	n;

	n = *(int *)(target->content);
	while (find_pos_a(a, n) > 0)
		rra(a);
	while (*(int *)(*b)->content != n)
		rb(b);
	pa(a, b);
}

void	exec_rarrb_ba(t_list **a, t_list **b, t_list *target)
{
	int	n;

	n = *(int *)(target->content);
	while (find_pos_a(a, n) > 0)
		ra(a);
	while (*(int *)(*a)->content != n)
		rrb(b);
	pa(a, b);
}
