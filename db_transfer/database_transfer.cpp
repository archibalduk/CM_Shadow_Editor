#include "database_transfer.h"

// Application headers
#include "../model/model_base_class_wrapper.h"

/* =========================================== */
/*      Database Import/Export Base Class      */
/* =========================================== */

// --- Default constructor --- //
DatabaseTransfer::DatabaseTransfer(QString identifier, QAbstractTableModel *model) :
    m_Model(model),
    m_Identifier(identifier.replace(" ", "_").toLower())
{
    m_Columns << ModeColumn;
}


/* =================== */
/*      Cell Data      */
/* =================== */

// --- Get data from a particular cell from the underlying model --- //
QVariant DatabaseTransfer::data(const qint32 &row, const qint32 &col)
{
    // For performance reasons, this function does not include any sanity check
    // if(col < 0 || col >= m_Columns.size())
    //      return QString();

    const qint32 columnId = m_Columns.at(col);

    if(columnId >= ModeColumn)
        return QVariant();
    else {
        QModelIndex idx = m_Model->index(row, columnId);
        return m_Model->data(idx, ModelBaseClassWrapper::SpreadsheetRole);
    }
}

// --- Get data from a particular cell from the proxy --- //
QVariant DatabaseTransfer::data(QSortFilterProxyModel *proxy, const qint32 &row, const qint32 &col)
{
    // For performance reasons, this function does not include any sanity check
    // if(col < 0 || col >= m_Columns.size())
    //      return QString();

    const qint32 columnId = m_Columns.at(col);

    if(columnId >= ModeColumn)
        return QVariant();
    else {
        QModelIndex idx = proxy->index(row, columnId);
        return proxy->data(idx, ModelBaseClassWrapper::SpreadsheetRole);
    }
}

// --- Get heading title for a column --- //
QString DatabaseTransfer::heading(const qint32 &col)
{
    // For performance reasons, this function does not include any sanity check
    // if(col < 0 || col >= m_Columns.size())
    //      return QString();

    const qint32 columnId = m_Columns.at(col);

    if(columnId == ModeColumn)
        return QObject::tr("Mode");
    else if(columnId == NewNameColumn)
        return QObject::tr("New Long Name");
    else if(columnId == NewLongNameColumn)
        return QObject::tr("New Long Name");
    else
        return m_Model->headerData(columnId, Qt::Horizontal).toString();
}


/* ===================== */
/*      Export Data      */
/* ===================== */

// --- Export all data --- //
bool DatabaseTransfer::exportData()
{
    Spreadsheet sheet;
    if(sheet.showSaveDialog() == false)
        return false;

    // Identifier
    sheet.addHeader(m_Identifier);
    sheet.addNewHeaderRow();

    // Heading
    const qint32 cols = m_Columns.size();
    for(qint32 c = 0; c < cols; ++c)
        sheet.addHeader(this->heading(c));

    // Data
    const qint32 rows = m_Model->rowCount();
    for(qint32 r = 0; r < rows; ++r) {  // Rows

        sheet.addNewRow();

        for(qint32 c = 0; c < cols; ++c) { // Cols
            sheet.add(this->data(r, c));
        }
    }

    return sheet.write();
}

// --- Export filtered data --- //
bool DatabaseTransfer::exportData(QSortFilterProxyModel *proxy)
{
    Spreadsheet sheet;
    if(sheet.showSaveDialog() == false)
        return false;

    // Identifier
    sheet.addHeader(m_Identifier);
    sheet.addNewHeaderRow();

    // Heading
    const qint32 cols = m_Columns.size();
    for(qint32 c = 0; c < cols; ++c)
        sheet.addHeader(this->heading(c));

    // Data
    const qint32 rows = proxy->rowCount();
    for(qint32 r = 0; r < rows; ++r) {  // Rows

        sheet.addNewRow();

        for(qint32 c = 0; c < cols; ++c) { // Cols
            sheet.add(this->data(proxy, r, c));
        }
    }

    return sheet.write();
}


/* ===================== */
/*      Import Data      */
/* ===================== */

// --- Import data --- //
bool DatabaseTransfer::importData()
{
    Spreadsheet sheet;
    if(sheet.showSaveDialog() == false)
        return false;

    // Validate identifier
    if(sheet.identifier() != m_Identifier)
        return false;

    // Data
    const qint32 rows = sheet.rowCount();
    const qint32 cols = m_Columns.size();

    for(qint32 r = 0; r < rows; ++r) {

        for(qint32 c = 0; c < cols; ++c) { // Cols

            const QVariant data = sheet.cell(r, c);

            if(data.isNull())
                continue;

            QModelIndex idx = m_Model->index(r, c);
            m_Model->setData(idx, ModelBaseClassWrapper::SpreadsheetRole);
        }
    }

    return true;
}
