/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:38:48 by janhan            #+#    #+#             */
/*   Updated: 2024/02/09 12:41:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_min_addr(t_stack *stack)
{
	t_stack	*min_addr;
	int		i;

	i = stack->nbr;
	min_addr = NULL;
	while (stack)
	{
		if (stack->index != -1)
		{
			stack = stack->next;
			continue ;
		}
		if (min_addr == NULL)
		{
			min_addr = stack;
			i = stack->nbr;
		}
		if (stack->nbr < i)
		{
			i = stack->nbr;
			min_addr = stack;
		}
		stack = stack->next;
	}
	return (min_addr);
}

void	ft_index(t_stack **stack_a)
{
	t_stack	*top;
	t_stack	*temp;
	size_t	size;
	int		i;

	top = *stack_a;
	size = ft_stacksize(*stack_a);
	i = 0;
	while (size > 0)
	{
		temp = ft_min_addr(top);
		temp->index = i;
		i++;
		size--;
		top = *stack_a;
	}
}
