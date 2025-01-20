/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:06:11 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/20 18:41:46 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_node
{
    int     number;
    int     index;
    int     push_cost;
    bool    above_median;
    bool    cheapest;
} t_node;

typedef struct s_stack
{
    t_node  data;
    struct  s_stack *next;
    struct  s_stack *prev;
} t_stack;

// AUX FUNCTS

int	    get_index(t_stack *node);
bool	above_median(t_stack *node);

// LIST MANAGEMENT

t_stack *new_node(int n);
void    add_node_back(t_stack **stack, int n);
t_stack *get_last_node(t_stack *stack);
int     stack_size(t_stack *node);

// 

#endif