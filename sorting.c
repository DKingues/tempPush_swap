/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:13:33 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/27 22:01:49 by dicosta-         ###   ########.fr       */
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

void sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(a) == 3 && !(is_sorted(a)))
		sort_three(a);
	else
	{
	push_b(a, b);
	push_b(a, b);
	}
	if (!(is_sorted(a)))
	{
		
	}
	
}