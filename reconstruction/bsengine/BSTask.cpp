// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none.
// 0xfc26e0 BSTask::GetDescription
// 0x19be50 BSTask::~BSTask
#include "BSTask.h"
#include <cstddef>

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSTask::BSTask()
{
}

