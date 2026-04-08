/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:10:57 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:44:19 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	trouver_position(t_pile *pile, int valeur)
{
	int	i;

	i = 0;
	while (i <= pile->top)
	{
		if (pile->tableau[i] == valeur)
			return (i);
		i++;
	}
	return (-1);
}

int	trouver_max(t_pile *pile)
{
	int	max;
	int	i;

	i = 1;
	max = pile->tableau[0];
	while (i <= pile->top)
	{
		if (max < pile->tableau[i])
			max = pile->tableau[i];
		i++;
	}
	return (max);
}

int	trouver_min(t_pile *pile)
{
	int	min;
	int	i;

	if (pile->top < 0)
		return (0);
	min = pile->tableau[0];
	i = 1;
	while (i <= pile->top)
	{
		if (pile->tableau[i] < min)
			min = pile->tableau[i];
		i++;
	}
	return (min);
}

void	pivoter_vers_valeur(t_pile *pile_a, int valeur)
{
	int	pos;

	pos = trouver_position(pile_a, valeur);
	if (pos <= pile_a->top / 2)
	{
		while (pile_a->tableau[pile_a->top] != valeur)
			rra(pile_a);
	}
	else
	{
		while (pile_a->tableau[pile_a->top] != valeur)
			ra(pile_a);
	}
}
