#ifndef NON_PLAYER_DATA_H
#define NON_PLAYER_DATA_H

// Application headers
#include "../db_schema/non_player.h"
#include "simple_container.h"

// --- Non-player database table --- //
class NonPlayerData : public SimpleContainer<NonPlayer>
{
public:
    // Constructor
    NonPlayerData();
};

#endif // NON_PLAYER_DATA_H
