/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erroc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:10:37 by isall             #+#    #+#             */
/*   Updated: 2024/10/28 10:10:37 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int ft_isdigit( int arg )
{
    if (arg >= '0' && arg <= '9')
        return (1);
    else 
        return (0);
}

static int ft_strcmp(const char *s1, const char *s2) 
{
    while (*s1 && (*s1 == *s2)) 
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int ft_is_correct_char(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-' && str[i] != '+')
            return (0);
        if (str[i] == '-' || str[i] == '+')
        {
            if (ft_isdigit(str[i + 1]) == 0)
                return (0);
        }
        i++;
    }
    return (1);
}

static int ft_double(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (ft_strcmp(str[i], str[j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
static int ft_error_message(void)
{
    printf ("error encountered\n");
    return (1);
}

void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node;

    if (!stack)
        return ;
    node = ft_lstnew(n);
    if (!node)
        free (stack);
    ft_lstadd_front(stack, node);
}

int ft_error (t_stack_node **a, char **str)
{
    int i;
    long nb;
    int j;

    i = 0;
    while (str[i])
    {
        nb = ft_atol(str[i]);
        if (ft_is_correct_char(str[i]) == 0)
            return(ft_error_message());
        if (nb < INT_MIN || nb > INT_MAX)
            return(ft_error_message());
        j = i + 1;
        while (str[j])
        {
            if (ft_strcmp(str[i], str[j]) == 0)
                return(ft_error_message());
            j++;
        }
        i++;
        append_node(a, (int)nb);
    }
    return (0);
}

void print_list (t_stack_node *lst)
{
    t_stack_node *current;

    current = lst;
        while (current->next != NULL)
        {
            printf("%d\n", current->nbr);
            current = current->next;
        }
        printf("%d\n", current->nbr);
}

#include <stdio.h>
int main(int ac, char **av)
{
    t_stack_node *a;

    a = NULL;
    ft_error(&a, av + 1);
    print_list(a);
}