// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xfd8c50 (gamebryo/nianimation/BSWindModifier_fd8c50): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream: GUESS(low)
// Owner1001910: GUESS(low) STANDIN
// NiPSysModifier, unk30: GUESS(low) STANDIN
#pragma once
#include "BSWindModifier_fd8c50.h"

class Owner1001910 : public NiPSysModifier
{
public:
    virtual void SaveBinary(NiStream& a_stream) override;

    unsigned char pad08[0x30];
    float unk30;
};
