/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:54:03 by janhan            #+#    #+#             */
/*   Updated: 2024/02/09 12:44:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotation(t_stack **stack, size_t
count_from_top, size_t count_from_bottom)
{
	if (count_from_top == 0)
		return ;
	if (count_from_top < ft_stacksize(*stack) / 2
		|| count_from_top < count_from_bottom)
	{
		while (count_from_top > 0)
		{
			ft_ra(stack, 1);
			count_from_top--;
		}
	}
	else
	{
		while (count_from_bottom > 0)
		{
			ft_rra(stack, 1);
			count_from_bottom--;
		}
	}
}

static void	optimize_rotation(t_stack **stack_a, int count, int chunk)
{
	size_t	count_from_top;
	size_t	count_from_bottom;
	t_stack	*current;
	t_stack	*tail;

	tail = NULL;
	count_from_top = 0;
	count_from_bottom = 1;
	current = *stack_a;
	while (current && current->next)
		current = current->next;
	tail = current;
	current = *stack_a;
	while (current && !(current->index < count + chunk))
	{
		count_from_top++;
		current = current->next;
	}
	current = tail;
	while (current && !(current->index < count + chunk))
	{
		count_from_bottom++;
		current = current->prev;
	}
	rotation(stack_a, count_from_top, count_from_bottom);
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	size;
	long	index;
	int		chunk;
	int		to_find;

	stack_b = NULL;
	size = ft_stacksize(*stack_a);
	chunk = ft_get_cunk(stack_a);
	index = 0;
	while (size--)
	{
		optimize_rotation(stack_a, index, chunk);
		to_find = (*stack_a)->index;
		ft_pb(stack_a, &stack_b, 1);
		if (index <= to_find && to_find <= index + chunk)
			ft_rb(&stack_b, 1);
		index++;
	}
	return (stack_b);
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	size_t	b_size;
	size_t	order;

	temp = *stack_b;
	b_size = ft_stacksize(*stack_b);
	while (*stack_b)
	{
		ft_find_index(*stack_b, ft_max(*stack_b), &order);
		if (order < ft_stacksize(*stack_b) / 2)
			up_pa(stack_a, stack_b, ft_find_max_addr(stack_b));
		else
			down_pa(stack_a, stack_b, ft_find_max_addr(stack_b));
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	size;

	stack_b = NULL;
	size = ft_stacksize(*stack_a);
	if (size == 2)
		ft_sa(stack_a, 1);
	else if (size == 3)
		ft_sort_three(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
	}
}
