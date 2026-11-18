// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1ef660 Leaf1ef660::Invoke
// 0x1ef650 TESQualityForm::InitializeDataComponent
// 0x1ef6e0 TESQualityForm::~TESQualityForm
#include "TESQualityForm.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESQualityForm::TESQualityForm()
{
}

// Body done: RVA 0x1ef660, 3 bytes, TESQualityForm::ClearDataComponent.
void TESQualityForm::ClearDataComponent()
{
}

// Body done: RVA 0x1ef650, 8 bytes, TESQualityForm::InitializeDataComponent.
void TESQualityForm::InitializeDataComponent()
{
    value08 = 0;
}
