/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:31:55 by isall             #+#    #+#             */
/*   Updated: 2024/11/09 12:31:55 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	ft_current(*a);
	ft_current(*b);
}

void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	ft_current(*a);
	ft_current(*b);
}