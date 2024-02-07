/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:15:03 by janhan            #+#    #+#             */
/*   Updated: 2024/02/07 09:29:14 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct	s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* ===== ERROR ===== */
void	ft_error(void);
int		ft_checkdup(t_stack *a);
int	check_error(char **argv, int i, int j);
/* ===== STACK UTILS ===== */
t_stack	*ft_stack_new(int value);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stacklast(t_stack *lst);
void	list_args(char **av, t_stack **stack_a);

/* ===== STACK ====== */
t_stack	*ft_process(int ac, char **av);
t_stack	*ft_parse_args_quoted(char **argv);
/* ===== STACK UTILS ====== */
int		ft_get_cunk(t_stack **stack_a);
t_stack	*ft_stacklast(t_stack *lst);
size_t	ft_stacksize(t_stack *stack);
int	ft_min(t_stack *stack);
int	ft_max(t_stack *stack);
long ft_find_index(t_stack *a, int nbr, size_t *order);
int	ft_find_place_b(t_stack *stack_b, int nbr_push);
int	ft_find_place_a(t_stack *stack_a, int nbr_push);

/* ===== TYPE UTILS ===== */
int	ft_rotate_type_ba(t_stack *a, t_stack *b);
int	ft_rotate_type_ab(t_stack *a, t_stack *b);

/* ===== SROTED ====== */
int		ft_checksorted(t_stack *stack_a);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort(t_stack **stack_a);

/* ===== FREE ===== */
void	ft_freestr(char **str);
void	ft_free(t_stack **stack);

/* ===== OPERATIONS ===== */
void	ft_sa(t_stack **a, int j);
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rra(t_stack **a, int j);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_rrb(t_stack	**b, int j);
void	ft_rb(t_stack **b, int j);
void	ft_sb(t_stack **b, int j);

void	ft_index(t_stack **stack);


#endif