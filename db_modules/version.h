#ifndef VERSION_H
#define VERSION_H

// Qt headers
#include <QObject>

// --- Database version controller --- //
class Version
{
private:
    qint8 m_VersionNumber;

public:
    // Constructor
    Version();

    // Set data
    void set(const qint32 &versionNumber);

    // Database version flags
    enum DATABASE_VERSIONS {
        INVALID_VERSION,
        CM_3_9_60 = 1,  // CM 01/02 version 0x01 (original version of CM 01/02)
        CM_3_9_68 = 2,  // CM 01/02 version 0x02 (final version of CM 01/02)
        VERSION_COUNT
    };
};

#endif // VERSION_H
