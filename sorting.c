/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:13:33 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/12 21:48:40 by dicosta-         ###   ########.fr       */
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

void set_cheapest(t_stack *a)
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

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!*a || !a)
		return	;
	if (stack_size((*a)) == 3 && !is_sorted((*a)))
		sort_three(a);
	if (stack_size(*a) > 3)
		push_b(a, b);
	if (stack_size(*a) > 3)
		push_b(a, b);
	while(stack_size(*a) > 3)
	{
		set_data(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a);
	rotate_last(b);
	while ((*b))
	{
		set_data(*a, *b);
		move_to_a(a, b);
	}
	rotate_a(a);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int 	target;
	
	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a && tmp_a->data.cheapest != 1)
		tmp_a = tmp_a->next;
	target = target_node(tmp_a, tmp_b);
	while (tmp_b && tmp_b->data.number != target)
		tmp_b = tmp_b->next;
	perform_rotations(a, b, tmp_a, tmp_b);
	push_b(a , b);
}

void	move_to_a(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int 	target;
	
	tmp_a = *a;
	tmp_b = *b;
	target = target_node(tmp_b, tmp_a);
	while (tmp_a->data.number != target)
		tmp_a = tmp_a->next;
	while(tmp_a->data.index != 0)
	{
		if(tmp_a->data.above_median == 0)
			rotate_a(a);
		if(tmp_a->data.above_median == 1)
			reverse_rotate_a(a);
		set_data(*a, *b);
	}
	push_a(b, a);
	swap(*a);
}

void rotate_last(t_stack **b)
{
	t_stack	*tmp_b;
	int 	biggest_number;
	
	tmp_b = *b;
	biggest_number = find_max(*b);
	while (tmp_b->data.number != biggest_number)
		tmp_b = tmp_b->next;
	while (tmp_b->data.index != 0)
	{
		reverse_rotate_b(b);
		current_index(*b);
	}
}

void perform_rotations(t_stack **a, t_stack **b, t_stack *tmp_a, t_stack *tmp_b)
{
	while ((tmp_a->data.index != 0 && tmp_b->data.index != 0) && (tmp_a->data.above_median == tmp_b->data.above_median))
	{
		if(tmp_a->data.above_median == 0 && tmp_b->data.above_median == 0)
			rotate_r(a, b);
		if(tmp_a->data.above_median == 1 && tmp_b->data.above_median == 1)
			reverse_rotate_r(a, b);
		set_data(*a, *b);	
	}
	while (tmp_a->data.index != 0)
	{
		if(tmp_a->data.above_median == 0)
			rotate_a(a);
		if(tmp_a->data.above_median == 1)
			reverse_rotate_a(a);
		set_data(*a, *b);
	}
	while (tmp_b->data.index != 0)
	{
		if(tmp_b->data.above_median == 0)
			rotate_b(b);
		if(tmp_b->data.above_median == 1)
			reverse_rotate_b(b);
		set_data(*a, *b);
	}
}
