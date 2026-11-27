// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadUntil: CRASHLOGGER_PDB(59818@2026.10.24)
// ReadBytes, Unk_01..Unk_10: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class BSFile
{
public:
    virtual ~BSFile();                                          // 00
    virtual void Unk_01();                                      // 01
    virtual void Unk_02();                                      // 02
    virtual void Unk_03();                                      // 03
    virtual void Unk_04();                                      // 04
    virtual void Unk_05();                                      // 05
    virtual void Unk_06();                                      // 06
    virtual void Unk_07();                                      // 07
    virtual void Unk_08();                                      // 08
    virtual void Unk_09();                                      // 09
    virtual void Unk_0A();                                      // 0A
    virtual void Unk_0B();                                      // 0B
    virtual void Unk_0C();                                      // 0C
    virtual void Unk_0D();                                      // 0D
    virtual void Unk_0E();                                      // 0E
    virtual void Unk_0F();                                      // 0F
    virtual void Unk_10();                                      // 10
    virtual std::uint32_t ReadBytes(void* dst, std::uint32_t count);  // 11 (0x88)

    std::uint32_t ReadUntil(char* buffer, std::uint32_t bufferSize, wchar_t delimiter);
};
