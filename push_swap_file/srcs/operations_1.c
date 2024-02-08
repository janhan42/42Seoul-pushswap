/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:56:53 by yogun             #+#    #+#             */
/*   Updated: 2024/02/08 18:56:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **a)
{
	ft_rr_sub(a);
	while(write(1, "ra\n", 3)!=3)
		continue;
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
	while(write(1, "sa\n", 3) !=3)
		continue;
	// printf("sa\n");
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
	while(write(1, "pa\n", 3) != 3)
		continue;
	// printf("pa\n");
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
	while(write(1, "rra\n", 4) !=4)
		continue;
	// printf("rra\n");
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
	while(write(1, "ss\n", 3)!=3)
		continue;
	// printf("ss\n");
}
