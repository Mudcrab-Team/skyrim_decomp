// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWindModifier, BSWindModifier::SaveBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifier, NiStream, StreamWriter, Write: GUESS(low)
// unk2A0, unk30, unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class StreamWriter
{
public:
    unsigned char pad00[0x8];
    uint32_t unk08;
    unsigned char pad0C[0xC];
    uint32_t (*Write)(StreamWriter* a_self, const void* a_data, uint32_t a_size, uint32_t* a_sizes, uint32_t a_count);
};

class NiStream
{
public:
    unsigned char pad000[0x2A0];
    StreamWriter* unk2A0;
};

class NiPSysModifier
{
public:
    virtual ~NiPSysModifier();
    virtual void SaveBinary(NiStream& a_stream);
};

class BSWindModifier : public NiPSysModifier
{
public:
    virtual void SaveBinary(NiStream& a_stream) override;

    unsigned char pad08[0x28];
    float unk30;
};
