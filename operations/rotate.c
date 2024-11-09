/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:33 by isall             #+#    #+#             */
/*   Updated: 2024/11/09 11:58:33 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	if (!*stack || !(*stack)->next)
		return;
	last_node = ft_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void ra(t_stack_node **a, bool affich)
{
	rotate(a);
	if (!affich)
		ft_printf("ra\n");
}

void rb(t_stack_node **b, bool affich)
{
	rotate(b);
	if (!affich)
		ft_printf("rb\n");
}

void rr(t_stack_node **a, t_stack_node **b, bool affich)
{
	rotate(a);
	rotate(b);
	if (!affich)
		ft_printf("rr\n");
}
