/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:41:59 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 13:59:22 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev;

	last = *stack;
	if (!*stack || !(*stack)->next)
		return ;
	while (last->next != 0)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	prev->next = NULL;
}

void	rra(t_list **a)
{
	rev_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}
