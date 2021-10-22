#include "so_long.h"

int    events_key(int key, t_data *game)
{
    printf("dfdf %d", key);
    if (key == KEY_W)
    {
       printf("dfdf %d", game->player_y);
    }
    return (0);
}