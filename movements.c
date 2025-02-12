/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:35:51 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/12 22:14:02 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
	if (!stack || !stack->next)
		return ;
	
	int	i;

	i = stack->data.number;
	stack->data.number = stack->next->data.number;
	stack->next->data.number = i;
}

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
}

void	push_a(t_stack **b, t_stack **a)
{
	if (!b || !*b)
		return ;
	
	t_stack	*temp;
	
	temp = remove_front_node(b);
	add_node_front(a, temp);
}


void	push_b(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	
	t_stack	*temp;
	temp = remove_front_node(a);
	add_node_front(b, temp);
}
void	rotate_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	
	t_stack	*temp;
	t_stack *last;

	temp = *a;
	last = get_last_node(*a);
	*a = temp->next;
	(*a)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
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
}

void	rotate_r(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next )
		return	;
	
	rotate_a(a);
	rotate_b(b);
}

void reverse_rotate_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next )
		return	;
		
	t_stack	*temp;
	t_stack	*last;
	
	temp = *a;
	last = get_last_node(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	*a = last;
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
}

void reverse_rotate_r(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next )
		return	;
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}

t_stack	*remove_front_node(t_stack **stack)
{
	if (!stack || !*stack)
		return (NULL);
	 
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	
	if (*stack)
		(*stack)->prev = NULL;
		
	return (temp);
}