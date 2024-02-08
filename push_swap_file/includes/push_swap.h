/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:40:31 by janhan            #+#    #+#             */
/*   Updated: 2024/02/08 17:55:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_process(int argc, char **argv);
void	ft_index(t_stack **stack_a);
/* ERROR */
void	ft_error(void);
void	ft_free(t_stack **lst);

/* CHECK UTILS*/
int	ft_checkdup(t_stack *a);
int	ft_checksorted(t_stack *stack_a);
/* STACK UTILS */
long	ft_find_index(t_stack *a, int nbr, size_t *order);
long	ft_find_min_index(t_stack *a, int index);
t_stack *ft_find_max_addr(t_stack **stack);
t_stack	*ft_stacklast(t_stack *lst);
size_t	ft_stacksize(t_stack *lst);
t_stack	*ft_stack_new(int content);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
int	ft_min(t_stack *a);
int	ft_max(t_stack *a);
int	ft_get_cunk(t_stack **stack_a);
/* OPERATIONS */
void	ft_ra(t_stack **a);
void	ft_sa(t_stack **a);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr_sub(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rrb(t_stack **b);
void	ft_rb(t_stack **b);
void	ft_sb(t_stack **b);
void	node_swap(t_stack *a, t_stack *b);
void	ft_rr_sub(t_stack **a_top);
/* SORT */
void	ft_sort(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
void	down_pa(t_stack **a_top_p, t_stack **b_top_p, t_stack *to_find);
void	up_pa(t_stack **a_top_p, t_stack **b_top_p, t_stack *to_find);
#endif
