/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:17:44 by yogun             #+#    #+#             */
/*   Updated: 2024/02/08 18:16:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	ft_rb(t_stack **b)
{
	ft_rr_sub(b);
	while(write(1, "rb\n",3) !=3)
		continue;

	// printf("rb\n");
}

void	ft_sb(t_stack **b)
{
	t_stack	*top;

	top = *b;
	if (top == NULL || top->next == NULL)
		return ;
	node_swap(top, top->next);
	*b = top->prev;
	while(write(1, "sb\n", 3) != 3)
		continue;

}

static void	node_swap_near(t_stack *a, t_stack *b)
{
	t_stack	*first;
	t_stack	*second;

	if (a->next == b)
	{
		first = a;
		second = b;
	}
	else
	{
		first = b;
		second = a;
	}
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
}

void	node_swap(t_stack *a, t_stack *b)
{
	t_stack	*prev;
	t_stack	*next;

	if (a == NULL && b == NULL)
		return ;
	else if (a->next == b || b->next == a)
		node_swap_near(a, b);
	else
	{
		prev = a->prev;
		next = a->next;
		a->next = b->next;
		a->prev = b->prev;
		b->next = next;
		b->prev = prev;
		if (b->next != NULL)
			b->next->prev = b;
		if (b->prev != NULL)
			b->prev->next = b;
		if (a->next != NULL)
			a->next->prev = a;
		if (a->prev != NULL)
			a->prev->next = a;
	}
	return ;
}

void	ft_rr_sub(t_stack **a_top)
{
	t_stack	*to_top;
	t_stack	*to_bot;
	t_stack	*temp;

	temp = *a_top;
	if (temp == NULL || temp->next == NULL)
		return ;
	to_top = temp->next;
	to_bot = temp;
	*a_top = to_top;
	to_top->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = to_bot;
	to_bot->prev = temp;
	to_bot->next = NULL;
}
