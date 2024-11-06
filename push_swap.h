/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:55:34 by isall             #+#    #+#             */
/*   Updated: 2024/10/28 09:55:34 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_stack_node
{
    int nbr;
    int index;
    int cost;
    bool above_median;
    bool cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

char    **ft_split(char const *s, char c);
long ft_atol(const char *str);
t_stack_node  *ft_lstnew(int content);
t_stack_node  *ft_lstlast(t_stack_node *lst);
void    ft_lstadd_front(t_stack_node **lst, t_stack_node *new_node);
int ft_error (t_stack_node **a, char **str);

//Operations

void    ft_swap (t_stack_node *lst);
void    ft_push (t_stack_node **lst_a, t_stack_node **lst_b);
void    ft_rotate(t_stack_node **lst);
void    ft_reverse_rotate(t_stack_node **lst);
#endif