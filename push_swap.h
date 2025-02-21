/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:06:11 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 14:59:05 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
}	t_node;

typedef struct s_stack
{
	t_node			data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// AUX FUNCTS

void	initialize_stack(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
void	current_index_r(t_stack *a, t_stack *b);
void	push_cost(t_stack **a, t_stack **b);
int		cost_calc(t_stack *tmp, t_stack **stack);
int		target_node(t_stack *a, t_stack *b);
int		target_node_b(t_stack *b, t_stack *a);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);

// ERROR CHECK

bool	error_check(t_stack *stack, char **split_number);
bool	check_dupes(t_stack *stack);
bool	check_non_int(char **split_number);
bool	check_int_minmax(char **split_number);
bool	is_number(char *nbr);
void	free_stack(t_stack **stack);

// LIST MANAGEMENT

t_stack	*new_node(int n);
void	append_node(t_stack **stack, int n);
void	add_node_front(t_stack **stack, t_stack *node);
void	add_node_back(t_stack **stack, int n);
t_stack	*get_last_node(t_stack *stack);
int		stack_size(t_stack *node);
t_stack	*remove_front_node(t_stack **stack);

// MOVEMENTS

void	swap_a(t_stack *a);
void	push_a(t_stack **b, t_stack **a);
void	rotate_a(t_stack **a);
void	reverse_rotate_a(t_stack **a);
void	swap_b(t_stack *b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_b(t_stack **b);
void	reverse_rotate_b(t_stack **b);
void	swaps(t_stack *a, t_stack *b);
void	rotate_r(t_stack **a, t_stack **b);
void	reverse_rotate_r(t_stack **a, t_stack **b);

// SORTING ALGORITHM

void	sort_three(t_stack **stack);
void	sort_stack(t_stack **a, t_stack **b);
void	move_to_b(t_stack **a, t_stack **b);
void	move_to_a(t_stack **a, t_stack **b);
void	set_cheapest(t_stack *a);
void	rotate_last(t_stack **b);
void	final_sort(t_stack **a);
void	perform_rotations(t_stack **a, t_stack **b, \
		t_stack *tmp_a, t_stack *tmp_b);
bool	is_sorted(t_stack *a);
void	last_rotate(t_stack **a);
void	set_data(t_stack *a, t_stack *b);

#endif