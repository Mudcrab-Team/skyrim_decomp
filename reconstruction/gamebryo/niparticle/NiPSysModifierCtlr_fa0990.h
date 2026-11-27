// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: Stand-in declarations from the labelled sources and the pinned image layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifierCtlr::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifierCtlr, NiSingleInterpController, NiSingleInterpController::LoadBinary, m_kTargetModifierName: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// NiStream, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// nifMaxVersion, _data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::LoadFixedString: SYMBOLS(tesv-2013-map)
// NiStream::LoadFixedStringLegacy: OBSERVED
// unk00, unk08: GUESS(low)
#pragma once

#include <cstdint>

class BSFixedString
{
    const char* _data;
};

class NiStream
{
public:
    void LoadFixedStringLegacy(BSFixedString& name);
    void LoadFixedString(BSFixedString& name);

    std::uint8_t unk00[0x100];
    std::uint32_t nifMaxVersion;
};

class NiSingleInterpController
{
public:
    virtual void LoadBinary(NiStream& stream);

private:
    std::uint8_t unk08[0x48];
};

class NiPSysModifierCtlr : public NiSingleInterpController
{
public:
    void LoadBinary(NiStream& stream) override;

private:
    BSFixedString m_kTargetModifierName;
};
