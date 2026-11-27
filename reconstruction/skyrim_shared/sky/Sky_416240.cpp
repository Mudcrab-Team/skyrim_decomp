// Source exposure: mixed (binary-analysis of the pinned image, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x416240 Sky::UpdateLightLODFadeDistances
#include "Sky_416240.h"

void Sky::UpdateLightLODFadeDistances()
{
    float start;

    if (!(lightingTransition <= 0.0f))
    {
        float prevStart;
        float prevEnd;
        if (GetPreviousRoomLightingTemplate())
        {
            prevStart = GetPreviousRoomLightingTemplate()->Function295920();
            prevEnd = GetPreviousRoomLightingTemplate()->Function295940();
        }
        else if (TES::GetSingleton()->GetInteriorCell())
        {
            prevStart = TES::GetSingleton()->GetInteriorCell()->Function2bc540();
            prevEnd = TES::GetSingleton()->GetInteriorCell()->Function2bc5b0();
        }
        else if (unk28)
        {
            prevStart = unk28->Function295920();
            prevEnd = unk28->Function295940();
        }
        else
        {
            prevStart = g_defaultLightLODStart;
            prevEnd = g_defaultLightLODRange + prevStart;
        }

        float curStart;
        float curEnd;
        if (GetCurrentRoomLightingTemplate())
        {
            curStart = GetCurrentRoomLightingTemplate()->Function295920();
            curEnd = GetCurrentRoomLightingTemplate()->Function295940();
        }
        else if (TES::GetSingleton()->GetInteriorCell())
        {
            curStart = TES::GetSingleton()->GetInteriorCell()->Function2bc540();
            curEnd = TES::GetSingleton()->GetInteriorCell()->Function2bc5b0();
        }
        else if (unk28)
        {
            curStart = unk28->Function295920();
            curEnd = unk28->Function295940();
        }
        else
        {
            curStart = g_defaultLightLODStart;
            curEnd = g_defaultLightLODRange + curStart;
        }

        float end = (curEnd - prevEnd) * lightingTransition + prevEnd;
        start = (curStart - prevStart) * lightingTransition + prevStart;
        g_lightLODFadeEndSq = end * end;
        g_lightLODFadeStartSq = start * start;
    }
    else
    {
        float end;
        if (GetCurrentRoomLightingTemplate())
        {
            start = GetCurrentRoomLightingTemplate()->Function295920();
            end = GetCurrentRoomLightingTemplate()->Function295940();
        }
        else if (TES::GetSingleton()->GetInteriorCell())
        {
            start = TES::GetSingleton()->GetInteriorCell()->Function2bc540();
            end = TES::GetSingleton()->GetInteriorCell()->Function2bc5b0();
        }
        else if (unk28)
        {
            start = unk28->Function295920();
            end = unk28->Function295940();
        }
        else
        {
            start = g_defaultLightLODStart;
            end = g_defaultLightLODRange + start;
        }
        g_lightLODFadeEndSq = end * end;
        g_lightLODFadeStartSq = start * start;
    }
}
