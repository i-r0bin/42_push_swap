/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:26:01 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 13:39:31 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error_and_free(t_list **a)
{
	free_stack(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	handle_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
