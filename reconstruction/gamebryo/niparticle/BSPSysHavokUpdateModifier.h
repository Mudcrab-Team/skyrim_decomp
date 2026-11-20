// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysHavokUpdateModifier, LoadBinary, SaveBinary, PostLinkObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// linkedModifier: GUESS(low)
#pragma once

#include <cstdint>

#include "NiPSysMeshUpdateModifier.h"

class BSPSysHavokUpdateModifier : public NiPSysMeshUpdateModifier
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    void PostLinkObject(NiStream& stream);

private:
    std::uint8_t padding30[0x20];
    NiPSysModifier* linkedModifier;
};
