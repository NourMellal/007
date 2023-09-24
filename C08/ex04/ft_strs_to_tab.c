#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *str_dup(char *src)
{
	char 	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
 	struct s_stock_str *res;

	i = 0;
	res = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!res)
		return (NULL);
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = str_dup(av[i]);
		i++;
	}
	res[i].copy = 0;
	res[i].str = 0;
	res[i].size = 0;
	return (res);
}
