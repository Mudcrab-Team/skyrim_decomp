// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::GetNumberOfLinkIDs: CRASHLOGGER_PDB(59818@2026.10.24)
// LinkIdList, LinkIdList::unk00, LinkIdList::counts, gLinkIdList_tls_0x9b8, NiStream::unk00, NiStream::linkIdIndex: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct LinkIdList
{
    std::uint64_t unk00;
    std::uint32_t* counts;
};

extern __declspec(thread) LinkIdList* gLinkIdList_tls_0x9b8;

class NiStream
{
public:
    std::uint32_t GetNumberOfLinkIDs();

    std::uint8_t unk00[0x2AC];
    std::uint32_t linkIdIndex;
};
static_assert(offsetof(NiStream, linkIdIndex) == 0x2AC, "linkIdIndex offset");
