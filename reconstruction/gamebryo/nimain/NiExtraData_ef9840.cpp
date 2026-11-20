// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build, with the cited setter.
// Adapted bodies: NiExtraData::SetName follows CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiExtraData.cpp:13 (MIT).
// 0xef9840 NiExtraData::CopyMembers
// 0xef9b00 NiExtraData::dtor
// 0xef9b50 NiExtraData::SetName
#include "NiExtraData_ef9840.h"

// CopyObjectMembers: GUESS(low); calls the object-level copy routine.
void CopyObjectMembers(NiObject& source, NiObject& destination);

void NiExtraData::CopyMembers(NiExtraData* dest)
{
    CopyObjectMembers(*this, *dest);
    dest->name = name;
}

NiExtraData::~NiExtraData()
{

}

void NiExtraData::SetName(const BSFixedString& a_name)
{
    name = a_name;
}
