// Source exposure: binary-analysis (pinned image).
// Code origin: partial declaration from pinned RTTI, sized deletion, and the direct calls.
// NiPSysModifierCtlr: STANDIN EXE_RTTI
// LoadBinary: OBSERVED
// LoadBinary occupies the NiObject stream slot.
#pragma once

#include <cstdint>

class NiStream;

class NiPSysModifierCtlr
{
public:
    virtual ~NiPSysModifierCtlr();
    void LoadBinary(NiStream& stream);

private:
    std::uint8_t padding08[0x58];
};
static_assert(sizeof(NiPSysModifierCtlr) == 0x60, "represented controller size");
