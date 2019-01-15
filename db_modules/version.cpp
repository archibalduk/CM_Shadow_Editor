#include "version.h"

Version::Version() :
    m_VersionNumber(INVALID_VERSION)
{

}

// --- Set database version number --- //
void Version::set(const qint32 &versionNumber)
{
    if(versionNumber >= VERSION_COUNT)
        m_VersionNumber = INVALID_VERSION;
    else
        m_VersionNumber = static_cast<qint8>(versionNumber);
}
