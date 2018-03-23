#include <math.h>
#include <stdio.h>

int			main(void)
{
	float	i;
	i = 0;
	while (i < 1.1)
	{

	printf("i : %f ret :%f\n", i, -10*log10(i));
		i += 0.1;
	}
	return (0);
}
