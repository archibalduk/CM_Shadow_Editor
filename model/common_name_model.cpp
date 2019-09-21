#include "common_name_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/name_data.h"

// --- Constructor --- //
CommonNameModel::CommonNameModel(QObject *parent) :
    NameModel(Database::commonNames.Data, ShadowCommon::COMMON_NAMES, parent)
{

}
