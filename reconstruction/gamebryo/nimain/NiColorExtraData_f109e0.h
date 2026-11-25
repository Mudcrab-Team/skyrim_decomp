// Source exposure: mixed (community declarations; pinned image observations; sibling symbol declarations).
// Code origin: original; minimal declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiColorExtraData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiColorExtraData::CopyMembers: GUESS(medium); inferred base-copy and color assignment
// NiExtraData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData::CopyMembers: SYMBOLS(tesv-2013-map)
// NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiColorA, red, green, blue, alpha: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// color: GUESS(low); observed four-component payload
#pragma once
#include <cstdint>
class NiCloningProcess;
struct NiColorA
{
    float red;
    float green;
    float blue;
    float alpha;
};
class NiExtraData
{
public:
    void CopyMembers(NiExtraData* destination, NiCloningProcess& cloning);
    std::uint8_t unknownBase[24];
};
class NiColorExtraData : public NiExtraData
{
public:
    void CopyMembers(NiColorExtraData* destination, NiCloningProcess& cloning);
    NiColorA color;
};
static_assert(sizeof(NiExtraData) == 24, "Observed extra-data base extent");
