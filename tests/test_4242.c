#include <stdio.h>

int		ft_strlen(char *str);

int		rt_parser_is_correct(char *str, char *ac, int len)
{
	int		i;
	int		u;
	int		lenac;
	int		ok;

	ok = 1;
	u = 0;
	i = 0;
	lenac = ft_strlen(ac);
	while (i < len)
	{
		ok = 1;
		u = 0;
		while (u < lenac && ok)
		{
			if (str[i] == ac[u])
				ok = 0;
			u++;
		}
		if (ok)
			return (0);
		i++;
	}
	return (1);
}


int main(void)
{
	printf("test 1: %d", rt_parser_is_correct("AFFBDww", "0123456789ABCDEF", 6));



	return (0);
}
