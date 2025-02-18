/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:04 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/13 21:52:17 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		median;

	if (!stack)
		return ;
	i = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->data.index = i;
		if (stack->data.index < median)
			stack->data.above_median = false;
		else if (stack->data.index > median)
			stack->data.above_median = true;
		i++;
		stack = stack->next;
	}
}

void	push_cost(t_stack **a, t_stack **b)
{
	int		cost;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	if (!*a || !a || !*b || !b)
		return ;
	while (tmp_a)
	{
		cost = 0;
		tmp_b = *b;
		if (tmp_a->data.above_median == 0)
			cost = tmp_a->data.index;
		if (tmp_a->data.above_median == 1)
			cost = stack_size(*a) - tmp_a->data.index;
		while (tmp_b->data.number != target_node(tmp_a, tmp_b))
			tmp_b = tmp_b->next;
		if (tmp_b->data.above_median == 0)
			cost += tmp_b->data.index;
		if (tmp_b->data.above_median == 1)
			cost += stack_size(*b) - tmp_b->data.index;
		tmp_a->data.push_cost = cost;
		tmp_a = tmp_a->next;
	}
}

int	target_node(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		best_target;

	temp_a = a;
	temp_b = b;
	best_target = INT_MIN;
	while (temp_b)
	{
		if (temp_a->data.number > temp_b->data.number \
		&& best_target < temp_b->data.number)
			best_target = temp_b->data.number;
		temp_b = temp_b->next;
	}
	if (best_target == INT_MIN)
		best_target = find_max(b);
	return (best_target);
}

int	target_node_b(t_stack *b, t_stack *a)
{
	t_stack	*temp_b;
	t_stack	*temp_a;
	int		best_target;

	temp_a = a;
	temp_b = b;
	best_target = INT_MAX;
	while (temp_a)
	{
		if (temp_b->data.number < temp_a->data.number && \
		best_target > temp_a->data.number)
			best_target = temp_a->data.number;
		temp_a = temp_a->next;
	}
	if (best_target == INT_MAX)
		best_target = find_min(b);
	return (best_target);
}

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
	smallest_number = INT_MIN;
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
