#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	count;
	int	res;

	sign = 1;
	count = 0;
	res = 0;
	while (nptr[count] == ' ' || (nptr[count] >= 9 && nptr[count] <= 13))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = sign * -1;
		count++;
	}
	while (nptr[count] >= '0' && nptr[count] <= '9')
	{
		res = res * 10 + nptr[count] - '0';
		count++;
	}
	return (res * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*ret;
	size_t		i;

	i = 0;
	ret = (char *)malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (i < count * size)
	{
		((char *)ret)[i] = '\0';
		i++;
	}
	return ((void *)ret);
}

int calc_base (int arg)
{
	int base = 7;
	int increment = 8;
	int i = 1;

	while (i != arg)
	{
		if (i % 2 == 0)
			increment += 2;
		else
			increment += 4;
		base += increment;
		i++;
	}
	return base;
}

int nb_lines(int nb)
{
    int ret;

    ret = nb;
    while (nb--)
        ret += nb + 2;
    return (ret);
}

int nb_space(int num_line, int base)
{
	int spaces = (base / 2) - 1;
    int i = 0;
	int lap = 0;
	int block = 1;
	int decrement = 3;
	int change_block = 3;

    while (i < num_line)
    {
		if (decrement == 0)
		{
			lap++;
			block += 1;
			decrement = block + 2;
			spaces -= change_block;
			if (lap % 2 == 0)
				change_block += 1;
		}
		else {
			spaces--;
		}
		decrement--;
		i++;
    }
    return (spaces + 1);
}

int nb_char(int num_line)
{
	int ret = 1;
	int increment = 3;
	int	augment = 3;
	int block = 1;
	int lap = 0;
	int i = 0;

	while (i < num_line)
	{
		if (increment == 0)
		{
			lap++;
			block += 1;
			increment = block + 2;
			ret += (augment * 2);
			if (lap % 2 == 0)
				augment += 1;
		}
		else {
			ret += 2;
		}
		increment--;
		i++;
	}
	return ret - 2;
}

void print_sastantua(int arg)
{
	int base;
	int height;
	int i = 1;
	int spaces;
	int stars;

	if (arg < 1)
		return ;
	base = calc_base(arg);
	height = nb_lines(arg);

	while (i <= height)
	{
		spaces = nb_space(i, base);
		stars = nb_char(i);
		while (spaces > 0)
		{
			write(1, " ", 1);
			spaces--;
		}
		write(1, "/", 1);
		while (stars--)
		{
			if (i > height - arg + (arg % 2 == 0))
			{
				if (stars >= (base / 2) - ((arg - (arg % 2 == 0)) / 2) - (height - i) - 1
					&& stars <= (base/2) + ((arg - (arg % 2 == 0))/2) - (height - i) - 1)
					{
						if (height - i == arg / 2 - (arg % 2 == 0)
							&& arg >= 5
							&& stars == (base / 2) - (arg - (arg % 2 == 0) / 2) + 1 + (arg % 2 == 0))
							write(1, "$", 1);
						else
							write(1, "|", 1);
					}
				else
					write(1, "*", 1);
			}
			else
				write(1, "*", 1);
		}
		write(1, "\\", 1);
		write(1, "\n", 1);
		i++;
	}
}

int main (int argc, char **argv) {
	if (argc != 2)
		return 0;
	print_sastantua(ft_atoi(argv[1]));
}