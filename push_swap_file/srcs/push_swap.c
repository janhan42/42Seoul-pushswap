/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:44:09 by janhan            #+#    #+#             */
/*   Updated: 2024/02/07 10:53:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (!ft_checksorted(stack_a))
		ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}