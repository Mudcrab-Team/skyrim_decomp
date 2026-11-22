// Source exposure: mixed (pinned image, CommonLibSSE-NG declarations, and FNV sibling comparison).
// Licence: GPL-3.0 because the name Clone comes from powerof3/CommonLibSSE.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original except for the bodies listed below.
// Adapted bodies: IsEqual and RegisterStreamables, CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiObject.cpp (MIT).
// NiObject::RegisterStreamables, NiStream::RegisterSaveObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::RegisterStreamables: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); the pinned sibling has the same forwarding body.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a40000_o2.cpp:3827
// 0xedca00 NiObject::ProcessClone
// 0xedcb60 NiObject::StreamCanSkip
// 0xedcb90 NiObject::GetGroup
// 0xedc740 NiObject::CreateClone
// 0xedcbc0 NiObject::ctor
// 0xedc920 NiObject::Clone
// 0xedc7e0 NiObject::IsEqual
// 0xedc7b0 NiObject::RegisterStreamables
#include "NiObject.h"

#include "NiObjectNET.h"

// Private stand-in used only by this translation unit; the shared header stays opaque.
// NiCloneMap, NiCloneMap::Visit: GUESS(low); names invented, the callee is bound by address through bind-hints.json
// cloneMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name as reported by the label check, not read from NG here
// NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the map at 0x38 is declared
// unknown00: GUESS(low); padding up to the map at 0x38
class NiCloneMap
{
public:
	void Visit(NiObject** a_object, bool* a_flag, bool* a_result);
};

class NiCloningProcess
{
public:
	std::uint8_t unknown00[0x38];  // 00
	NiCloneMap   cloneMap;         // 38
};


#include <cstring>

NiObject::NiObject() {}

bool NiObject::StreamCanSkip() { return false; }

NiObjectGroup* NiObject::GetGroup() const { return nullptr; }

NiObject* NiObject::CreateClone(NiCloningProcess&) { return this; }

// Register this object with the stream's save table.
bool NiObject::RegisterStreamables(NiStream& a_stream)
{
	return a_stream.RegisterSaveObject(this);
}

bool NiObject::IsEqual(NiObject* a_object)
{
	return a_object != nullptr && std::strcmp(GetRTTI()->name, a_object->GetRTTI()->name) == 0;
}

void NiObject::ProcessClone(NiCloningProcess& a_cloning)
{
	NiObject* self = this;
	bool flag = true;
	bool result;
	a_cloning.cloneMap.Visit(&self, &flag, &result);
}

NiObject* NiObject::Clone(NiCloningProcess& a_cloning)
{
	NiObject* clone = CreateClone(a_cloning);
	ProcessClone(a_cloning);
	return clone;
}
