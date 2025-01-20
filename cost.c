/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:04 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/20 18:47:15 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *node)
{
	int	i;

	i = 0;
	while (node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

bool	above_median(t_stack *node)
{
	int	size;
	int	median;
	
	median = stack_size(node) / 2;
	
	if (node->data.index > median)
		return (1);
	else
		return (0);
}
