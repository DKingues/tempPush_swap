/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:18:29 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:59:35 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int n)
{
	t_stack	*new;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		return (NULL);
	new->data.nbr = n;
	new->data.index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(sizeof(t_stack), 1);
	node->next = NULL;
	node->data.nbr = n;
	if (!(*stack))
	{
		(*stack) = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	add_node_front(t_stack **stack, t_stack *node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	node->next = (*stack);
	(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*temp_node;

	if (!stack)
		return (NULL);
	temp_node = stack;
	while (temp_node->next != NULL)
	{
		temp_node = temp_node->next;
	}
	return (temp_node);
}

int	stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
