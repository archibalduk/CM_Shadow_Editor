#ifndef NAME_H
#define NAME_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/int.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Name Data --- //
class Name : public SchemaBaseClass
{
private:
    String NameText; // QString representation of NameText[ STANDARD_TEXT_LENGTH ];
    Int Nation;
    Char  Count;

public:
    // Constructor
    Name();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    QString getName();
};

#endif // NAME_H
