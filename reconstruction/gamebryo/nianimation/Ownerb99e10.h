// Source exposure: mixed (local binary analysis and public names).
// Code origin: Stamped as a twin of matched 0xbafba0 (gamebryo/nianimation/BGSGamebryoSequenceGenerator): source copied, names replaced by placeholders.
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Functionbafba0: GUESS(low); storage names invented for the measured member offsets
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionb99e10, Ownerb99e10: GUESS(low) STANDIN
// Unk_18, Functionbaf630, pad, field68, field68Float, field6C, Ownerb99e10::Functionbaf630: GUESS(low) STANDIN
#pragma once
#include "BGSGamebryoSequenceGenerator.h"

class Ownerb99e10
{
public:
    virtual std::uint8_t Unk_18() const;
    void Functionbaf630();
    // Ownerb99e10::Functionbafba0: stores the incoming float at 0x68
    void Functionb99e10(float a_value);

private:
    std::uint64_t pad[0x68 / 8 - 1];  // 08 .. 68
    union {
        float         field68Float;  // 68
        std::uint32_t field68;       // 68
    };
    std::uint8_t field6C;   // 6C
};

