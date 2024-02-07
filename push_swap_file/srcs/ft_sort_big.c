/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:54:03 by janhan            #+#    #+#             */
/*   Updated: 2024/02/07 15:51:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void optimize_rotation(t_stack **stack_a, int index, int chunk)
{
	int size = ft_stacksize(*stack_a);
	int mid = size / 2;
	int count_from_top = 0;
	int count_from_bottom = 1;
	t_stack *current = *stack_a;
	t_stack *tail = NULL;

	// 스택의 끝(tail)을 찾기
	while (current && current->next)
		current = current->next;
	tail = current;
	// 상단에서 조건에 맞는 노드까지의 거리 계산
	current = *stack_a;
	while (current && !(current->index < index + chunk))
	{
		count_from_top++;
		current = current->next;
	}
	// 하단에서 조건에 맞는 노드까지의 거리 계산
	// current = tail;
	// while (current && !(current->index < index + chunk))
	// {
	// 	count_from_bottom++;
	// 	current = current->prev; // 이전 노드로 이동 (더블 링크드 리스트인 경우)
	// }
	//printf("f_top: %d , f_bottom %d \n", count_from_top, count_from_bottom);
	if (!count_from_top)
		return ;
	while (count_from_top-- > 0)
		ft_ra(stack_a);
	// else
	// {
	// 	while (count_from_bottom-- > 0)
	// 		ft_rra(stack_a);
	// }
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	size;
	long	index;
	int		count;
	int		cunk;

	stack_b = NULL;
	size = ft_stacksize(*stack_a);
	cunk = ft_get_cunk(stack_a);
	index = 0;
	count = 0;
	while (size--)
	{
		optimize_rotation(stack_a, index, cunk);
		int tttt = (*stack_a)->index;
		ft_pb(stack_a, &stack_b);
		if (count < tttt && tttt <= count + cunk)
			ft_rb(&stack_b);
		index++;
		count++;
	}
	return (stack_b);
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	size_t	b_size;
	int		to_find;
	size_t	order;

	temp = *stack_b;
	b_size = ft_stacksize(*stack_b);
	while (*stack_b)
	{
		to_find = ft_find_index(*stack_b, ft_max(*stack_b), &order);
		if (order > ft_stacksize(*stack_b) / 2)
			down_pa(stack_a, stack_b, ft_find_max_addr(stack_b));
		else
		 	up_pa(stack_a, stack_b, ft_find_max_addr(stack_b));
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	size_t	size;

	stack_b = NULL;
	size = ft_stacksize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	if (size == 3)
		ft_sort_three(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
	}
}