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
