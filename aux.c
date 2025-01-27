/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:04 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/24 18:56:51 by dicosta-         ###   ########.fr       */
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

void	initialize_stack(t_stack *a, t_stack *b)
{
	a = ft_calloc(sizeof(t_stack), 1);
	b = ft_calloc(sizeof(t_stack), 1);
	if (!a || !b)
    	return ;
	a->data.number = 0;
	a->data.index = 0;
	a->data.cheapest = NULL;
	a->data.above_median = NULL;
	a->data.push_cost = 0;
	b->data.number = 0;
	b->data.index = 0;
	b->data.cheapest = NULL;
	b->data.above_median = NULL;
	b->data.push_cost = 0;
}

int error_check(t_stack **stack, int n)
{
	if(!stack)
		return	;
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if(temp->data.number > INT_MAX || temp->data.number < INT_MIN || temp->data.number == n)
		{
			printf("Error\n");
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
