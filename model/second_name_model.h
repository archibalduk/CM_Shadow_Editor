#ifndef MODEL_SECOND_NAME_H
#define MODEL_SECOND_NAME_H

// Application headers
#include "name_model.h"

// --- Second Name Model (sub-class) --- //
class SecondNameModel : public NameModel
{
public:
    // Constructor
    SecondNameModel(QObject *parent = nullptr);
};

#endif // MODEL_SECOND_NAME_H
