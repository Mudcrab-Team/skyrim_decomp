// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiPSysEmitterCtlr, NiPSysEmitterCtlr::IsEqual, NiPSysModifierCtlr, NiPSysModifierCtlr::IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Interp, Interp::IsEqual, unk60: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Interp
{
public:
    virtual ~Interp();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual bool IsEqual(const Interp* a_other);
};

class NiPSysModifierCtlr
{
public:
    bool IsEqual(const NiPSysModifierCtlr* a_other);

    unsigned char pad000[0x60];
    Interp* unk60;
};

class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
public:
    bool IsEqual(const NiPSysEmitterCtlr* a_other);
};
