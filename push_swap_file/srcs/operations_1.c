/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:56:53 by yogun             #+#    #+#             */
/*   Updated: 2024/02/07 13:23:30 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = ft_stacklast(*a);
	*a = first->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack *first_b;

	if (!*b)
		return ;
	first_b = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	if (*a)
		(*a)->prev = first_b;
	first_b->next = *a;
	first_b->prev = NULL;
	*a = first_b;
	write(1, "pa\n", 3);
}

void	ft_rra(t_stack **a)
{
	t_stack *last;
	t_stack *second_last;

	if (!*a || !(*a)->next)
		return;
	last = *a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	write(1, "rra\n", 4);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	t_stack	*top;

	top = *a;
	if (top == NULL || top->next == NULL)
		return ;
	else
	{
		node_swap(top, top->next);
		*a= top->prev;
	}
	top = *b;
	if (top == NULL || top->next == NULL)
		return ;
	else
	{
		node_swap(top, top->next);
		*b = top->prev;
	}
	ft_printf("ss\n");
}
