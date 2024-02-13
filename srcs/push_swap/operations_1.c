/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:10:09 by janhan            #+#    #+#             */
/*   Updated: 2024/02/14 08:15:18 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **stack_a, int i)
{
	ft_rr_sub(stack_a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_sa(t_stack **stack_a, int i)
{
	t_stack	*tmp;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*first_b;

	if (!*stack_b)
		return ;
	first_b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = first_b;
	first_b->next = *stack_a;
	first_b->prev = NULL;
	*stack_a = first_b;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	ft_rra(t_stack **stack_a, int i)
{
	ft_rrr_sub(stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*top;

	top = *stack_a;
	if (top == NULL || top->next == NULL)
		return ;
	else
	{
		node_swap(top, top->next);
		*stack_a = top->prev;
	}
	top = *stack_b;
	if (top == NULL || top->next == NULL)
		return ;
	else
	{
		node_swap(top, top->next);
		*stack_b = top->prev;
	}
	if (i == 1)
		write(1, "ss\n", 3);
}
