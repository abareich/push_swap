/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:11:10 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:11:12 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_duplicates(t_pile *pile)
{
	int	i;
	int	j;

	i = 0;
	while (i <= pile->top)
	{
		j = i + 1;
		while (j <= pile->top)
		{
			if (pile->tableau[i] == pile->tableau[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_pile *pile)
{
	int	i;

	i = 0;
	while (i < pile->top)
	{
		if (pile->tableau[i] < pile->tableau[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_secure(char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > 2147483647) || (sign == -1
				&& result > 2147483648))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

int	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
