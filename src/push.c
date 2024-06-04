/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:41:29 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:05:02 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*to_push;

	if (!*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, to_push);
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
