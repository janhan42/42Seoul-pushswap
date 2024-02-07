/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:16:13 by yogun             #+#    #+#             */
/*   Updated: 2024/02/07 13:48:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stddef.h>

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

long ft_find_index(t_stack *a, int nbr, size_t *order)
{
	int	i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	if (order != NULL)
		*order = i;
	return a->index;
}
long	ft_find_min_index(t_stack *a, int index)
{
	t_stack	*a_top;
	int		chunk;
	long	count;

	a_top = a;
	chunk = ft_get_cunk(&a);
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
