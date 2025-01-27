/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:11:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/24 18:50:18 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack         *a;
    t_stack         *b;
    int             i;
    char            **tmp;
    printf("Initializing Stacks...\n\n");
    initialize_stack(a, b);
    
    if (argc < 2 || (argc == 2 && !argv[1][0]))
        return (printf("Error\n"), 0);
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
    printf("START\n\n");
    printf("First Stack A\n\n");
    t_stack *temp = a;
    print_stack(temp);
    reverse_rotate_a(&a);
    printf("Stack B\n\n");
    print_stack(b);
    printf("Second Stack A\n\n");
    print_stack(a);
}

void print_stack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;

    while (temp)
    {
        printf("number: %d\t index: %d\n", temp->data.number, temp->data.index);
        temp = temp->next;
    }
}
