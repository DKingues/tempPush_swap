/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:13:33 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/30 19:37:53 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->data.number > (*stack)->next->next->data.number)
		rotate_a(stack);
	if ((*stack)->data.number > (*stack)->next->data.number)
		swap(*stack);
	if ((*stack)->next->data.number > (*stack)->next->next->data.number)
	{
		reverse_rotate_a(stack);
		swap(*stack);
	}
}

int	is_sorted(t_stack *a)
{
	while (a)
	{
		if (a->data.number > a->next->data.number)
			return (0);
		a = a->next;
	}
	return (1);
}

void	set_data(t_stack **a, t_stack **b)
{
	current_index(a);
	current_index(b);
	push_cost(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(a) == 3 && !is_sorted(a)) 
		sort_three(a);
	if (stack_size(*a) > 3)
		push_b(a, b);
	if (stack_size(*a) > 3)
		push_b(a, b);
	while(stack_size(*a) > 3 && !is_sorted(*a))
	{
		set_data(a, b);
		
	}
	sort_three(a);
}

void	move_to_b(t_stack **a, t_stack **b)
{	
	while ((*a)->data.index != 0 && !(*a)->data.above_median)
		rotate(*a);
	
}