/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:06:11 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/27 18:49:45 by dicosta-         ###   ########.fr       */
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
void	initialize_stack(t_stack *a, t_stack *b);
void    print_stack(t_stack *stack);
void    error_check(t_stack *stack, int n);

// LIST MANAGEMENT

t_stack *new_node(int n);
void    append_node(t_stack **stack, int n);
void    add_node_front(t_stack **stack, t_stack *node);
void    add_node_back(t_stack **stack, int n);
t_stack *get_last_node(t_stack *stack);
int     stack_size(t_stack *node);
t_stack	*remove_front_node(t_stack **stack);


// MOVEMENTS

void    swap(t_stack *stack);
void	swaps(t_stack *a, t_stack *b);
void	push_a(t_stack **b, t_stack **a);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_r(t_stack **a, t_stack **b);
void    reverse_rotate_a(t_stack **a);
void    reverse_rotate_b(t_stack **b);
void    reverse_rotate_r(t_stack **a, t_stack **b);

// SORTING ALGORITHM

void	sort_three(t_stack **stack);
#endif