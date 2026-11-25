// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiTransformController: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// NiTransformController::IsTargetOfType: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// NiLightDimmerController: GUESS(low); placeholder name
#pragma once

struct NiObjectNET;
struct NiRTTI;


struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pkBase;
};
extern NiRTTI g_011f4428_arg1;
struct NiObjectNET
{
    virtual void Unk0();
    virtual void Unk1();
    virtual NiRTTI* GetRTTI();
};
struct NiTransformController
{
    bool IsTargetOfType(NiObjectNET* pkTarget) const;
};

struct NiLightDimmerController
{
};
