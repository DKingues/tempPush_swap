/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:11:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/06 17:53:26 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack         *a;
    t_stack         *b;
    int             i;
    char            **tmp;
    initialize_stack(&a, &b);
	
  	if (argc < 2 || (argc == 2 && !argv[1][0]))
        return (write (2 ,"Error\n", 6), 0);
    else if (argc == 2)
    {
        tmp = ft_split(argv[1], ' ');
        while (tmp[i])
            append_node(&a, ft_atoi(tmp[i++]));
    }
    else if (argc > 2)
    {
        i++;
        while (argv[i])
            append_node(&a, ft_atoi(argv[i++]));
    }
	sort_stack(&a, &b);
	// print_stack(a);
}

void print_stack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;

    while (temp)
    {
        printf("number: %d\t index: %d\t median: %d\t push cost: %d\n", temp->data.number, temp->data.index, temp->data.above_median, temp->data.push_cost);
        temp = temp->next;
    }
}
