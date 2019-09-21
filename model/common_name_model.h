#ifndef MODEL_COMMON_NAME_H
#define MODEL_COMMON_NAME_H

// Application headers
#include "name_model.h"

// --- Common Name Model (sub-class) --- //
class CommonNameModel : public NameModel
{
public:
    // Constructor
    CommonNameModel(QObject *parent = nullptr);
};

#endif // MODEL_COMMON_NAME_H
