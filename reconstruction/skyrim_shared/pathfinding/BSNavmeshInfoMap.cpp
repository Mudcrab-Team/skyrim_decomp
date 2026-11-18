// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x11f01d0 BSNavmeshInfoMap::~BSNavmeshInfoMap
#include "BSNavmeshInfoMap.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSNavmeshInfoMap::BSNavmeshInfoMap()
{
}

BSNavmeshInfoMap::~BSNavmeshInfoMap()
{
    bsNavmeshInfoMapInstance = nullptr;
}
