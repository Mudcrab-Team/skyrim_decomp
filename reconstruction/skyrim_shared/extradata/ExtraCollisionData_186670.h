// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCollisionData: EXE_RTTI
// CollisionData, id: GUESS(low)
// collisionData, IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
struct CollisionData { std::uint32_t id; };
class ExtraCollisionData {
public:
    bool IsNotEqual(const ExtraCollisionData* other) const;
    std::uint64_t unk00;
    std::uint64_t unk08;
    CollisionData* collisionData;
};
