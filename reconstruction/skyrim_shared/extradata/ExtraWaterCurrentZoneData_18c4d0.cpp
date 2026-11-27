// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original component comparisons from the assigned local pack; community declarations only.
// ExtraWaterCurrentZoneData, BSExtraData, IsNotEqual, angularVelocity, linearVelocity, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Cookbook: 42, 48
// 0x18c4d0 ExtraWaterCurrentZoneData::IsNotEqual
#include "ExtraWaterCurrentZoneData_18c4d0.h"

bool ExtraWaterCurrentZoneData::IsNotEqual(const BSExtraData* rhs) const
{
    const auto* other = reinterpret_cast<const ExtraWaterCurrentZoneData*>(rhs);
    if (!(angularVelocity.x != other->angularVelocity.x ||
        angularVelocity.y != other->angularVelocity.y ||
        angularVelocity.z != other->angularVelocity.z ||
        linearVelocity.x != other->linearVelocity.x ||
        linearVelocity.y != other->linearVelocity.y ||
        linearVelocity.z != other->linearVelocity.z)) {
        return false;
    }
    return true;
}
