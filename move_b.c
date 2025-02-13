/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:14:47 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/13 16:18:11 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	if (!b || !b->next)
		return ;
	
	int	i;

	i = b->data.number;
	b->data.number = b->next->data.number;
	b->next->data.number = i;
	write(1, "sb\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	
	t_stack	*temp;
	temp = remove_front_node(a);
	add_node_front(b, temp);
	write(1, "pb\n", 3);
}

void	rotate_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	
	t_stack	*temp;
	t_stack *last;

	temp = *b;
	last = get_last_node(*b);
	*b = temp->next;
	(*b)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
	write(1, "rb\n", 3);
}

void reverse_rotate_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next )
		return	;
		
	t_stack	*temp;
	t_stack	*last;
	
	temp = *b;
	last = get_last_node(*b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	*b = last;
	write(1, "rrb\n", 4);
}