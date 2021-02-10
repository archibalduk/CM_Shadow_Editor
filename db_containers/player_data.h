#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

// Application headers
#include "../db_schema/player.h"
#include "simple_container.h"

// --- Player database table --- //
class PlayerData : public SimpleContainer<Player>
{
public:
    // Constructor
    PlayerData();
};

#endif // PLAYER_DATA_H
