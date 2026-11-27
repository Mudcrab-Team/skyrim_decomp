// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x180880 ExtraDismemberedLimbs::RemoveLimb
// Adapted bodies: none
#include "ExtraDismemberedLimbs_180880.h"

// Marks all dismembered limb entries matching a_limbIndex with the given removed flag.
void ExtraDismemberedLimbs::RemoveLimb(std::uint32_t a_limbIndex, bool a_removed)
{
    for (std::uint32_t i = 0; i < dismemberedLimbs.size; ++i) {
        DismemberedLimb* limb = dismemberedLimbs.data[i];
        if (limb && limb->limbIndex == a_limbIndex) {
            limb->removed = a_removed;
        }
    }
}
