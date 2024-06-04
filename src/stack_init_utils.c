/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:17:58 by rilliano          #+#    #+#             */
/*   Updated: 2024/03/10 14:18:05 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;
	int	count_nbr;

	count_nbr = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count_nbr++;
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ' ' && !((i == 0 || str[i - 1] == ' ')
					&& (str[i] == '+' || str[i] == '-')))
				return (0);
		}
		i++;
	}
	return (count_nbr);
}

int	check_overflow(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

int	check_unique(t_list *a, int n)
{
	int	*tmp;

	if (!a)
		return (1);
	while (a)
	{
		tmp = (int *)a->content;
		if (tmp[0] == n)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}
