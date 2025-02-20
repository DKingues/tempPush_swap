/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:32:30 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/20 21:33:49 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	t_stack	*temp;
	int		biggest_number;

	temp = stack;
	biggest_number = INT_MIN;
	while (temp)
	{
		if (temp->data.number > biggest_number)
			biggest_number = temp->data.number;
		temp = temp->next;
	}
	return (biggest_number);
}

int	find_min(t_stack *stack)
{
	t_stack	*temp;
	int		smallest_number;

	temp = stack;
	smallest_number = INT_MAX;
	while (temp)
	{
		if (temp->data.number < smallest_number)
			smallest_number = temp->data.number;
		temp = temp->next;
	}
	return (smallest_number);
}

void	initialize_stack(t_stack **a, t_stack **b)
{
	*a = NULL;
	*b = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*aux;

	temp = *stack;
	while (temp)
	{
		aux = temp;
		temp = temp->next;
		aux->data.above_median = NULL;
		aux->data.cheapest = NULL;
		aux->data.push_cost = 0;
		aux->data.index = 0;
		aux->data.number = 0;
		free(aux);
	}
	*stack = NULL;
}

void	current_index_r(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
}
