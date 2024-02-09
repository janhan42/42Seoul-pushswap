/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:56:53 by yogun             #+#    #+#             */
/*   Updated: 2024/02/09 12:46:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **a, int i)
{
	ft_rr_sub(a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_sa(t_stack **a, int i)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*first_b;

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
	if (i == 1)
		write(1, "pa\n", 3);
}

void	ft_rra(t_stack **a, int i)
{
	ft_rrr_sub(a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	t_stack	*top;

	top = *a;
	if (top == NULL || top->next == NULL)
		return ;
	else
	{
		node_swap(top, top->next);
		*a = top->prev;
	}
	top = *b;
	if (top == NULL || top->next == NULL)
		return ;
	else
	{
		node_swap(top, top->next);
		*b = top->prev;
	}
	if (i == 1)
		write(1, "ss\n", 3);
}
