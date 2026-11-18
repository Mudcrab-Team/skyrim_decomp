// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1f34d0 Leaf1f34d0::Invoke
// 0x1f34c0 TESValueForm::InitializeDataComponent
// 0x1f36d0 TESValueForm::~TESValueForm
#include "TESValueForm.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESValueForm::TESValueForm()
{
}

// Compared function: RVA 0x1f34d0, 3 bytes, TESValueForm::ClearDataComponent.
void TESValueForm::ClearDataComponent()
{
}

// Compared function: RVA 0x1f34c0, 8 bytes, TESValueForm::InitializeDataComponent.
void TESValueForm::InitializeDataComponent()
{
    unk08 = 0;
}

// Compared as the scalar deleting destructor; the sized delete it calls is bound by RVA in
// bind-hints.json.
TESValueForm::~TESValueForm()
{
}
