// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream::Load1, NiStream::Load2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream, NiBinaryStream::IsValid, NiStream::binaryStream: GUESS(low)
// NiStream::Load1: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

// Stand-in for the stream source object; only the one virtual slot used is declared.
class NiBinaryStream
{
public:
    virtual void unk00();
    virtual bool IsValid();
};

class NiStream
{
public:
    virtual void unk00();
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
    virtual bool Load2();

    bool Load1(NiBinaryStream* source);

    std::uint8_t pad08[0x290];  // 0x08
    NiBinaryStream* binaryStream;  // 0x298
};
