/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:14:47 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:57:53 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	int	i;

	if (!b || !b->next)
		return ;
	i = b->data.nbr;
	b->data.nbr = b->next->data.nbr;
	b->next->data.nbr = i;
	write(1, "sb\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = remove_front_node(a);
	add_node_front(b, temp);
	write(1, "pb\n", 3);
}

void	rotate_b(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	last = get_last_node(*b);
	*b = temp->next;
	(*b)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	last = get_last_node(*b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	*b = last;
	write(1, "rrb\n", 4);
}
