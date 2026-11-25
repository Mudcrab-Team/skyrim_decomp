// Source exposure: mixed (community declarations, symbol layouts, pinned-image observations).
// Code origin: original; body and bounded accessor reconstructed from local target observations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiMorphData, NiMorphData::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// NiMorphData layout, MorphTarget, m_uiNumTargets, m_uiNumVertsPerTarget, m_aMorphTargets, m_bRelativeTargets, m_aTargetVerts, m_kName, m_fLegacyWeight, m_spLegacyInterpolator: SYMBOLS(fo4-pdb)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::RegisterFixedString, BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3, NiInterpolator: STANDIN SYMBOLS(fo4-pdb)
// NiMorphData::GetTarget: SYMBOLS(fo4-pdb); bounded accessor body reconstructed from local observations
#pragma once
#include "declarations/NiObject.h"
#include <cstddef>
#include <cstdint>
class NiBinaryStream;
class NiPoint3;
class NiInterpolator;
struct BSFixedString { const char* data; };
class NiStream
{
public:
    virtual ~NiStream();
    virtual bool Load1(NiBinaryStream* stream);
    virtual bool Load2(char* buffer, std::uint64_t length);
    virtual bool Load3(const char* path);
    virtual bool Save1(NiBinaryStream* stream);
    virtual bool Save2(char*& path, std::uint64_t& length);
    virtual bool Save3(const char* path);
    virtual void Unk_07();
    virtual bool RegisterFixedString(const BSFixedString& name);
};
class NiMorphData : public NiObject
{
public:
    struct MorphTarget
    {
        NiPoint3* m_aTargetVerts;
        BSFixedString m_kName;
        float m_fLegacyWeight;
        NiInterpolator* m_spLegacyInterpolator;
    };
    bool RegisterStreamables(NiStream& stream) override;
    MorphTarget* GetTarget(std::uint32_t index)
    {
        return index < m_uiNumTargets ? &m_aMorphTargets[index] : nullptr;
    }
    std::uint32_t m_uiNumTargets;
    std::uint32_t m_uiNumVertsPerTarget;
    MorphTarget* m_aMorphTargets;
    bool m_bRelativeTargets;
};
static_assert(sizeof(NiMorphData::MorphTarget) == 0x20, "morph target stride");
static_assert(offsetof(NiMorphData::MorphTarget, m_kName) == 8, "target name offset");
static_assert(offsetof(NiMorphData, m_aMorphTargets) == 0x18, "target array offset");
