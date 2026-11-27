// Source exposure: mixed (pinned-image analysis; community and permitted sibling declarations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectLAND, TESLandTexture, LoadedLandData, loadedData, quadTextures: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectLAND::Function2aad90: GUESS(low); placeholder pending name evidence.
// opaquePrefix: GUESS(low) STANDIN; unaccessed layout ranges before the declared members.
#pragma once
#include <cstddef>
#include <cstdint>

class TESLandTexture;
class TESObjectLAND
{
public:
    struct LoadedLandData
    {
        std::uint8_t opaquePrefix[0x48B0];
        TESLandTexture* quadTextures[4][6];
    };
    std::int32_t Function2aad90(std::uint8_t quadrant) const;
    std::uint8_t opaquePrefix[0x40];
    LoadedLandData* loadedData;
};
static_assert(offsetof(TESObjectLAND, loadedData) == 0x40, "observed layout");
static_assert(offsetof(TESObjectLAND::LoadedLandData, quadTextures) == 0x48B0, "community layout");
