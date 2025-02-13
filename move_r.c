/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:16:33 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/13 20:17:03 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaps(t_stack *a, t_stack *b)
{
	int	a_number;
	int	b_number;

	a_number = a->data.number;
	a->data.number = a->next->data.number;
	a->next->data.number = a_number;
	b_number = b->data.number;
	b->data.number = b->next->data.number;
	b->next->data.number = b_number;
	write(1, "ss\n", 3);
}

void	rotate_r(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next )
		return	;
	
	t_stack	*temp;
	t_stack *last;
	t_stack	*temp_b;
	t_stack *last_b;

	temp = *a;
	temp_b = *b;
	last = get_last_node(*a);
	*a = temp->next;
	(*a)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
	last_b = get_last_node(*b);
	*b = temp_b->next;
	(*b)->prev = NULL;
	temp_b->next = NULL;
	temp_b->prev = last_b;
	last_b->next = temp_b;
	write(1, "rr\n", 3);
}

void reverse_rotate_r(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next )
		return	;
		
	t_stack	*temp;
	t_stack	*last;
	t_stack	*temp_b;
	t_stack	*last_b;
	
	temp = *a;
	last = get_last_node(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	*a = last;
	temp_b = *b;
	last_b = get_last_node(*b);
	last_b->prev->next = NULL;
	last_b->prev = NULL;
	last_b->next = temp_b;
	temp_b->prev = last_b;
	*b = last_b;
	write(1, "rrr\n", 4);
}