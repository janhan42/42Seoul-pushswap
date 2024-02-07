/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:22:46 by janhan            #+#    #+#             */
/*   Updated: 2024/02/07 09:03:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_get_cunk(t_stack **stack_a)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size > 450)
		return (31);
	else if (401 <= size && size == 450)
		return (28);
	else if (301 <= size && size == 400)
		return (26);
	else if (251 <= size && size == 300)
		return (23);
	else if (201 <= size && size == 250)
		return (22);
	else if (151 <= size && size == 200)
		return (20);
	else if (51 < size && size <= 150)
		return (17);
	else if (25 < size && size <= 50)
		return (15);
	else
		return (14);
}
