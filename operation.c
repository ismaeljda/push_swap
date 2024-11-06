/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:42:59 by isall             #+#    #+#             */
/*   Updated: 2024/10/28 11:42:59 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap (t_stack_node *lst)
{
    int tmp;

    if (!lst || !lst->next)
        return;
    tmp = lst->nbr;
    lst->nbr = lst->next->nbr;
    lst->next->nbr = tmp;
}

void    ft_push (t_stack_node **lst_a, t_stack_node **lst_b)
{
    t_stack_node *node;
    t_stack_node *next;
    if (!lst_a || !*lst_a)
        return ;
    node = ft_lstnew((*lst_a)->nbr);
    if (!node)
        return ;
    next = (*lst_a)->next;
    ft_lstadd_front (lst_b,node);
    ft_lstdelone (*lst_a);
    *lst_a = next;
}

void    ft_rotate(t_stack_node **lst)
{
    t_stack_node *current;
    t_stack_node *first;
    
    if (!*lst || !lst || !(*lst)->next)
        return ;
    first = *lst;
    *lst = first->next;
    current = *lst;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = first;
    first->next = NULL;
}

void    ft_reverse_rotate(t_stack_node **lst)
{
    t_stack_node *current;
    t_stack_node *first;
    
    if (!*lst || !lst || !(*lst)->next)
        return ;
    first =  *lst;
    current = *lst;
    while (current->next->next != NULL)
        current = current->next;
    *lst = current->next;
    current->next = NULL;
    (*lst)->next = first;
}