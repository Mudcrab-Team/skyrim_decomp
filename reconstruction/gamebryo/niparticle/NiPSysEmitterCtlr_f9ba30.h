// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: Stand-in declarations from the labelled sources and the pinned image layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysEmitterCtlr::ProcessClone: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysEmitterCtlr, NiPSysModifierCtlr, NiPSysModifierCtlr::ProcessClone, m_spVisibilityInterpolator: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// NiInterpolator, NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiInterpolator::ProcessClone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk01 to unk1C, unk08: GUESS(low)
#pragma once

#include <cstdint>

class NiCloningProcess;

class NiInterpolator
{
public:
    virtual ~NiInterpolator();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
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
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void ProcessClone(NiCloningProcess& process);
};

class NiPSysModifierCtlr
{
public:
    virtual void ProcessClone(NiCloningProcess& process);

private:
    std::uint8_t unk08[0x58];
};

class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
public:
    void ProcessClone(NiCloningProcess& process) override;

private:
    NiInterpolator* m_spVisibilityInterpolator;
};
