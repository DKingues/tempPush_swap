/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:18:29 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/20 18:41:15 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(int n)
{
    t_stack *new;
    
    new = ft_calloc(sizeof(t_stack), 1);
    if (!new)
        return (NULL);
    new->data.number = n;
    new->data.index = 0;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void    add_node_back(t_stack **stack, int n)
{
    t_stack *new_node;
    t_stack *current;

    if (!stack || !*stack)
        return ;
        
    new_node = ft_calloc(sizeof(t_stack), 1);
    if (!new_node)
        return ;
        
    current = get_last_node(*stack);
    current->next = new_node;
    new_node->next = NULL;
    new_node->prev = current;
    new_node->data.number = n;
    new_node->data.index = get_index(*stack);
}

t_stack *get_last_node(t_stack *stack)
{
    t_stack *temp_node;
    
    if (!stack)
        return (NULL);
        
    temp_node = stack;
    
    while (temp_node)
    {
        temp_node = temp_node->next;
    }
    return (temp_node);
}

int stack_size(t_stack *node)
{
    int i;
    while (node->next != NULL)
    {
        i++;
        node = node->next;
    }
    return (i);
}
