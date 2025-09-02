/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:50:25 by shebaz            #+#    #+#             */
/*   Updated: 2024/05/07 23:32:23 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	additional_case(char *str, int n, long **arr, char **tab)
{
	int	i;

	i = 0;
	if (str[i] != '\0' || (str[i] < '0' && str[i] > '9') || n >= 11)
	{
		free(*arr);
		if (tab)
			free_tab(tab);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	skip_plus_moins(char *str, int *i, long **arr, char **tab)
{
	int	tmp;
	int	signe;

	tmp = 0;
	signe = 1;
	(void)(arr);
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			signe = -1;
		(*i)++;
		tmp++;
	}
	if ((tmp == 1 && ft_strlen(str) == 1) || tmp > 1)
	{
		free(*arr);
		if (tab)
			free_tab(tab);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (signe);
}

long	ft_atoi(char *str, long **arr, char **tab)
{
	int			i;
	int			sum;
	int			signe;
	long		result;
	int			k;

	i = 0;
	sum = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	k = i;
	signe = skip_plus_moins(str, &i, arr, tab);
	while (str[i] == '0')
		i++;
	k = i - k;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		sum++;
	}
	additional_case(str + i, sum - k, arr, tab);
	return (signe * result);
}
