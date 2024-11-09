/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:56:55 by isall             #+#    #+#             */
/*   Updated: 2024/11/09 11:56:55 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void rev_rotate(t_stack_node **stack)
{
	t_stack_node *last;

	if (!*stack || !(*stack)->next)
		return;
	last = ft_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void rra(t_stack_node **a, bool affich)
{
	rev_rotate(a);
	if (!affich)
		ft_printf("rra\n");
}

void rrb(t_stack_node **b, bool affich)
{
	rev_rotate(b);
	if (!affich)
		ft_printf("rrb\n");
}

void rrr(t_stack_node **a, t_stack_node **b, bool affich)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!affich)
		ft_printf("rrr\n");
}
