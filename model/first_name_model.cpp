#include "first_name_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/name_data.h"

// --- Constructor --- //
FirstNameModel::FirstNameModel(QObject *parent) :
    NameModel(Database::firstNames.Data, ShadowCommon::FIRST_NAMES, parent)
{

}
