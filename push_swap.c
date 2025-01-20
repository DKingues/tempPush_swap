/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:11:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/01/20 19:08:52 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack         *a;
    t_stack         *b;
    int             i;
    char            **tmp;

    a = NULL;
    b = NULL;
    i = 0;
    
    if (argc < 2 || !argv[1][0])
        return (0);
    else if (argc == 2)
    {
        tmp = ft_split(argv[1], ' ');
        a = new_node(ft_atoi(tmp[i++]));
        while (tmp[i])
            add_node_back(&a, ft_atoi(tmp[i++]));
    }
    while (a)
    {
        printf("number = %i \tindex = %i\n", a->data.number, a->data.index);
        a = a->next;
    }
    free(tmp);
}
