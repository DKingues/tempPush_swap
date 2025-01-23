/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:11:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/23 18:25:36 by dicosta-         ###   ########.fr       */
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
    
    if (argc < 2 || !argv[1][0])
        return (0);
    else if (argc == 2)
    {
        tmp = ft_split(argv[1], ' ');
        a = new_node(ft_atoi(tmp[i++]));
        while (tmp[i])
            add_node_back(&a, ft_atoi(tmp[i++]));
    }
    else if (argc > 2)
    {
        i++;
        a = new_node(ft_atoi(argv[i++]));
        while (argv[i])
            add_node_back(&a, ft_atoi(argv[i++]));
    }
    printf("START\n\n");
    printf("First Stack A\n\n");
    while(a)
    {   
        printf("number: %d\t index: %d\n", a->data.number, a->data.index);
        a = a->next;
    }
    push_b(&a, &b);
    printf("Stack B\n\n");
    while (b)
    {
        printf("number: %d\t index: %d\n", b->data.number, b->data.index);
        b = b->next;
    }
    printf("Second Stack A\n\n");
    while(a)
    {   
        printf("number: %d\t index: %d\n", a->data.number, a->data.index);
        a = a->prev;
    }
}
