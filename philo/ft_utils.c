#include <philosopher.h>

int	ft_atoi(char *str)
{
	int	i;
	int nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = nb * 10;
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb);
}
