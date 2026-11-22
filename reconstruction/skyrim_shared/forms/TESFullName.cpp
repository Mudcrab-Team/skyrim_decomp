// Source exposure: mixed. Drafted from the local instruction listing of the pinned image.
// Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled otherwise.
// Code origin: original; the listing, community declarations and CrashLogger PDB names only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x146720 TESFullName::GetFullName
// 0x190b10 MapMarkerData::SetVisible
// 0x190b50 MapMarkerData::SetCanTravelTo
// MapMarkerData::SetVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MapMarkerData: CRASHLOGGER_PDB(59818@2026.10.24)
// MapMarkerData::SetCanTravelTo: GUESS(low)
#include "TESFullName.h"

void TESFullName::ClearDataComponent()
{
}

std::uint32_t TESFullName::GetFullNameLength() const
{
    return BSFixedStringLength(&fullName);
}

const char* TESFullName::GetFullName() const
{
    return fullName.data();
}

void MapMarkerData::SetVisible(bool a_value)
{
    flags = a_value ? (flags | kVisible) : (flags & ~kVisible);
}

void MapMarkerData::SetCanTravelTo(bool a_value)
{
    flags = a_value ? (flags | kCanTravelTo) : (flags & ~kCanTravelTo);
}
