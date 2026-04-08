/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:10:46 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:10:49 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remplire_tableau(t_pile *pile, int *tableau)
{
	int	i;

	i = 0;
	while (i <= pile->top)
	{
		tableau[i] = pile->tableau[i];
		i++;
	}
}

void	creer_tableau_trie(t_pile *pile_a, int *trie)
{
	int	i;
	int	j;
	int	temp;

	remplire_tableau(pile_a, trie);
	i = 0;
	while (i < pile_a->top)
	{
		j = 0;
		while (j < pile_a->top - i)
		{
			if (trie[j] > trie[j + 1])
			{
				temp = trie[j];
				trie[j] = trie[j + 1];
				trie[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	rank_pile(t_pile *pile)
{
	int	*trie;
	int	i;
	int	j;

	trie = malloc(sizeof(int) * (pile->top + 1));
	if (!trie)
		return ;
	creer_tableau_trie(pile, trie);
	i = 0;
	while (i <= pile->top)
	{
		j = 0;
		while (j <= pile->top)
		{
			if (pile->tableau[i] == trie[j])
			{
				pile->tableau[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(trie);
}

int	obt_max_bits(t_pile *pile)
{
	int	max;
	int	max_bits;

	max = trouver_max(pile);
	max_bits = 0;
	while (max != 0)
	{
		max /= 2;
		max_bits++;
	}
	return (max_bits);
}

int	obt_position_bit(int nbr, int position)
{
	while (position > 0)
	{
		nbr /= 2;
		position--;
	}
	return (nbr % 2);
}
