// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x1e8660 Leaf1e8660::Invoke
// 0x1e8650 TESImageSpaceModifiableForm::InitializeDataComponent
// 0x1e8760 TESImageSpaceModifiableForm::~TESImageSpaceModifiableForm
#include "TESImageSpaceModifiableForm.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESImageSpaceModifiableForm::TESImageSpaceModifiableForm()
{
}

// ClearDataComponent: the target has no work to do.
void TESImageSpaceModifiableForm::ClearDataComponent()
{
}

// InitializeDataComponent: the target clears the pointer at +0x8.
void TESImageSpaceModifiableForm::InitializeDataComponent()
{
    data08 = nullptr;
}
