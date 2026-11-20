// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysMeshUpdateModifier, LoadBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// SkipLinkIDs, PostLinkBase: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysMeshUpdateModifier : public NiPSysModifier
{
public:
    void SaveBinary(NiStream& stream) override;
    void PostLinkBase(NiStream& stream);
    void LoadBinary(NiStream& stream) override;
};
