// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x416ca0 Sky::sub_1403B6250
#include "Sky_416ca0.h"

TES* g_tes;

void Sky::sub_1403B6250(BGSLightingTemplate* a_template, NiColor& a_c1, NiColor& a_c2, NiColor& a_c3, NiColor& a_c4)
{
    if (a_template)
    {
        a_template->Function295690(a_c1);
        a_template->Function295610(a_c2);
        a_template->Function2957a0(a_c3);
        a_template->Function295800(a_c4);
    }
    else if (g_tes->interiorCell)
    {
        g_tes->interiorCell->Function2bbf30(a_c1);
        g_tes->interiorCell->Function2bbe40(a_c2);
        g_tes->interiorCell->Function2bc1b0(a_c3);
        g_tes->interiorCell->Function2bc240(a_c4);
    }
    else if (extLightingOverride)
    {
        extLightingOverride->Function295690(a_c1);
        extLightingOverride->Function295610(a_c2);
        extLightingOverride->Function2957a0(a_c3);
        extLightingOverride->Function295800(a_c4);
    }
    else
    {
        a_c1 = GetSky()->skyColorSun;
        a_c2 = GetSky()->skyColorSunlight;
        a_c3 = GetSky()->skyColorUnknown;
        a_c4 = GetSky()->skyColorSkyStatics;
    }
}
