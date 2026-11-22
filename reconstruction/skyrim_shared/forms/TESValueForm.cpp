// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1f36a0 TESValueForm::Function1f36a0
// Adapted bodies: none
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1f3480 TESValueForm::Function1f3480
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "TESValueForm.h"

void TESValueForm::Function1f36a0(BGSLoadGameBuffer* a_buf)
{
    if (TestBit(a_buf->flags40, 1)) {
        a_buf->LoadDataEndian(&unk08, 4, 4);
    }
}
#include <new>

TESValueForm* TESValueForm::Function1f3480()
{
    return new (this) TESValueForm;
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
