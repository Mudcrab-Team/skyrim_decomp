// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf5f840 NiInterpController::ResetTimeExtrema
// 0xf5f860 NiInterpController::GetCtlrID
// NiInterpController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiInterpController::ResetTimeExtrema, NiInterpController::GetCtlrID, NiInterpController::flags, NiInterpController::loKeyTime, NiInterpController::hiKeyTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the flags, loKeyTime and hiKeyTime members are declared by NiTimeController there
// Unk_00 through Unk_34: GUESS(low); placeholder virtual slots that keep ResetTimeExtrema and GetCtlrID at slots 0x35 and 0x36
// unk08, unk12, unk14, unk18: GUESS(low)
#pragma once

#include <cstdint>

class NiInterpController
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void ResetTimeExtrema();  // 35
    virtual const char* GetCtlrID();  // 36

    std::uint64_t unk08;  // 08
    std::uint16_t flags;  // 10
    std::uint16_t unk12;  // 12
    std::uint32_t unk14;  // 14
    std::uint32_t unk18;  // 18
    float         loKeyTime;  // 1C
    float         hiKeyTime;  // 20
};
