// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// 0xff50c0 BSPSysMultiTargetEmitterCtlr::IsEqual
// BSPSysMultiTargetEmitterCtlr, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPSysEmitterCtlr, pMasterParticleSystem, usMaxFullEmitters: SYMBOLS(fo4-pdb)
#include "BSPSysMultiTargetEmitterCtlr_ff50c0.h"

bool BSPSysMultiTargetEmitterCtlr::IsEqual(NiObject* object)
{
    if (!NiPSysEmitterCtlr::IsEqual(object))
        return false;
    auto* other = reinterpret_cast<BSPSysMultiTargetEmitterCtlr*>(object);
    if (pMasterParticleSystem != other->pMasterParticleSystem)
        return false;
    if (usMaxFullEmitters != other->usMaxFullEmitters)
        return false;
    return true;
}
