// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1db8e0 Leaf1db8e0::Invoke
// 0x1db8d0 BGSSkinForm::InitializeDataComponent
// 0x1dbab0 BGSSkinForm::~BGSSkinForm
#include "BGSSkinForm.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BGSSkinForm::BGSSkinForm()
{
}

// Body done: RVA 0x1db8e0, 3 bytes, BGSSkinForm::ClearDataComponent.
void BGSSkinForm::ClearDataComponent()
{
}

// Body done: RVA 0x1db8d0, 9 bytes, BGSSkinForm::InitializeDataComponent.
void BGSSkinForm::InitializeDataComponent()
{
    ptr08 = nullptr;
}
