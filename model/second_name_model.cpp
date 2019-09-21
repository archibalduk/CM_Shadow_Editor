#include "second_name_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/name_data.h"

// --- Constructor --- //
SecondNameModel::SecondNameModel(QObject *parent) :
    NameModel(Database::secondNames.Data, ShadowCommon::SECOND_NAMES, parent)
{

}
