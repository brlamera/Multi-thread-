#include "../includes/rt.h"

int     color_MSAA_RGB(int x, int y, t_win *mlx)
{
    unsigned int color;

    color = (mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)] +
                mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8)] +
                    mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8)] +
                        mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8)] / 4 );

    color += (mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] +
                mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 1] +
                    mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8) + 1] +
                        mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 1] / 4 ) * 256;


    color += (mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] +
                mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 2] +
                    mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8) + 2] +
                        mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 2] / 4 ) * 256 * 256;
    x /= 2;
    y /= 2;
    if (x < (X_WIN / 4) && y < (Y_WIN / 4) && x >= 0 && y >= 0)
    {
        mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)] = color;
        mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] = color >> 8;
        mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] = color >> 16;
    }

    return (color);
}
//
// int     color_MSAA_G(int x, int y)
// {
//     unsigned int color;
//     color = (mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] +
//                 mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 1] +
//                     mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8) + 1] +
//                         mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 1] / 4 );
//     return (color);
// }
//
// int     color_MSAA_B(int x, int y)
// {
//     unsigned int color;
//
//     color = (mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] +
//                 mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 2] +
//                     mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8) + 2] +
//                         mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 2] / 4 );
//     return (color);
// }
//
// void		img_add_px_MSAA(t_win *mlx, unsigned int color, int x, int y)
// {
// 	if (x < (X_WIN / 4) && y < (Y_WIN / 4) && x >= 0 && y >= 0)
// 	{
// 		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)] = color_MSAA_R(x * 2, y * 2);
// 		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] = color_MSAA_G(x * 2, y * 2) >> 8;
// 		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] = color_MSAA_B(x * 2, y * 2) >> 16;
// 	}
// }
