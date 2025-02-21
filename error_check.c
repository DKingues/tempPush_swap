/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:57:36 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:57:15 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_check(t_stack *stack, char **split_nbr)
{
	if (check_dupes(stack) == true && check_int_minmax(split_nbr) == true
		&& check_non_int(split_nbr) == true)
		return (true);
	else
		return (false);
}

bool	check_dupes(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->data.nbr == tmp->data.nbr)
				return (false);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (true);
}

bool	check_non_int(char **split_nbr)
{
	int	j;
	int	i;
	int	check;

	j = 1;
	while (split_nbr[j])
	{
		i = 0;
		while (split_nbr[j][i])
		{
			if ((split_nbr[j][0] == '-' \
				|| split_nbr[j][0] == '+') && i == 0)
				i++;
			if (split_nbr[j][i] < '0' || split_nbr[j][i] > '9')
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

bool	check_int_minmax(char **split_nbr)
{
	int		i;
	int		j;
	long	nbr;

	j = 0;
	while (split_nbr[j])
	{
		i = 0;
		nbr = 0;
		if (split_nbr[j][i] == '-')
			i++;
		while (split_nbr[j][i])
		{
			nbr *= 10;
			nbr += split_nbr[j][i] - '0';
			i++;
			if (nbr > INT_MAX)
				return (false);
		}
		j++;
	}
	return (true);
}
