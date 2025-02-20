/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:55:25 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/20 21:58:19 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->data.number > (*stack)->next->data.number && (*stack)->next->data.number < (*stack)->next->next->data.number && (*stack)->data.number > (*stack)->next->next->data.number)
		rotate_a(stack);
	else if ((*stack)->data.number > (*stack)->next->data.number && (*stack)->next->data.number > (*stack)->next->next->data.number && (*stack)->next->next->data.number < (*stack)->data.number)
	{
		swap_a(*stack);
		reverse_rotate_a(stack);
	}
	else if ((*stack)->data.number < (*stack)->next->data.number && (*stack)->next->data.number > (*stack)->next->next->data.number && (*stack)->data.number > (*stack)->next->next->data.number)
		reverse_rotate_a(stack);
	else if ((*stack)->data.number < (*stack)->next->data.number && (*stack)->next->data.number > (*stack)->next->next->data.number && (*stack)->data.number < (*stack)->next->next->data.number)
	{
		reverse_rotate_a(stack);
		swap_a(*stack);
	}
	else if ((*stack)->data.number > (*stack)->next->data.number && (*stack)->next->data.number < (*stack)->next->next->data.number && (*stack)->next->next->data.number > (*stack)->data.number)
		swap_a(*stack);
}

bool	is_sorted(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		return (false);
	temp = a;
	while (temp->next)
	{
		if (temp->data.number > temp->next->data.number)
			return (false);
		temp = temp->next;
	}
	return (true);
}

void	set_cheapest(t_stack *a)
{
	t_stack	*temp;
	int		min;

	if (!a)
		return ;
	temp = a;
	min = INT_MAX;
	while (temp)
	{
		if (temp->data.push_cost < min)
			min = temp->data.push_cost;
		temp = temp->next;
	}
	temp = a;
	while (temp->data.push_cost != min)
		temp = temp->next;
	temp->data.cheapest = true;
}

void	set_data(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	push_cost(&a, &b);
	set_cheapest(a);
}

void	rotate_last(t_stack **b)
{
	t_stack	*tmp_b;
	int		biggest_number;

	tmp_b = *b;
	biggest_number = find_max(*b);
	while (tmp_b->data.number != biggest_number)
		tmp_b = tmp_b->next;
	while (tmp_b->data.index != 0)
	{
		if (tmp_b->data.above_median == 0)
			rotate_b(b);
		if (tmp_b->data.above_median == 1)
			reverse_rotate_b(b);
		current_index(*b);
	}
}
