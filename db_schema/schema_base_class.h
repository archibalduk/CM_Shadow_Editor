#ifndef SCHEMA_BASE_CLASS_H
#define SCHEMA_BASE_CLASS_H

// Qt headers
#include <QString>

// Application headers
#include "../data_types/primary_key.h"

// --- Database table/schema base class --- //
class SchemaBaseClass
{
protected:
    // Primary key
    PrimaryKey ID;

    // Identifier
    QString m_Identifier;

public:
    // Constructor
    SchemaBaseClass();

    // Get data
    QString getIdentifier();
};

#endif // SCHEMA_BASE_CLASS_H
