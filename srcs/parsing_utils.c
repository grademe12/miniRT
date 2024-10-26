/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:02:38 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 17:03:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	check_argument(char **split, int num)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != num)
		return (0);
	return (1);
}

double	ft_atof(char *str)
{
	double	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		double  dec;
		dec = 1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			dec /= 10;
			res += (str[i] - '0') * dec;
			i++;
		}
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	sum;
	int	flag;

	sum = 0;
	flag = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - 48);
		str++;
	}
	return (flag * sum);
}