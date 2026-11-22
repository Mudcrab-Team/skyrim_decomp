// Source exposure: mixed (local instruction listings of the pinned image and community declarations).
// 0x1d2750 BGSDestructibleObjectForm::InitializeDataComponent
// 0x1d2760 BGSDestructibleObjectForm::ClearDataComponent
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x1d26d0 BGSDestructibleObjectForm::Ctor
// Adapted bodies: none
#include "BGSDestructibleObjectForm.h"

BGSDestructibleObjectForm::BGSDestructibleObjectForm() : data(nullptr)
{
}

void BGSDestructibleObjectForm::InitializeDataComponent()
{
    data = nullptr;
}

void BGSDestructibleObjectForm::ClearDataComponent()
{
    if (data) {
        data->Destroy(1);
    }
    data = nullptr;
}
