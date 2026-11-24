// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSScene, BGSScene::actors, BGSScene::actorFlags, BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSScene::HasActorId: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

template <class T>
class BSTArray
{
public:
    T* data;  // 0x00
    std::uint32_t capacity;  // 0x08
    std::uint32_t pad0C;
    std::uint32_t size;  // 0x10
    std::uint32_t pad14;
};

class BGSScene
{
public:
    bool HasActorId(std::uint32_t actorId);  // compared: 0x3a7520

    std::uint8_t pad00[0x38];
    BSTArray<std::uint32_t> actors;  // 0x38
    BSTArray<std::uint32_t> actorFlags;  // 0x50
};
