#include <stdlib.h>
#include <stdio.h>


int	is_sperator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	words_count(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!is_sperator(str[i], sep) && is_sperator(str[i + 1], sep))
			words++;
		i++;
	}
	return (words);
}

void	write_in_grid(char *dest, char *src, char *sep)
{
	int	i;

	i = 0;
	while (!is_sperator(src[i], sep))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	grid_define(char **grid, char *str, char *sep)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_sperator(str[i], sep))
			i++;
		else
		{
			j = 0;
			while (!is_sperator(str[i + j], sep))
				j++;
			grid[word] = malloc(sizeof(char) * (j + 1));
			if (!grid[word])
				return ;
			write_in_grid(grid[word], str + i, sep);
			i += j;
			word++;
		}
	}
} /* Hello, World  ", "*/

char **ft_split(char *str, char *charset)
{
	int		words;
	char	**grid;

	words = words_count(str, charset);
	grid = malloc(sizeof(char *) * (words + 1));
	if (!grid)
		return (NULL);
	grid[words] = NULL;
	grid_define(grid, str, charset);
	return (grid);
}

int main() {
    char **result;

    // Test 1: Splitting by space
    result = ft_split("Hello world!", " !");
    // Expected output: "Hello", "world!"
    printf("Test 1:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
		free(result[i]);
    }
	free(result);
    printf("\n");

    // Test 2: Splitting by comma and space
    result = ft_split("        ,,,,    apple, orange, banana        ,,,,,,", ", ");
    // Expected output: "apple", "orange", "banana"
    printf("Test 2:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
		free(result[i]);
    }
	free(result);
    printf("\n");

    // Test 3: Splitting by a character not in the string
    result = ft_split("Hello world!", "z");
    // Expected output: "Hello world!"
    printf("Test 3:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
		free(result[i]);
    }
	free(result);
    printf("\n");

    // Test 4: Splitting by multiple characters
    result = ft_split("a::c::d::e", ":");
    // Expected output: "a", "b", "c", "d", "e"
    printf("Test 4:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
		free(result[i]);
    }
	free(result);
    printf("\n");

    // Test 5: Splitting an empty string
    result = ft_split("", " ");
    // Expected output: (nothing, array should be empty)
    printf("Test 5:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
		free(result[i]);
    }
	free(result);
    printf("\n");

    return 0;
}
