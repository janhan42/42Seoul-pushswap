/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:44:50 by janhan            #+#    #+#             */
/*   Updated: 2024/02/14 08:18:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rb(t_stack **stack_b, int i)
{
	ft_rr_sub(stack_b);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	ft_sb(t_stack **stack_b, int i)
{
	t_stack	*top;

	top = *stack_b;
	if (top == NULL || top->next == NULL)
		return ;
	node_swap(top, top->next);
	*stack_b = top->prev;
	if (i == 1)
		write(1, "sb\n", 3);
}

static void	node_swap_near(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_a->next == stack_b)
	{
		first = stack_a;
		second = stack_b;
	}
	else
	{
		first = stack_b;
		second = stack_a;
	}
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
}

void	node_swap(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*prev;
	t_stack	*next;

	if (stack_a == NULL && stack_b == NULL)
		return ;
	else if (stack_a->next == stack_b || stack_b->next == stack_a)
		node_swap_near(stack_a, stack_b);
	else
	{
		prev = stack_a->prev;
		next = stack_a->next;
		stack_a->next = stack_b->next;
		stack_a->prev = stack_b->prev;
		stack_b->next = next;
		stack_b->prev = prev;
		if (stack_b->next != NULL)
			stack_b->next->prev = stack_b;
		if (stack_b->prev != NULL)
			stack_b->prev->next = stack_b;
		if (stack_a->next != NULL)
			stack_a->next->prev = stack_a;
		if (stack_a->prev != NULL)
			stack_a->prev->next = stack_a;
	}
	return ;
}

void	ft_rr_sub(t_stack **stack_a)
{
	t_stack	*to_top;
	t_stack	*to_bot;
	t_stack	*temp;

	temp = *stack_a;
	if (temp == NULL || temp->next == NULL)
		return ;
	to_top = temp->next;
	to_bot = temp;
	*stack_a = to_top;
	to_top->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = to_bot;
	to_bot->prev = temp;
	to_bot->next = NULL;
}
