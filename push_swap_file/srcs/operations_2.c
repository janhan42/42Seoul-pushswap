/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:19:40 by yogun             #+#    #+#             */
/*   Updated: 2024/02/08 19:11:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rr_sub(a);
	ft_rr_sub(b);
	// write(1, "rr\n", 3);
	while(write(1, "rr\n", 3)!=3)
		continue;
	// printf("rr\n");
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

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rrr_sub(a);
	ft_rrr_sub(b);
	// ft_printf("rrr\n");
	while(write(1, "rrr\n", 4)!= 4)
		continue;
	// printf("rrr\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack *first_a;

	if (!*a)
		return ;
	first_a = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (*b)
		(*b)->prev = first_a;
	first_a->next = *b;
	first_a->prev = NULL;
	*b = first_a;
	while(write(1,"pb\n", 3) != 3)
		continue;
	// printf("pb\n");
	// write(1, "pb\n", 3);
}

void	ft_rrb(t_stack **b)
{
	ft_rrr_sub(b);
	while(write(1, "rrb\n", 4) !=4)
		continue;
	// printf("rrb\n");
}
