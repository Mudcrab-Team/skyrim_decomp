// Code origin: names, base, slot order and size adapted from CharmedBaryon/CommonLibSSE-NG (MIT)
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObjectPalette, NiAVObjectPalette::RegisterStreamables, NiAVObjectPalette::~NiAVObjectPalette, NiAVObjectPalette::GetRTTI, NiAVObjectPalette::LoadBinary, NiAVObjectPalette::LinkObject, NiAVObjectPalette::SaveBinary, NiAVObjectPalette::GetAVObject, NiAVObjectPalette::SetAVObject, NiAVObjectPalette::ResetAndFillFromScenegraph: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiAVObject, BSFixedString: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiAVObject;
class BSFixedString;

class NiAVObjectPalette : public NiObject
{
public:
    ~NiAVObjectPalette() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    void LoadBinary( NiStream& a_stream) override;  // 18
    void LinkObject( NiStream& a_stream) override;  // 19
    void SaveBinary( NiStream& a_stream) override;  // 1B
    virtual NiAVObject* GetAVObject(BSFixedString& a_name) = 0;  // 25
    virtual void SetAVObject(BSFixedString& a_name, NiAVObject* a_object) = 0;  // 26
    virtual void ResetAndFillFromScenegraph();  // 27
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A, compared: 0xf0a920
};
static_assert(sizeof(NiAVObjectPalette) == 0x10, "NiAVObjectPalette size");
