// Exposure detail: (community declarations; permitted sibling game code; pinned-image observations).
// Source exposure: mixed
// Code origin: original partial declarations from named sources and observed layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESRace, TESRace::GetDefaultHeadPart: SIBLING(fo4-private@1b765c70, author-permission)
// BGSHeadPart, BGSHeadPart::HeadPartType, BGSHeadPart::type, TESRace::FaceRelatedData, faceRelatedData, headParts: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HeadPartArray, data, count, prefix, gap08, sex: STANDIN GUESS(low); partial declarations and integer sex index

#pragma once
#include <cstdint>
#include <cstddef>
class BGSHeadPart {
public:
    enum class HeadPartType : std::uint32_t;
    std::uint8_t prefix[0x6c];
    HeadPartType type;
};
struct HeadPartArray {
    BGSHeadPart** data;
    std::uint8_t gap08[8];
    std::uint32_t count;
};
class TESRace {
public:
    struct FaceRelatedData {
        std::uint8_t prefix[0xc0];
        HeadPartArray* headParts;
    };
    BGSHeadPart* GetDefaultHeadPart(std::int32_t sex, BGSHeadPart::HeadPartType type) const;
    std::uint8_t prefix[0x4a8];
    FaceRelatedData* faceRelatedData[2];
};
static_assert(offsetof(TESRace, faceRelatedData) == 0x4a8, "face data offset");
static_assert(offsetof(TESRace::FaceRelatedData, headParts) == 0xc0, "head parts offset");
static_assert(offsetof(BGSHeadPart, type) == 0x6c, "head part type offset");
