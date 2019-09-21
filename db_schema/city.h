#ifndef CITY_H
#define CITY_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/double.h"
#include "../data_types/int.h"
#include "../data_types/string.h"
#include "../pointer/ptr_nation.h"
#include "schema_base_class.h"

// --- City data --- //
class City : public SchemaBaseClass
{
private:
    String      Name;
    Char        GenderName;
    PtrNation   Nation;
    Double      Latitude;
    Double      Longitude;
    Char        Attraction;
    Int         Weather;
    //CityWeather WeatherCity;

    // Friend classes
    friend class CityData;
    friend class CityModel;

public:
    // Constructor
    City();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    QString getDisplayText();
};

#endif // CITY_H
