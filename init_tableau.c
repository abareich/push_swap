/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tableau.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:09:15 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:09:23 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_tableau(int ac, char **av, t_pile *pile_a, t_pile *pile_b)
{
	int	error;

	if (ac < 2)
		return (0);
	pile_a->top = -1;
	pile_b->top = -1;
	ac--;
	while (ac > 0)
	{
		if (!is_number(av[ac]))
			return (0);
		pile_a->tableau[++pile_a->top] = ft_atoi_secure(av[ac], &error);
		if (error)
			return (0);
		ac--;
	}
	if (is_duplicates(pile_a))
		return (0);
	return (1);
}

void	free_pile(t_pile *pile_a, t_pile *pile_b)
{
	free(pile_a->tableau);
	free(pile_a);
	free(pile_b->tableau);
	free(pile_b);
}
