// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// BSPSysMultiTargetEmitterCtlr, IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPSysEmitterCtlr, BSMasterParticleSystem, pMasterParticleSystem, usMaxFullEmitters: SYMBOLS(fo4-pdb)
// NiPSysEmitterCtlr: STANDIN SYMBOLS(fo4-pdb); only the observed prefix is represented.
// unknown08: GUESS(low); unrepresented base storage.
#pragma once
#include <cstddef>

class NiObject;
class BSMasterParticleSystem;
class NiPSysEmitterCtlr
{
public:
    virtual bool IsEqual(NiObject* object);
    unsigned char unknown08[0x88];
};

class BSPSysMultiTargetEmitterCtlr : public NiPSysEmitterCtlr
{
public:
    bool IsEqual(NiObject* object) override;
    BSMasterParticleSystem* pMasterParticleSystem;
    unsigned short usMaxFullEmitters;
};
static_assert(offsetof(BSPSysMultiTargetEmitterCtlr, pMasterParticleSystem) == 0x90, "master system offset");
static_assert(offsetof(BSPSysMultiTargetEmitterCtlr, usMaxFullEmitters) == 0x98, "emitter limit offset");
