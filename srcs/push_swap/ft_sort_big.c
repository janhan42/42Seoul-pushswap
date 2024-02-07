/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:38:42 by yogun             #+#    #+#             */
/*   Updated: 2024/02/07 09:39:19 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stddef.h>
#include <stdio.h>

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	size;
	long	index;
	int		cunk;

	stack_b = NULL;
	size = ft_stacksize(*stack_a);
	index = 0;
	cunk = ft_get_cunk(stack_a);
	while (size--)
	{
		while (1)
		{
			if ((*stack_a)->index < index + cunk)
				break;
			ft_ra(stack_a, 0);
		}
		ft_pb(stack_a, &stack_b, 0);
		if (index % 2 == 0)ft_rb(&stack_b, 0);
		index++;
	}
	return (stack_b);
}



t_stack *ft_find_max_addr(t_stack **stack)
{
	t_stack	*top;
	t_stack	*res_idx;
	int		temp;

	top = *stack;
	temp = top->index;
	res_idx = top;
	while (top)
	{
		if (temp < top->index)
		{
			temp = top->index;
			res_idx = top;
		}
		top = top->next;
	}
	return (res_idx);
}

void	up_pa(t_stack **a_top_p, t_stack **b_top_p, t_stack *to_find)
{
	t_stack	*b_top;

	b_top = *b_top_p;
	while (b_top)
	{
		if (b_top == to_find)
		{
			ft_pa(a_top_p, b_top_p, 0);
			return ;
		}
		else
		{
			ft_rb(b_top_p, 0);
			b_top = *b_top_p;
		}
	}
}

void	down_pa(t_stack **a_top_p, t_stack **b_top_p, t_stack *to_find)
{
	t_stack	*b_top;

	b_top = *b_top_p;
	while (b_top)
	{
		if (b_top == to_find)
		{
			ft_pa(a_top_p, b_top_p, 0);
			return ;
		}
		else
		{
			ft_rrb(b_top_p, 0);
			b_top = *b_top_p;
		}
	}
}
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	size_t	b_size;
	int		to_find;
	size_t	order;

	temp = *stack_b;
	b_size = ft_stacksize(*stack_b);
	while (*stack_b)
	{
		to_find = ft_find_index(*stack_b, ft_max(*stack_b), &order);
		if (order > ft_stacksize(*stack_b) / 2)
			down_pa(stack_a, stack_b, ft_find_max_addr(stack_b));
		else
		 	up_pa(stack_a, stack_b, ft_find_max_addr(stack_b));
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	size;
	long	index;

	stack_b = NULL;
	size = ft_stacksize(*stack_a);
	index = 0;

	if (size == 2)
		ft_sa(stack_a, 0);
	if (size == 3)
		ft_sort_three(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
	}
}
