// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0x7ee090 Leaf7ee090::Invoke
// 0x7ee9c0 Hazard::OnAddCellPerformQueueReference
// 0x7ee8d0 Hazard::IsPermanent
#include "Hazard.h"

void Hazard::Unk_A3()
{
}

bool Hazard::OnAddCellPerformQueueReference(TESObjectCELL& a_cell) const
{
    return false;
}

// The handler's temporary-ID test on this reference's form ID, negated.
bool Hazard::IsPermanent() const
{
    return !TESDataHandler::singleton->IsTemporaryFormID(formID);
}
