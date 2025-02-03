/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:04 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/30 19:35:39 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		median;
	
	if (!stack)
	{
		return ;
	}
	i = 0;
	median = stack_size(stack) / 2;
	printf("%d", median);
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
void	push_cost(t_stack **a, t_stack **b)
{
	int	cost_a;
	int cost_b;
	
	cost_a = 0;
	cost_b = 0;
	if(!*a || !a || !*b || !b )
		return	;
	if (!(*a)->data.above_median)
		cost_a = (*a)->data.index;
	else if ((*a)->data.above_median)
		cost_a = stack_size((*a)) - (*a)->data.index;
	while((*b)->data.number != target_node(a, b))
		(*b) = (*b)->next;
	if (!(*b)->data.above_median)
		cost_b = (*b)->data.index;
	else if ((*b)->data.above_median)
		cost_b = stack_size((*b)) - (*b)->data.index;
	(*a)->data.push_cost = cost_a + cost_b;
}
int target_node(t_stack **a, t_stack **b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int		best_target;
	
	temp_a = *a;
	best_target = LONG_MIN;
	
	while (temp_a)
	{
		temp_b = *b;
		while (temp_b)
		{	
			if(temp_a->data.number > temp_b->data.number && best_target < temp_b->data.number)
				best_target = temp_b->data.number;
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	if (best_target == LONG_MIN)
	{
		best_target = find_max(b);
	}
	return (best_target);
}

int find_max(t_stack **stack)
{
	t_stack	*temp;
	int		biggest_number;
	
	temp = *stack;
	biggest_number = LONG_MIN;
	while (temp)
	{
		if (temp->data.number > biggest_number)
		{
			biggest_number = temp->data.number;
			temp = temp->next;
		}
	}
	return (biggest_number);
}

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
