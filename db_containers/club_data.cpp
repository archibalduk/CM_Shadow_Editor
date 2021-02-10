#include "club_data.h"


/* ============================= */
/*      Club Database Table      */
/* ============================= */

// --- Default constructor --- //
ClubData::ClubData() :
    DatabaseContainer<Club, ClubModel>()
{

}


/* ===================================== */
/*      Domestic/International Data      */
/* ===================================== */

// --- Calculate the position of the first international item --- //
void ClubData::setFirstInternationalItem()
{
    const qint32 size = Data.size();
    for(qint32 i = 0; i < size; ++i) {
        if(Data[i].m_IsDomestic == false) {
            m_PosFirstInternationalItem = i;
            return;
        }
    }

    m_PosFirstInternationalItem = size;
}

// --- Flag next items to be read/written as domestic --- //
void ClubData::setNextItemsAsDomestic()
{
    Club::s_NextItemIsDomestic = true;
}

// --- Flag next items to be read/written as international --- //
void ClubData::setNextItemsAsInternational()
{
    Club::s_NextItemIsDomestic = false;
}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void ClubData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool ClubData::sortMethod(const Club &a, const Club &b)
{
    if(a.m_IsDomestic != b.m_IsDomestic)
        return a.m_IsDomestic;

    else return(a.ID.get() < b.ID.get());
}
