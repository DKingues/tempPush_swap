/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:35:51 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:57:44 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	int	i;

	if (!a || !a->next)
		return ;
	i = a->data.nbr;
	a->data.nbr = a->next->data.nbr;
	a->next->data.nbr = i;
	write(1, "sa\n", 3);
}

void	push_a(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = remove_front_node(b);
	add_node_front(a, temp);
	write(1, "pa\n", 3);
}

void	rotate_a(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	last = get_last_node(*a);
	*a = temp->next;
	(*a)->prev = NULL;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	last = get_last_node(*a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	*a = last;
	write(1, "rra\n", 4);
}

t_stack	*remove_front_node(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	return (temp);
}
