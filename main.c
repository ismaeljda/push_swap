/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:33 by isall             #+#    #+#             */
/*   Updated: 2024/10/28 10:01:33 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac == 2)
        av = ft_split_2(av[1], ' ');
    ft_error(&a, av + 1);
    if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
