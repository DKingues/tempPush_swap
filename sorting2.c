/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:55:25 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:59:23 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->data.nbr > (*a)->next->data.nbr
		&& (*a)->next->data.nbr < (*a)->next->next->data.nbr
		&& (*a)->data.nbr > (*a)->next->next->data.nbr)
		rotate_a(a);
	if ((*a)->data.nbr > (*a)->next->data.nbr
		&& (*a)->next->data.nbr > (*a)->next->next->data.nbr
		&& (*a)->next->next->data.nbr < (*a)->data.nbr)
	{
		swap_a(*a);
		reverse_rotate_a(a);
	}
	if ((*a)->data.nbr < (*a)->next->data.nbr
		&& (*a)->next->data.nbr > (*a)->next->next->data.nbr
		&& (*a)->data.nbr > (*a)->next->next->data.nbr)
		reverse_rotate_a(a);
	if ((*a)->data.nbr < (*a)->next->data.nbr
		&& (*a)->next->data.nbr > (*a)->next->next->data.nbr
		&& (*a)->data.nbr < (*a)->next->next->data.nbr)
	{
		reverse_rotate_a(a);
		swap_a(*a);
	}
	if ((*a)->data.nbr > (*a)->next->data.nbr && (*a)->next->data.nbr < \
	(*a)->next->next->data.nbr && (*a)->next->next->data.nbr > (*a)->data.nbr)
		swap_a(*a);
}

bool	is_sorted(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		return (false);
	temp = a;
	while (temp->next)
	{
		if (temp->data.nbr > temp->next->data.nbr)
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
	int		biggest_nbr;

	tmp_b = *b;
	biggest_nbr = find_max(*b);
	while (tmp_b->data.nbr != biggest_nbr)
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
