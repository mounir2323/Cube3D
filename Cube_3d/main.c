
#include "cub3d.h"


// int main() {
//     void *mlx_ptr;


//     mlx_ptr = mlx_init(WIDTH, HEIGHT,"fenetre", true );
//     if (!mlx_ptr)
//         return -1;
//     mlx_loop(mlx_ptr);

//     return 0;
// }

// int main() // main function
// {
//  t_data *data;

//  data = init_argumet(); // init the data structure
//  start_the_game(data); // start the game
//  return 0;
// }

int main() // main function
{
 t_data *data;

 data = init_argumet(); // init the data structure
 start_the_game(data); // start the game
 return 0;
}