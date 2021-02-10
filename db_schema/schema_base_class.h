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
    PrimaryKey m_OldID; // For caching old ID numbers before all pointers are updated with the new IDs

    // Identifier
    QString m_Identifier;

    // Set data
    void setIdentifier(const QString &text);

public:
    // Constructor
    SchemaBaseClass();
    virtual ~SchemaBaseClass() {}

    // Get data
    QString getIdentifier();
    virtual QString getName();

    // ID cache
    void syncIdCache();
};

#endif // SCHEMA_BASE_CLASS_H
