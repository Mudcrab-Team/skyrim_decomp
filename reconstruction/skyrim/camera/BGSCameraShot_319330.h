// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// BGSCameraShot, BGSCameraShot::IsValid: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// modelPath, cameraAction, unk00, unk30, unk5C, unkA0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BSFixedString
{
public:
    std::uint32_t Length() const;

    const char* data;
};
static_assert(sizeof(BSFixedString) == 0x08, "BSFixedString size");

class BGSCameraShot
{
public:
    bool IsValid() const;

    std::uint8_t unk00[0x28];
    BSFixedString modelPath;
    std::uint8_t unk30[0x58 - 0x30];
    std::uint32_t cameraAction;
    std::uint8_t unk5C[0xA0 - 0x5C];
    void* unkA0;
};
static_assert(offsetof(BGSCameraShot, modelPath) == 0x28, "BGSCameraShot::modelPath offset");
static_assert(offsetof(BGSCameraShot, cameraAction) == 0x58, "BGSCameraShot::cameraAction offset");
static_assert(offsetof(BGSCameraShot, unkA0) == 0xA0, "BGSCameraShot::unkA0 offset");
