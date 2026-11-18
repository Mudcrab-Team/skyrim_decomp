// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names from the community header; a byte match does not verify names.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ApplyCollisionLayer, ApplyCollisionLayerAndGroup, FindCollisionObject: GUESS; unnamed callees, see the header
// EnableRigidConstraints, DisableRigidConstraints: GUESS; unnamed callees, see the header
// IsInvalid, FindBone, FindFlattenedBone: GUESS; unnamed callees, see the header
// NiAVObject::GetCollisionObject (non-const): COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares it const, the const overload above is the already compared one
// 0x1053280 NiAVObject::SetCollisionLayer
// 0x10532a0 NiAVObject::SetCollisionLayerAndGroup
// 0x405a50 NiAVObject::GetCollisionObject
// 0x105a360 NiAVObject::UpdateRigidConstraints
// 0xeeac80 NiAVObject::SetName
// 0x1900a0 NiAVObject::GetCollisionObject
// 0xfddac0 NiAVObject::GetBoneFromName
// 0xeec1a0 NiAVObject::RecalculateWorldTransform
#include "NiAVObject.h"

void NiAVObject::SetCollisionLayer(COL_LAYER a_collisionLayer)
{
    const COL_LAYER layer = a_collisionLayer;
    ApplyCollisionLayer(this, layer);
}

void NiAVObject::SetCollisionLayerAndGroup(COL_LAYER a_collisionLayer, std::uint32_t a_group)
{
    const CollisionLayerAndGroup args{ a_collisionLayer, a_group };
    ApplyCollisionLayerAndGroup(this, args);
}

bhkCollisionObject* NiAVObject::GetCollisionObject() const
{
    bhkCollisionObject* result = nullptr;
    FindCollisionObject(this, result);
    return result;
}

void NiAVObject::UpdateRigidConstraints(bool a_enable, std::uint8_t a_arg2, std::uint32_t a_arg3)
{
    if (a_enable) {
        const std::uint8_t arg = static_cast<std::uint8_t>(a_arg3);
        EnableRigidConstraints(this, arg);
    } else {
        const std::uint8_t arg = a_arg2;
        DisableRigidConstraints(this, arg);
    }
}

void NiAVObject::SetName(const BSFixedString& a_name)
{
    name.Copy(a_name);
}

bool NiAVObject::RegisterStreamables(NiStream& a_stream)
{
    if (!NiObjectNET::RegisterStreamables(a_stream)) {
        return false;
    }
    if (collisionObject.pointer) {
        collisionObject.pointer->RegisterStreamables(a_stream);
    }
    return true;
}

// Walks the runtime type chain of an object (the engine's kind-of test, inlined at its use sites).
static bool IsKindOf(const NiObject* a_object, const NiRTTI* a_type)
{
    for (const NiRTTILink* rtti = reinterpret_cast<const NiRTTILink*>(a_object->GetRTTI()); rtti; rtti = rtti->parent) {
        if (rtti == reinterpret_cast<const NiRTTILink*>(a_type)) {
            return true;
        }
    }
    return false;
}

bhkCollisionObject* NiAVObject::GetCollisionObject()
{
    NiCollisionObject* object = collisionObject.pointer;
    if (!object) {
        return nullptr;
    }
    return IsKindOf(object, &NiRTTI_bhkCollisionObject) ? reinterpret_cast<bhkCollisionObject*>(object) : nullptr;
}

NiAVObject* NiAVObject::Clone()
{
    NiCloningProcess cloning;
    NiObject* clone = CreateClone(cloning);
    ProcessClone(cloning);
    return static_cast<NiAVObject*>(clone);
}

NiAVObject* NiAVObject::GetBoneFromName(NiAVObject* a_root, const BSFixedString& a_name, bool a_flag)
{
    NiAVObject* result = nullptr;
    if (a_root) {
        if (a_name.HasValue() != 0) {
            NiExtraData* boneMap = a_root->GetExtraData(kBoneMapName);
            if (boneMap && FindBone(boneMap, a_name, result)) {
                return result;
            }
            if (a_flag) {
                return a_root->GetObjectByName(a_name);
            }
            if (a_root->GetRTTI() == &NiRTTI_BSFlattenedBoneTree) {
                return FindFlattenedBone(a_root, a_name, true);
            }
        }
        return result;
    }
    return nullptr;
}

void NiAVObject::RecalculateWorldTransform()
{
    if (parent) {
        if (TestBit(flags, kFlagBit9)) {
            world = parent->world;
        } else {
            world = parent->world * local;
        }
    } else {
        world = local;
    }
    if (IsInvalid(&previousWorld)) {
        previousWorld = world;
    }
}
