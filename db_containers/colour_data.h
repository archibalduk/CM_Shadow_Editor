#ifndef COLOUR_DATA_H
#define COLOUR_DATA_H

// Application headers
#include "../db_schema/colour.h"
#include "../model/colour_model.h"
#include "database_container.h"

// --- Colour database table --- //
class ColourData : public DatabaseContainer<Colour, ColourModel>
{
public:
    ColourData();
};

#endif // COLOUR_DATA_H
