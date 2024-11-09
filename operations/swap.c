/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:59:26 by isall             #+#    #+#             */
/*   Updated: 2024/11/09 11:59:26 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_stack_node **lst)
{
	if (!*lst || !(*lst)->next)
		return;
	*lst = (*lst)->next;
	(*lst)->prev->prev = *lst;
	(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	(*lst)->next = (*lst)->prev;
	(*lst)->prev = NULL;
}

void sa(t_stack_node **a, bool affich)
{
	swap(a);
	if (!affich)
		ft_printf("sa\n");
}

void sb(t_stack_node **b, bool affich)
{
	swap(b);
	if (!affich)
		ft_printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b, bool affich)
{
	swap(a);
	swap(b);
	if (!affich)
		ft_printf("ss\n");
}
