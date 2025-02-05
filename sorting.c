/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:13:33 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/05 21:12:06 by dicosta-         ###   ########.fr       */
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
	t_stack	*temp;
	
	if (!a)
		return (0);
	temp = a;
	while (a)
	{
		if (a->data.number > a->next->data.number)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack *find_cheapest(t_stack **a)
{
	t_stack	*temp;
	int		min;

	if (!*a || !a)
		return (NULL);

	temp = *a;
	min = INT_MAX;
	while (temp)
	{
		if (temp->data.push_cost < min)
			min = temp->data.push_cost;
		temp = temp->next;	
	}
	while (temp->data.push_cost != min)
		temp = temp->prev;
	return (temp);
}

void	set_data(t_stack *a, t_stack *b)
{
	print_stack(a);
	print_stack(b);
	current_index(a);
	current_index(b);
	print_stack(a);
	print_stack(b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!*a || !*b || !a || !b)
		return	;
	if (stack_size((*a)) == 3 && !is_sorted((*a)))
		sort_three(a);
	if (stack_size(*a) > 3)
		push_b(&*a, &*b);
	if (stack_size(*a) > 3)
		push_b(a, b);
	//while(stack_size(*a) > 3 && !is_sorted(*a))
	//{
	set_data(*a, *b);
	//}
	sort_three(a);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(a);
	while ((*a) != cheapest_node && target_node)
	{
		if ((*a)->data.index != 0 && !(*a)->data.above_median)
			rotate_a(a);
		if ((*a)->data.index != 0 && (*a)->data.above_median)
			reverse_rotate_a(a);
	}
	
}

