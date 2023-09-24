#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

typedef int t_bool;
const t_bool ft_false = 0;
const t_bool ft_true = 1;
#define FALSE ft_false
#define TRUE ft_true
#define EVEN(number) (number % 2 == 0)
#define SUCCESS 0
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

#endif
