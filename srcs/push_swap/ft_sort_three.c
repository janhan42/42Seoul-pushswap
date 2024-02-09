/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:10:59 by yogun             #+#    #+#             */
/*   Updated: 2024/02/09 11:57:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 1);
		if (!ft_checksorted(*stack_a))
			ft_sa(stack_a, 1);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a), NULL) == 1)
			ft_rra(stack_a, 1);
		else
			ft_sa(stack_a, 1);
	}
}
