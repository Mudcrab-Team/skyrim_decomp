// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSBehaviorGraphExtraData, BSBehaviorGraphExtraData::RegisterStreamables, NiExtraData, NiStream: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, RegisterFixedString, behaviorGraphFile: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct BSFixedString
{
    const char* data;
};

class NiStream
{
public:
    virtual ~NiStream();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void RegisterFixedString(BSFixedString* a_str);
};

class NiExtraData
{
public:
    bool RegisterStreamables(NiStream& a_stream);

    std::uint8_t unk00[0x18];
};

class BSBehaviorGraphExtraData : public NiExtraData
{
public:
    bool RegisterStreamables(NiStream& a_stream);

    BSFixedString behaviorGraphFile;
};

static_assert(offsetof(BSBehaviorGraphExtraData, behaviorGraphFile) == 0x18, "behaviorGraphFile offset");
