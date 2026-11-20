// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSShadowLight: EXE_RTTI
// Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// shadowLightDefault, shadowLightCurrent: GUESS(low); a read-only default at RVA 0x20d9008 copied into a global at RVA 0x34869c0
extern const std::uint32_t shadowLightDefault;
extern std::uint32_t shadowLightCurrent;

class BSShadowLight
{
public:
    static void Function155c650();  // compared: 0x155c650
    virtual std::uint8_t Unk_03() const;
    // Unk_04, Unk_06, Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // return type: GUESS(low); the listing returns a zero byte in AL
    virtual std::uint8_t Unk_04();
    virtual std::uint8_t Unk_06();
    virtual std::uint8_t Unk_08();
};
