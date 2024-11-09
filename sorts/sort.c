/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:08:04 by isall             #+#    #+#             */
/*   Updated: 2024/11/09 12:08:04 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = ft_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	ft_prep(a, cheapest_node, 'a');
	ft_prep(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ft_prep(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != ft_min(*a)->nbr)
	{
		if (ft_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b_to_a(a, b);
	}
	ft_current(*a);
	min_on_top(a);
}
