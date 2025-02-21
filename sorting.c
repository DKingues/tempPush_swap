/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:13:33 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:59:15 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) == true)
		return ;
	if (stack_size(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	if (stack_size(*a) > 3)
		push_b(a, b);
	if (stack_size(*a) > 3)
		push_b(a, b);
	while (stack_size(*a) > 3)
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
	set_data(*a, *b);
	last_rotate(a);
}

void	last_rotate(t_stack **a)
{
	int		check;
	t_stack	*tmp_a;

	tmp_a = *a;
	check = find_min(tmp_a);
	while ((tmp_a)->data.nbr != check)
		(tmp_a) = (tmp_a)->next;
	if ((tmp_a)->data.above_median == 0)
	{
		while (is_sorted(*a) == false)
			rotate_a(a);
	}
	else
	{
		while (is_sorted(*a) == false)
			reverse_rotate_a(a);
	}
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		target;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a->data.cheapest != 1)
		tmp_a = tmp_a->next;
	target = target_node(tmp_a, tmp_b);
	while (tmp_b && tmp_b->data.nbr != target)
		tmp_b = tmp_b->next;
	perform_rotations(a, b, tmp_a, tmp_b);
	push_b(a, b);
}

void	move_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		target;

	tmp_a = *a;
	tmp_b = *b;
	target = target_node_b(tmp_b, tmp_a);
	while (tmp_a && tmp_a->data.nbr != target)
		tmp_a = tmp_a->next;
	while (tmp_a && tmp_a->data.index != 0)
	{
		if (tmp_a->data.above_median == 0)
			rotate_a(a);
		if (tmp_a->data.above_median == 1)
			reverse_rotate_a(a);
		current_index_r(*a, *b);
	}
	push_a(b, a);
}

void	perform_rotations(t_stack **a, t_stack **b, \
t_stack *tmp_a, t_stack *tmp_b)
{
	while ((tmp_a->data.index != 0 && tmp_b->data.index != 0)
		&& (tmp_a->data.above_median == tmp_b->data.above_median))
	{
		if (tmp_a->data.above_median == 0 && tmp_b->data.above_median == 0)
			rotate_r(a, b);
		if (tmp_a->data.above_median == 1 && tmp_b->data.above_median == 1)
			reverse_rotate_r(a, b);
		current_index_r(*a, *b);
	}
	while (tmp_b->data.index != 0)
	{
		if (tmp_b->data.above_median == 0)
			rotate_b(b);
		if (tmp_b->data.above_median == 1)
			reverse_rotate_b(b);
		current_index_r(*a, *b);
	}
	while (tmp_a->data.index != 0)
	{
		if (tmp_a->data.above_median == 0)
			rotate_a(a);
		if (tmp_a->data.above_median == 1)
			reverse_rotate_a(a);
		current_index_r(*a, *b);
	}
}
