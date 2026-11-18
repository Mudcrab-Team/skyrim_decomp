// Code origin: SetCenter and RegisterStreamables bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xfceab0 BSMultiBoundAABB::SetCenter
// 0xfce8c0 BSMultiBoundAABB::RegisterStreamables
// 0x213ab0 BSMultiBoundAABB::~BSMultiBoundAABB
// 0xfce870 BSMultiBoundAABB::LoadBinary
#include "BSMultiBoundAABB.h"

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

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSMultiBoundAABB::BSMultiBoundAABB()
{
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
