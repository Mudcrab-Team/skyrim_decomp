// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectLIGH__Data; size 0x28
#pragma once

#include "Color.h"
#include "TES_LIGHT_FLAGS_d6c37478.h"
struct TESObjectLIGH__Data {
    int Time_0;
    int Radius_4;
    Color LightColor_8;
    TES_LIGHT_FLAGS_d6c37478 LightFlags_C;
    float FallOffExponent_10;
    float Fov_14;
    float NearDistance_18;
    float FlickerPeriodRecip_1C;
    float FlickerIntensityAmplitude_20;
    float FlickerMovementAmplitude_24;
};
static_assert(sizeof(TESObjectLIGH__Data) == 40, "TESObjectLIGH__Data layout differs from the PDB");
