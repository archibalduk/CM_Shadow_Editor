#include "club_comp_data.h"


/* ========================================= */
/*      Club Competition Database Table      */
/* ========================================= */

// --- Default constructor --- //
ClubCompData::ClubCompData() :
    DatabaseContainer<ClubComp, ClubCompModel>()
{

}


/* ===================================== */
/*      Domestic/International Data      */
/* ===================================== */

// --- Calculate the position of the first international item --- //
void ClubCompData::setFirstInternationalItem()
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
void ClubCompData::setNextItemsAsDomestic()
{
    ClubComp::s_NextItemIsDomestic = true;
}

// --- Flag next items to be read/written as international --- //
void ClubCompData::setNextItemsAsInternational()
{
    ClubComp::s_NextItemIsDomestic = false;
}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void ClubCompData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool ClubCompData::sortMethod(const ClubComp &a, const ClubComp &b)
{
    if(a.m_IsDomestic != b.m_IsDomestic)
        return a.m_IsDomestic;

    else return(a.ID.get() < b.ID.get());
}
