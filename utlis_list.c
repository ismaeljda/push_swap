/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:19:08 by isall             #+#    #+#             */
/*   Updated: 2024/10/28 11:19:08 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node  *ft_lstnew(int content)
{
    t_stack_node  *list;

    list = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!list)
        return (NULL);
    list->nbr = content;
    list->next = NULL;
    return (list);
}

t_stack_node  *ft_lstlast(t_stack_node *lst)
{
    t_stack_node  *current;

    current = lst;
    while (current->next != NULL)
    {
        current = current->next;
    }
    return (current);
}

void    ft_lstadd_front(t_stack_node **lst, t_stack_node *new_node)
{
    if (!lst || !new_node)
        return ;
    new_node->next = *lst;
    *lst = new_node;
}