/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:52 by isall             #+#    #+#             */
/*   Updated: 2024/11/09 11:53:52 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push(t_stack_node **dest, t_stack_node **source)
{
	t_stack_node *push_node;

	if (!*source)
		return;
	push_node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void pa(t_stack_node **a, t_stack_node **b, bool affich)
{
	push(a, b);
	if (!affich)
		ft_printf("pa\n");
}

void pb(t_stack_node **b, t_stack_node **a, bool affich)
{
	push(b, a);
	if (!affich)
		ft_printf("pb\n");
}
