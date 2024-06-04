/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:16:30 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:16:30 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rr_moves_ab(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = find_pos_b(b, *(int *)(target->content));
	if (c < get_pos(a, target))
		c = get_pos(a, target);
	return (c);
}

int	get_rrr_moves_ab(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = 0;
	if (find_pos_b(b, *(int *)(target->content)))
		c = ft_lstsize(*b) - find_pos_b(b, *(int *)(target->content));
	if ((c < (ft_lstsize(*a) - get_pos(a, target))) && get_pos(a, target))
		c = ft_lstsize(*a) - get_pos(a, target);
	return (c);
}

int	get_rrarb_moves_ab(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = 0;
	if (get_pos(a, target))
		c = ft_lstsize(*a) - get_pos(a, target);
	c += find_pos_b(b, *(int *)(target->content));
	return (c);
}

int	get_rarrb_moves_ab(t_list **a, t_list **b, t_list *target)
{
	int	c;

	c = 0;
	if (find_pos_b(b, *(int *)(target->content)))
		c = ft_lstsize(*b) - find_pos_b(b, *(int *)(target->content));
	c += get_pos(a, target);
	return (c);
}

int	get_moves_ab(t_list **a, t_list **b, t_list *target, int *code)
{
	int	moves;
	int	c;

	moves = get_rr_moves_ab(a, b, target);
	c = 0;
	if (get_rrr_moves_ab(a, b, target) < moves)
	{
		moves = get_rrr_moves_ab(a, b, target);
		c = 1;
	}
	if (get_rrarb_moves_ab(a, b, target) < moves)
	{
		moves = get_rrarb_moves_ab(a, b, target);
		c = 2;
	}
	if (get_rarrb_moves_ab(a, b, target) < moves)
	{
		moves = get_rarrb_moves_ab(a, b, target);
		c = 3;
	}
	if (*code != -2)
		*code = c;
	return (moves);
}
