/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:57:36 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/20 21:35:14 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_check(t_stack *stack, char **split_number)
{
	if (check_dupes(stack) == true && check_int_minmax(split_number) == true
		&& check_non_int(split_number) == true)
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
			if (tmp2->data.number == tmp->data.number)
				return (false);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (true);
}

bool	check_non_int(char **split_number)
{
	int	j;
	int	i;
	int	check;

	j = 1;
	while (split_number[j])
	{
		i = 0;
		while (split_number[j][i])
		{
			if ((split_number[j][0] == '-' \
				|| split_number[j][0] == '+') && i == 0)
				i++;
			if (split_number[j][i] < '0' || split_number[j][i] > '9')
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

bool	check_int_minmax(char **split_number)
{
	int		i;
	int		j;
	long	number;

	j = 0;
	while (split_number[j])
	{
		i = 0;
		number = 0;
		if (split_number[j][i] == '-')
			i++;
		while (split_number[j][i])
		{
			number *= 10;
			number += split_number[j][i] - '0';
			i++;
			if (number > INT_MAX)
				return (false);
		}
		j++;
	}
	return (true);
}
