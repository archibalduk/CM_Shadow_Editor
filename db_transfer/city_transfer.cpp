#include "city_transfer.h"

// Application headers
#include "../model/city_model.h"

/* ============================ */
/*      City Import/Export      */
/* ============================ */

// --- Default constructor --- //
CityTransfer::CityTransfer(QAbstractTableModel *model) :
    DatabaseTransfer("cities", model)
{
    m_Columns << CityModel::Name
              << NewNameColumn
              << CityModel::Nation
              << CityModel::Latitude
              << CityModel::Longitude
              << CityModel::Attraction
              << CityModel::Weather;
}
