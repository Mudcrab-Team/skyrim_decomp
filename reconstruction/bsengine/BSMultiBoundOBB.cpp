// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfcf830 BSMultiBoundOBB::GetType
// 0xfcf6a0 BSMultiBoundOBB::SaveBinary
// 0x213af0 BSMultiBoundOBB::~BSMultiBoundOBB
// 0xfcf630 BSMultiBoundOBB::LoadBinary
#include "BSMultiBoundOBB.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSMultiBoundOBB::BSMultiBoundOBB()
{
}

// Compared function: RVA 0xfcf830, 6 bytes, BSMultiBoundOBB::GetType.
std::uint32_t BSMultiBoundOBB::GetType()
{
    return 2;
}

// Compared function: RVA 0xfcf6a0, 43 bytes, BSMultiBoundOBB::SaveBinary.
void BSMultiBoundOBB::SaveBinary(NiStream& a_stream)
{
    BSMultiBoundAABB::SaveBinary(a_stream);
    unknown40.SaveBinary(a_stream);
}

// Body done: RVA 0x213af0, 50 bytes, BSMultiBoundOBB::~BSMultiBoundOBB; compared as the scalar
// deleting destructor. The target does the NiRefObject cleanup itself, so keep this empty
// definition and the constructor: the inline base destructors in the header make the compiler
// produce the same body.
BSMultiBoundOBB::~BSMultiBoundOBB()
{
}

// Compared function: RVA 0xfcf630, 55 bytes, BSMultiBoundOBB::LoadBinary.
void BSMultiBoundOBB::LoadBinary(NiStream& a_stream)
{
    BSMultiBoundAABB::LoadBinary(a_stream);
    unknown40.LoadBinary(a_stream);
    unknown64 = ComputeFlag();
}
