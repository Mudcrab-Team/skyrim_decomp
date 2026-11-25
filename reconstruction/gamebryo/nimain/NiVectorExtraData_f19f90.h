// Source exposure: mixed.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiVectorExtraData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData, NiExtraData::CopyMembers, NiCloningProcess: STANDIN SYMBOLS(tesv-2013-map)
// NiVectorExtraData::CopyMembers, values: GUESS(medium)
#pragma once
#include <cstdint>

class NiCloningProcess;
class NiExtraData
{
public:
    void CopyMembers(NiExtraData* destination, NiCloningProcess& process);
    std::uint8_t baseData[0x18];
};
class NiVectorExtraData : public NiExtraData
{
public:
    void CopyMembers(NiVectorExtraData* destination, NiCloningProcess& process);
    std::uint32_t values[4];
};
