/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:44:09 by janhan            #+#    #+#             */
/*   Updated: 2024/02/14 08:14:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_find_max_addr(t_stack **stack)
{
	t_stack	*top;
	t_stack	*res_addr;
	int		temp;

	top = *stack;
	temp = top->index;
	res_addr = top;
	while (top)
	{
		if (temp < top->index)
		{
			temp = top->index;
			res_addr = top;
		}
		top = top->next;
	}
	return (res_addr);
}

long	ft_find_index(t_stack *stack_a, int nbr, size_t *order)
{
	int	i;

	i = 0;
	while (stack_a->nbr != nbr)
	{
		i++;
		stack_a = stack_a->next;
	}
	if (order != NULL)
		*order = i;
	return (stack_a->index);
}

long	ft_find_min_index(t_stack *stack_a, int index)
{
	t_stack	*a_top;
	int		chunk;
	long	count;

	a_top = stack_a;
	chunk = ft_get_cunk(&stack_a);
	count = 0;
	while (a_top)
	{
		if (a_top->index < index + chunk)
			break ;
		count++;
		a_top = a_top->next;
	}
	return (count);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	new->prev = NULL;
	new->index = -1;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	t_stack	*last;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = stack_new;
		stack_new->prev = NULL;
	}
	else
	{
		last = ft_stacklast(*stack);
		last->next = stack_new;
		stack_new->prev = last;
	}
	stack_new->next = NULL;
}
