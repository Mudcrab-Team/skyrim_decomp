// Source exposure: mixed (community declarations; target observations; sibling-symbol layout).
// Code origin: original declarations; PutBool adapted from CommonLibSSE-NG binary stream helpers
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysAgeDeathModifier, SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// m_bSpawnOnDeath, m_pkSpawnModifier, NiPSysSpawnModifier: SYMBOLS(fo4-pdb)
// NiStream, NiBinaryStream, NiPSysModifier, SaveLinkID, oStr, _absoluteCurrentPos, _writeFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Slot01, Slot02, Slot03, Slot04, Slot05, Slot06, Slot07, Slot08, Slot09, Slot0A, Slot0B, unknown08, unknown0C, readFn, PutBool: GUESS(low)
// Adapted bodies: NiBinaryStream::PutBool, CommonLibSSE-NG@b93280e include/RE/N/NiBinaryStream.h and src/RE/N/NiBinaryStream.cpp, MIT
#pragma once
#include <cstdint>
class NiPSysSpawnModifier;
struct NiBinaryStream
{
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    virtual ~NiBinaryStream();
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t unknown0C;
    void* readFn;
    WriteFn* _writeFn;
    void PutBool(bool value)
    {
        std::uint32_t componentSize = sizeof(value);
        _absoluteCurrentPos += _writeFn(this, &value, sizeof(value), &componentSize, 1);
    }
};
class NiStream
{
public:
    virtual ~NiStream();
    virtual void Slot01(); virtual void Slot02(); virtual void Slot03();
    virtual void Slot04(); virtual void Slot05(); virtual void Slot06();
    virtual void Slot07(); virtual void Slot08(); virtual void Slot09();
    virtual void Slot0A(); virtual void Slot0B();
    virtual void SaveLinkID(const NiPSysSpawnModifier* object);
    std::uint8_t unknown08[0x298];
    NiBinaryStream* oStr;
};
class NiPSysModifier
{
public:
    virtual ~NiPSysModifier();
    void SaveBinary(NiStream& stream);
    std::uint8_t unknown08[0x28];
};
class NiPSysAgeDeathModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream);
    bool m_bSpawnOnDeath;
    NiPSysSpawnModifier* m_pkSpawnModifier;
};
