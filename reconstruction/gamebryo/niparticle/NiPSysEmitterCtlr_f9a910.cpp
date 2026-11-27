// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf9a910 NiPSysEmitterCtlr::IsEqual
// Adapted bodies: none
#include "NiPSysEmitterCtlr_f9a910.h"

bool NiPSysEmitterCtlr::IsEqual(const NiPSysEmitterCtlr* a_other)
{
    if (!NiPSysModifierCtlr::IsEqual(a_other)) {
        return false;
    }
    Interp* otherInterp = a_other->unk60;
    Interp* interp = unk60;
    if (!otherInterp) {
        if (!interp) {
            return true;
        }
        return false;
    }
    if (!interp) {
        return false;
    }
    if (!otherInterp->IsEqual(interp)) {
        return false;
    }
    return true;
}
