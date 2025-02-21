/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:04 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:56:50 by dicosta-         ###   ########.fr       */
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
	t_stack	*tp_a;
	t_stack	*tp_b;

	if (!a || !*a || !b || !*b)
		return ;
	tp_a = *a;
	while (tp_a)
	{
		cost = 0;
		tp_b = *b;
		cost = cost_calc(tp_a, a);
		while (tp_b->data.nbr != target_node(tp_a, tp_b))
			tp_b = tp_b->next;
		cost += cost_calc(tp_b, b);
		if (tp_a->data.above_median == tp_b->data.above_median && \
		stack_size(*a) - tp_a->data.index == stack_size(*b) - tp_b->data.index)
			cost /= 2;
		tp_a->data.push_cost = cost;
		tp_a = tp_a->next;
	}
}

int	cost_calc(t_stack *tmp, t_stack **stack)
{
	int	cost;

	cost = 0;
	if (tmp->data.above_median == 0)
		cost = tmp->data.index;
	if (tmp->data.above_median == 1)
		cost = stack_size(*stack) - tmp->data.index;
	return (cost);
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
		if (temp_a->data.nbr > temp_b->data.nbr \
		&& best_target < temp_b->data.nbr)
			best_target = temp_b->data.nbr;
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
		if (temp_b->data.nbr < temp_a->data.nbr \
		&& best_target > temp_a->data.nbr)
			best_target = temp_a->data.nbr;
		temp_a = temp_a->next;
	}
	if (best_target == INT_MAX)
		best_target = find_min(a);
	return (best_target);
}
