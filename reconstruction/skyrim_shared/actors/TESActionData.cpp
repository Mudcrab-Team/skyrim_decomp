// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: body written from the pinned image listing; names and declarations from community headers
// 0x78db60 TESActionData::Function78db60
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActionData::Unk_02: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// return type std::uint32_t is a guess; the listing returns 0 in EAX
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
#include "TESActionData.h"

// RVA 0x78db50, 3 bytes, TESActionData::Unk_02. Returns 0 in EAX.
std::uint32_t TESActionData::Unk_02()
{
    return 0;
}

std::uint32_t TESActionData::Function78db60()
{
    if (member08 != nullptr) {
        return member08->Slot45();
    }
    return 0;
}
