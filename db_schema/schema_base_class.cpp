#include "schema_base_class.h"

/* ================================= */
/*      Schema/Table Base Class      */
/* ================================= */

// --- Default constructor --- //
SchemaBaseClass::SchemaBaseClass()
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Identifier --- //
QString SchemaBaseClass::getIdentifier()
{
    return m_Identifier;
}

// --- Name (empty virtual class - consider making abstract) --- //
QString SchemaBaseClass::getName()
{
    return "[No implementation of SchemaBaseClass::getName()]";
}


/* ================== */
/*      ID Cache      */
/* ================== */

// --- Synchronise current ID to old ID --- //
void SchemaBaseClass::syncIdCache()
{
    m_OldID.copy(ID);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set identifier --- //
void SchemaBaseClass::setIdentifier(const QString &text)
{
    m_Identifier = text;
}
