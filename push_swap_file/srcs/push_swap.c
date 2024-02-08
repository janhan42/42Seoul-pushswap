/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:44:09 by janhan            #+#    #+#             */
/*   Updated: 2024/02/08 19:20:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	print_index(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (temp)
	{
		printf("index : %ld , nbr : %d \n", temp->index, temp->nbr);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = ft_process(ac, av);
	if (!stack_a || ft_checkdup(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}
	ft_index(&stack_a);
	// print_index(&stack_a);
	if (!ft_checksorted(stack_a))
		ft_sort(&stack_a);
	print_index(&stack_a);
	ft_free(&stack_a);
	return (0);
}