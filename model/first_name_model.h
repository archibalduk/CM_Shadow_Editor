#ifndef MODEL_FIRST_NAME_H
#define MODEL_FIRST_NAME_H

// Application headers
#include "name_model.h"

// --- First Name Model (sub-class) --- //
class FirstNameModel : public NameModel
{
public:
    // Constructor
    FirstNameModel(QObject *parent = nullptr);
};

#endif // MODEL_FIRST_NAME_H
