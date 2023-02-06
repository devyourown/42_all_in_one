#include	"ft_putchar.c"

void	rush(int x, int y)
{
	int dx;
	int	dy;
	
	dy = 1;
	while (dy <= y)
	{
		dx = 1;
		while (dx <= x)
		{
			if ( (dx == 1 || dx == x) && (dy == 1 || dy == y) )
				ft_putchar("o");
			else if( (dy == 1 || dy == y ) )
				ft_putchar("-");
			else
				ft_putchar("|");
			dx++;
		}
		ft_putchar("\n");
		dy++;
	}
}
