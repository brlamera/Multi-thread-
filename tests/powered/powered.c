#include <stdio.h>
#include <math.h>

double	power(double nb, int power)
{
	double	tmp;

	tmp = nb;
	if (power < 0)
	{
		if (nb == 0)
			return(INFINITY);
		while (power <= 0)
		{
			tmp /= nb;
			power++;
		}
	}
	else if (power == 0)
		return (1.0);
	else
	{
		while (power > 1)
		{
			tmp *= nb;
			power--;
		}
	}
	return (tmp);
}


int	main(void)
{
	int omg;

	omg = -3;
	while (omg < 102)
	{
		printf("pour power = %d\n", omg);
		printf("the true one : %f\n", pow(99.01, omg));
		printf("the real one : %f\n", power(99.01, omg));
		printf("\n\n");
		omg++;
	}
}
