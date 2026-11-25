// Near miss: 0.0% | other
// NiNode: LoadBinary, LinkObject, RegisterStreamables, SaveBinary, IsEqual, OnVisible; build sse-steam-1-7-104.
//
// Licence: uses some member names from powerof3/CommonLibSSE (see the header), so this file is GPL-3.0.
// RVA 0xee1560, 58 bytes (LoadBinary); RVA 0xee15a0, 168 bytes (LinkObject);
// RVA 0xee1650, 123 bytes (RegisterStreamables); RVA 0xee16e0, 189 bytes (SaveBinary);
// Source exposure: mixed
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// NiNode::LoadBinary, NiNode::LinkObject, NiNode::RegisterStreamables, NiNode::SaveBinary, NiNode::IsEqual, NiNode::OnVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xee24d0 NiNode::UpdateDownwardPass

#include "include/ee24d0/NiNode.h"

void NiNode::LoadBinary(NiStream& a_stream)
{
	NiAVObject::LoadBinary(a_stream);
	a_stream.SkipLinkIDs();
	a_stream.SkipLinkIDs();
	flags.kNoDismemberValidity = 0;
}

void NiNode::LinkObject(NiStream& a_stream)
{
	NiAVObject::LinkObject(a_stream);

	std::uint32_t count = a_stream.ReadLinkIDCount();
	if (count) {
		SetArraySize(children, count);
		for (std::uint32_t i = 0; i < count; ++i) {
			NiAVObject* child = a_stream.ReadLinkID();
			SetAt2(i, child);
			if (child) {
				child->parentIndex = i;
			}
		}
	}

	// the stream carries a second list of links that this build reads and discards
	for (std::uint32_t skipped = a_stream.ReadLinkIDCount(); skipped; --skipped) {
		a_stream.ReadLinkID();
	}
}

bool NiNode::RegisterStreamables(NiStream& a_stream)
{
	if (!NiAVObject::RegisterStreamables(a_stream)) {
		return false;
	}
	for (std::uint32_t i = 0; i < children._freeIdx; ++i) {
		NiAVObject* child = children._data[i];
		if (child) {
			child->RegisterStreamables(a_stream);
		}
	}
	return true;
}

void NiNode::SaveBinary(NiStream& a_stream)
{
	NiAVObject::SaveBinary(a_stream);

	std::uint32_t count = children._freeIdx;
	a_stream.oStr->write(&count, 1);
	for (std::uint32_t i = 0; i < count; ++i) {
		a_stream.SaveLinkID(children._data[i]);
	}

	// trailing list count, always written as zero
	std::uint32_t zero = 0;
	a_stream.oStr->write(&zero, 1);
}

bool NiNode::IsEqual(NiObject* a_object)
{
	if (!NiAVObject::IsEqual(a_object)) {
		return false;
	}
	NiNode*       other = static_cast<NiNode*>(a_object);
	std::uint32_t count = children._freeIdx;
	if (count != other->children._freeIdx) {
		return false;
	}
	for (std::uint32_t i = 0; i < count; ++i) {
		NiAVObject* mine = children._data[i];
		NiAVObject* theirs = other->children._data[i];
		if (mine) {
			if (!theirs || !mine->IsEqual(theirs)) {
				return false;
			}
		} else if (theirs) {
			return false;
		}
	}
	return true;
}

void NiNode::OnVisible(NiCullingProcess& a_process, std::int32_t a_alphaGroupIndex)
{
	// radius is tested as bits so the zero check needs no float compare
	if (worldBound.radiusBits != 0 || TestBit(FlagWord(), kAlwaysDrawBit)) {
		std::uint16_t count = children._freeIdx;
		for (std::uint16_t i = 0; i < count; ++i) {
			NiAVObject* child = children._data[i];
			if (child) {
				child->Cull(&a_process, a_alphaGroupIndex);
			}
		}
	}
}

void NiNode::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	if (a_data.flags & 1) {
		for (NiTimeController* controller = controllers; controller; controller = controller->next) {
			controller->Update(a_data);
		}
	}

	UpdateWorldData(&a_data);

	std::uint32_t childFlags = a_arg2;
	if (TestBit(FlagByte(), 0)) {
		childFlags |= 1;
	}

	const std::uint32_t count = children._freeIdx;
	std::uint32_t       i = 0;
	if (!TestBit(FlagWord(), 13)) {
		worldBound.radiusBits = 0;
		for (; i < count; ++i) {
			NiAVObject* child = children._data[i];
			if (child) {
				child->UpdateDownwardPass(a_data, childFlags);
				if (child->worldBound.radiusBits != 0) {
					const NiBound& childBound = child->worldBound;
					worldBound.SetCenterAndRadius(childBound.center, childBound.radius);
					++i;
					break;
				}
			}
		}
	}
	for (; i < count; ++i) {
		NiAVObject* child = children._data[i];
		if (child) {
			child->UpdateDownwardPass(a_data, childFlags);
			if (!TestBit(FlagWord(), 13) && child->worldBound.radiusBits != 0) {
				worldBound.Merge(&child->worldBound);
			}
		}
	}
}
