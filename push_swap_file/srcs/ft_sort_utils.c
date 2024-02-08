/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:28:18 by janhan            #+#    #+#             */
/*   Updated: 2024/02/08 19:06:27 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	up_pa(t_stack **a_top_p, t_stack **b_top_p, t_stack *to_find)
{
	t_stack	*b_top;

	b_top = *b_top_p;
	while (1)
	{
		if (*b_top_p == to_find)
		{
			ft_pa(a_top_p, b_top_p);
			return ;
		}
		else
		{
			ft_rb(b_top_p);
			// b_top = *b_top_p;
		}
	}
}

void	down_pa(t_stack **a_top_p, t_stack **b_top_p, t_stack *to_find)
{
	t_stack	*b_top;

	b_top = *b_top_p;
	while (1)
	{
		if (*b_top_p == to_find)
		{
			ft_pa(a_top_p, b_top_p);
			return ;
		}
		else
		{
			ft_rrb(b_top_p);
			// b_top = *b_top_p;
		}
	}
}