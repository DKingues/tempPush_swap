/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:04 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/27 22:08:19 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	t_stack	*temp;
	int		i;
	int		median;
	
	if (!stack)
		return ;
	temp = stack;
	i = 0;
	median = stack_size(stack) / 2;
	
	while(stack)
	{
		stack->data.index = i;
		if (stack->data.index < median)
			stack->data.above_median = false;
		else if (stack->data.index > median)
			stack->data.above_median = true;
		i++;
		stack = stack->next;
	}
}
// int	push_cost(t_stack **stack)
// {
	
// }


void	initialize_stack(t_stack *a, t_stack *b)
{
	a = ft_calloc(sizeof(t_stack), 1);
	b = ft_calloc(sizeof(t_stack), 1);
	if (!a || !b)
    	return ;
	a->data.number = 0;
	a->data.index = 0;
	a->data.cheapest = NULL;
	a->data.above_median = NULL;
	a->data.push_cost = 0;
	b->data.number = 0;
	b->data.index = 0;
	b->data.cheapest = NULL;
	b->data.above_median = NULL;
	b->data.push_cost = 0;
}

// int error_check(t_stack **stack, int n)
// {
// 	if(!stack)
// 		return	;
// 	t_stack	*temp;

// 	temp = *stack;
// 	while (temp)
// 	{
// 		if(temp->data.number > INT_MAX || temp->data.number < INT_MIN || temp->data.number == n)
// 		{
// 			printf("Error\n");
// 			return (1);
// 		}
// 		temp = temp->next;
// 	}
// 	return (0);
// }
