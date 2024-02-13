/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:28:18 by janhan            #+#    #+#             */
/*   Updated: 2024/02/14 08:13:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stddef.h>

void	up_pa(t_stack **stack_a, t_stack **stack_b, t_stack *to_find)
{
	t_stack	*b_top;

	b_top = *stack_b;
	while (1)
	{
		if (*stack_b == to_find)
		{
			ft_pa(stack_a, stack_b, 1);
			return ;
		}
		else
			ft_rb(stack_b, 1);
	}
}

void	down_pa(t_stack **stack_a, t_stack **stack_b, t_stack *to_find)
{
	t_stack	*b_top;

	b_top = *stack_b;
	while (1)
	{
		if (*stack_b == to_find)
		{
			ft_pa(stack_a, stack_b, 1);
			return ;
		}
		else
			ft_rrb(stack_b, 1);
	}
}
