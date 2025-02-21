/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:11:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/02/21 15:03:17 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	initialize_stack(&a, &b);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[i])
			append_node(&a, ft_atoi(argv[i++]));
	}
	else if (argc > 2)
	{
		i++;
		while (argv[i])
			append_node(&a, ft_atoi(argv[i++]));
	}
	if (error_check(a, argv) == false)
		return (write(2, "Error\n", 6), free_stack(&a), false);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
