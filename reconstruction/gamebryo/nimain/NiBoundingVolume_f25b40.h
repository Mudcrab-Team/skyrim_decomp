// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBoundingVolume: EXE_RTTI
// GetVolumeType, LoadBinary, SaveBinary, Slot01, Slot02, Slot04..Slot09: GUESS(low)
#pragma once

#include "bssystem/NiStream_19e930.h"

class NiBoundingVolume
{
public:
    virtual ~NiBoundingVolume();
    virtual void Slot01();
    virtual void Slot02();
    virtual std::uint32_t GetVolumeType() const;
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual bool Slot09(const NiBoundingVolume& other) const;
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);
};
