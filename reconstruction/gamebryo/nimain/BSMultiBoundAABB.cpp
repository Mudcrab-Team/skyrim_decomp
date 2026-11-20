// Code origin: original reconstruction from the pinned image with community declarations.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xfceab0 BSMultiBoundAABB::SetCenter
// 0xfce8c0 BSMultiBoundAABB::RegisterStreamables
// 0x213ab0 BSMultiBoundAABB::~BSMultiBoundAABB
// 0xfce870 BSMultiBoundAABB::LoadBinary
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfcea20 BSMultiBoundAABB::Ctor
// 0xfceba0 BSMultiBoundAABB::Unk_28
#include "BSMultiBoundAABB.h"

#include <cmath>

// g_initialBoundPoint: GUESS(low)
extern NiPoint3 g_initialBoundPoint;

std::uint32_t BSMultiBoundAABB::Unk_28(const float* sphere)
{
    const NiPoint3 center{sphere[0], sphere[1], sphere[2]};
    const float radius = sphere[3];
    const float x = std::fabs(center.x - unk1C.x);
    const float halfX = unk2C.x;
    const float xInnerDistance = x - (halfX - radius);
    const float xOuterDistance = x - (halfX + radius);
    bool inside = !(xInnerDistance > 0.0f);
    bool overlaps = !(xOuterDistance > 0.0f);

    if (inside || overlaps) {
        const float halfY = unk2C.y;
        const float y = std::fabs(center.y - unk1C.y);
        if (inside) {
            inside &= !(y - (halfY - radius) > 0.0f);
        }
        overlaps &= !(y - (halfY + radius) > 0.0f);
        if (inside || overlaps) {
            const float dz = center.z - unk1C.z;
            const float halfZ = unk2C.z;
            const float z = std::fabs(dz);
            if (inside) {
                inside &= !(z - (halfZ - radius) > 0.0f);
            }
            overlaps &= !(z - (halfZ + radius) > 0.0f);
        }
    }
    return inside ? 2 : overlaps;
}

void BSMultiBoundAABB::SetCenter(const NiPoint3& a_center)
{
    unk1C.x = a_center.x;
    unk1C.y = a_center.y;
    unk1C.z = a_center.z;
}

bool BSMultiBoundAABB::RegisterStreamables(NiStream& a_stream)
{
    return RegisterStreamablesBase(this, a_stream) != 0;
}

BSMultiBoundAABB::BSMultiBoundAABB()
{
    unk1C.x = g_initialBoundPoint.x;
    unk1C.y = g_initialBoundPoint.y;
    unk1C.z = g_initialBoundPoint.z;
    unk2C.x = g_initialBoundPoint.x;
    unk2C.y = g_initialBoundPoint.y;
    unk2C.z = g_initialBoundPoint.z;
}

// Body done: RVA 0x213ab0, 50 bytes, BSMultiBoundAABB::~BSMultiBoundAABB; compared as the scalar
// deleting destructor. The target does the NiRefObject cleanup itself, so keep this empty
// definition and the constructor: the inline base destructors in the header make the compiler
// produce the same body.
BSMultiBoundAABB::~BSMultiBoundAABB()
{
}

// Body done: RVA 0xfce870, 55 bytes, BSMultiBoundAABB::LoadBinary.
void BSMultiBoundAABB::LoadBinary(NiStream& a_stream)
{
    NiObject::LoadBinary(a_stream);
    unk1C.LoadTriple(a_stream);
    unk2C.LoadTriple(a_stream);
}

// Retained generated leaf; its byte-match evidence is renewed with this unit.
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t BSMultiBoundAABB::GetType() const
{
    return 0x1;
}
