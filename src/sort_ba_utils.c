/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ba_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:15:11 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:15:11 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rr_moves_ba(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = find_pos_a(a, *(int *)(target->content));
	if (c < get_pos(b, target))
		c = get_pos(b, target);
	return (c);
}

int	get_rrr_moves_ba(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = 0;
	if (find_pos_a(a, *(int *)(target->content)))
		c = ft_lstsize(*a) - find_pos_a(a, *(int *)(target->content));
	if ((c < (ft_lstsize(*b) - get_pos(b, target))) && get_pos(b, target))
		c = ft_lstsize(*b) - get_pos(b, target);
	return (c);
}

int	get_rrarb_moves_ba(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = 0;
	if (get_pos(b, target))
		c = ft_lstsize(*b) - get_pos(b, target);
	c += find_pos_a(a, *(int *)(target->content));
	return (c);
}

int	get_rarrb_moves_ba(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = 0;
	if (find_pos_a(a, *(int *)(target->content)))
		c = ft_lstsize(*a) - find_pos_a(a, *(int *)(target->content));
	c += get_pos(b, target);
	return (c);
}

int	get_moves_ba(t_list **a, t_list **b, t_list *node, int *code)
{
	int	moves;
	int	c;

	moves = get_rr_moves_ba(a, b, node);
	c = 0;
	if (get_rrr_moves_ba(a, b, node) < moves)
	{
		moves = get_rrr_moves_ba(a, b, node);
		c = 1;
	}
	if (get_rrarb_moves_ba(a, b, node) < moves)
	{
		moves = get_rrarb_moves_ba(a, b, node);
		c = 2;
	}
	if (get_rarrb_moves_ba(a, b, node) < moves)
	{
		moves = get_rarrb_moves_ba(a, b, node);
		c = 3;
	}
	if (*code != -2)
		*code = c;
	return (moves);
}
