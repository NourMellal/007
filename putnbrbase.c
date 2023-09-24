#include <stdlib.h>

// Function to validate the base
int	base_validation(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13)
			|| base[i] == '-'
			|| base[i] == '+'
			|| base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

// Function to get the length of a string
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Function to get the numerical value of a character in a base
int	get_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

// Function to handle signs and spaces
int	signs_spaces(char *str, int *idx)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*idx = i;
	return (sign);
}

// Function to convert a string to an integer based on a given base
int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_num;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	base_num = base_validation(base);
	if (base_num >= 2)
	{
		sign = signs_spaces(str, &i);
		while (str[i] && get_num(str[i], base) != -1)
		{
			res = res * base_num + get_num(str[i], base);
			i++;
		}
		return (res * sign);
	}
	return (0);
}

// Function to calculate the length of the number in the target base
int	length_num(int nbr, char *base, int length)
{
	long	nb;
	int		baselength;

	baselength = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		length++;
	}
	if (nb == 0)
		return (length + 1);
	while ((nb / baselength) > 0)
	{
		nb /= baselength;
		length++;
	}
	return (length);
}

char	*Buff_fill(int num, char *buffer, char *base, int buff_len)
{
	int		i;
	int		base_len;
	long	nb;
	char	*res;

	i = (num < 0) ? 1 : 0;
	base_len = ft_strlen(base);
	nb = num;
	res = malloc(sizeof(char) * (buff_len + 1));
	if (!res)
		return (NULL);
	res[buff_len--] = '\0';
	if (nb < 0)
	{
		buffer[0] = '-';
		nb = -nb;
	}
	while (nb >= base_len)
	{
		buffer[buff_len] = base[nb % base_len];
		nb /= base_len;
		buff_len--;
	}
	if (nb < base_len)
			buffer[i] = base[nb];
	return (res);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*res;
	int		bufflen;

	if (!base_validation(base_from) || !base_validation(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	bufflen = length_num(num, base_to, 0);
	res = Buff_fill(num, res, base_to, bufflen);
	return (res);
}
