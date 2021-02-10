#include "spreadsheet_file.h"

// --- Static data --- //
const QRegExp SpreadsheetFile::s_Numerical("\\d*");


/* ===================================== */
/*      Spreadsheet File Base Class      */
/* ===================================== */

// --- Default constructor --- //
SpreadsheetFile::SpreadsheetFile() :
    m_HeaderCount(2),
    m_ProgressDialog("Spreadsheet File", 0, 1)
{
    m_ProgressDialog.setSilent(m_HideProgress);
}

// --- Actual constructor --- //
SpreadsheetFile::SpreadsheetFile(QFile &file) :
    m_File(&file),
    m_HeaderCount(2),
    m_ProgressDialog("Spreadsheet File", 0, 1)
{
    m_ProgressDialog.setSilent(m_HideProgress);
}

// --- Desctructor --- //
SpreadsheetFile::~SpreadsheetFile()
{
    m_ProgressDialog.complete();
}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read cells --- //
bool SpreadsheetFile::read(QVector<QVector<QVariant>> &/*cells*/, const qint32 &/*headerCount*/)
{
    // Virtual wrapper method
    return false;
}

// --- Write cells --- //
bool SpreadsheetFile::writeCells(QVector<QVector<QVariant>> &/*prefix*/, QVector<QVector<QVariant> > &/*cells*/)
{
    // Virtual wrapper method
    return false;
}

// --- Write header cells --- //
bool SpreadsheetFile::writeHeader(QVector<QVector<QVariant>> &/*prefix*/, QVector<QVector<QVariant> > &/*header*/)
{
    // Virtual wrapper method
    return false;
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Show/hide progress dialog --- //
void SpreadsheetFile::setSilent(const bool silent)
{
    m_HideProgress = silent;
}
