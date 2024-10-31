/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemikim <imyourdata@soongsil.ac.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:02:38 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 14:17:25 by jaemikim         ###   ########.fr       */
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
	double	dec;

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
		check_decimal(str, &i, &dec, &res);
	if (str[i] != '\0' && !iswhitespace(str[i]) && str[i] != ',')
		error_print("Invalid argument");
	return (res * sign);
}

void	check_decimal(char *str, int *i, double *dec, double *res)
{
	*i += 1;
	*dec = 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*dec /= 10;
		*res += (str[*i] - '0') * (*dec);
		*i += 1;
	}
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
	if (*str != '\0' && !iswhitespace(*str) && *str != ',')
		error_print("Invalid argument");
	return (flag * sum);
}
