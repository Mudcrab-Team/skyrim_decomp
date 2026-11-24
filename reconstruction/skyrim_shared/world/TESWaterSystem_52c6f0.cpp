// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x52c6f0 TESWaterSystem::Function52c6f0
// Adapted bodies: none
#include "TESWaterSystem_52c6f0.h"

bool TESWaterSystem::Function52c6f0(WaterObject* a_object)
{
    if (a_object) {
        if (a_object->unk30 && a_object->unk30->unk02() == &g_waterType) {
            return a_object->unk30->unk128->unk18->unk10Field == 1;
        }
        return a_object->ApplyCamera(GetWorldRootCamera());
    }
    return false;
}
