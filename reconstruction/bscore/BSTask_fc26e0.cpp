// Source exposure: mixed (community headers, pinned image, image RTTI and the 2013 map).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original body based on the pinned game build; declarations follow powerof3/CommonLibSSE.
// Adapted bodies: none
// 0xfc26e0 BSTask::GetDescription
#include "BSTask_fc26e0.h"

#include <string.h>

// The CrashLogger PDB calls this slot GetName, with a folded Havok function's prototype; the community header and 2013 map name are kept.
// Writes the default description; returns false because a plain task has none of its own.
bool BSTask::GetDescription(char* a_dest, std::uint32_t a_maxCount)
{
    strncpy_s(a_dest, static_cast<rsize_t>(a_maxCount) + 1, "Unnamed", a_maxCount);
    return false;
}
