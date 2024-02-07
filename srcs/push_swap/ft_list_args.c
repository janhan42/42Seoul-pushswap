/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:12:47 by yogun             #+#    #+#             */
/*   Updated: 2024/02/05 13:59:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// While arguments are valid, we start to add them
// into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer
// value where we can make math operations.
// With stack new we create a new node for the current
// argument without linking it to list.
// We make linking stage in ft_add_back call.
void	list_args(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_add_back(stack_a, ft_stack_new(ft_atoi(argv[i])));
		i++;
	}
}
