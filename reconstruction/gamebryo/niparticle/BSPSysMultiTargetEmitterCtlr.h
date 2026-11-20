// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysMultiTargetEmitterCtlr, RegisterStreamables: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// RegisterBaseStreamables: GUESS(low)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiStream;

class BSPSysMultiTargetEmitterCtlr
{
public:
    bool RegisterStreamables(NiStream& stream);

private:
    std::uint8_t RegisterBaseStreamables(NiStream& stream);
};
