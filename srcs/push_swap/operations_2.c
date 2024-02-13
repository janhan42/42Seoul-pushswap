/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:55:23 by janhan            #+#    #+#             */
/*   Updated: 2024/02/14 08:16:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	ft_rr_sub(stack_a);
	ft_rr_sub(stack_b);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	ft_rrr_sub(t_stack **a_top)
{
	t_stack	*to_top;
	t_stack	*to_bot;
	t_stack	*temp;

	temp = *a_top;
	if (temp == NULL || temp->next == NULL)
		return ;
	while (temp->next)
		temp = temp->next;
	to_top = temp;
	to_bot = temp->prev;
	to_top->prev = NULL;
	to_top->next = *a_top;
	*a_top = to_top;
	to_top->next->prev = to_top;
	to_bot->next = NULL;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	ft_rrr_sub(stack_a);
	ft_rrr_sub(stack_b);
	if (i == 1)
		write(1, "rrr\n", 4);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*first_a;

	if (!*stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = first_a;
	first_a->next = *stack_b;
	first_a->prev = NULL;
	*stack_b = first_a;
	if (i == 1)
		write(1, "pb\n", 3);
}

void	ft_rrb(t_stack **stack_b, int i)
{
	ft_rrr_sub(stack_b);
	if (i == 1)
		write(1, "rrb\n", 4);
}
