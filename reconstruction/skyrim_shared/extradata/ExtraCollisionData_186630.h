// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraCollisionData: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// BSExtraData, ExtraCollisionData, CollisionData, collisionData, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FreeCollision: GUESS(low)
class BSExtraData { public: virtual ~BSExtraData() {} virtual std::uint32_t GetType() const = 0; virtual bool IsNotEqual(const BSExtraData*) const; BSExtraData* next; };
struct CollisionData { std::uint32_t layer; };
void FreeCollision(CollisionData*, std::uint64_t) noexcept;
class ExtraCollisionData : public BSExtraData {
public:
 ~ExtraCollisionData() override;
 std::uint32_t GetType() const override;
 bool IsNotEqual(const BSExtraData*) const override;
 CollisionData* collisionData;
};
