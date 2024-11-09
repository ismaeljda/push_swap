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
#include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
    int nbr;
    int index;
    int cost;
    bool above_median;
    bool cheapest;
    int push_cost;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

//Main function
void ft_error (t_stack_node **a, char **str);
void sort_three(t_stack_node **a);
void sort_stacks(t_stack_node **a, t_stack_node **b);

//init 
void init_a(t_stack_node *a, t_stack_node *b);
void init_b(t_stack_node *a, t_stack_node *b);
void ft_current(t_stack_node *stack);
void set_cheapest(t_stack_node *stack);

//Operations
void			sa(t_stack_node **a, bool affich);
void			sb(t_stack_node **b, bool affich);
void			ss(t_stack_node **a, t_stack_node **b, bool affich);
void			ra(t_stack_node **a, bool affich);
void			rb(t_stack_node **b, bool affich);
void			rr(t_stack_node **a, t_stack_node **b, bool affich);
void			rra(t_stack_node **a, bool affich);
void			rrb(t_stack_node **b, bool affich);
void			rrr(t_stack_node **a, t_stack_node **b, bool affich);
void			pa(t_stack_node **a, t_stack_node **b, bool affich);
void			pb(t_stack_node **b, t_stack_node **a, bool affich);
void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

//utils
int stack_len(t_stack_node *stack);
t_stack_node *ft_last(t_stack_node *stack);
bool stack_sorted(t_stack_node *stack);
t_stack_node *ft_min(t_stack_node *stack);
t_stack_node *ft_max(t_stack_node *stack);
t_stack_node *ft_cheapest(t_stack_node *stack);
void ft_prep(t_stack_node **stack, t_stack_node *top_node, char stack_name);
char    **ft_split_2(char const *s, char c);
long ft_atol(const char *str);
void free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

#endif