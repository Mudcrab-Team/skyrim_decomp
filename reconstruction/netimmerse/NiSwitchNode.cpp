// Source exposure: mixed (community declarations; the listing of the contributor's own pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: IsEqual and its small accessor helpers retain the earlier project draft; the other bodies are original reconstructions by v-macrev, assisted by claude-opus-5-5, from a local listing of the contributor's own pinned image. The bound copy calls SetCenterAndRadius as named and called in the FNV decompilation (label at the helper); no sibling body is copied.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// StreamRead, StreamBinaryRead: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/N/NiBinaryStream.h (read) and src/RE/N/NiBinaryStream.cpp (binary_read).
// Adapted bodies: StreamRead, StreamBinaryRead (CommonLibSSE-NG, MIT; its notice is the SPDX line above, full text in licenses/CommonLibSSE-NG.txt).
// 0xeed530 NiSwitchNode::IsEqual
// 0xeee380 NiSwitchNode::AsSwitchNode
// CI hash: 0xeee380 ?AsSwitchNodeImpl@NiSwitchNode@@QEAAPEAV1@XZ
// 0xeed490 NiSwitchNode::SaveBinary
// 0xeed6e0 NiSwitchNode::AttachChild
// 0xeed3c0 NiSwitchNode::LoadBinary
// 0xeedae0 NiSwitchNode::SetAt1
// 0xeee100 NiSwitchNode::OnVisible
// 0xeee080 NiSwitchNode::UpdateWorldBound
// 0xeedf20 NiSwitchNode::UpdateRigidDownwardPass
// 0xeedc40 NiSwitchNode::UpdateDownwardPass
// 0xeedda0 NiSwitchNode::UpdateSelectedDownwardPass
#include "NiSwitchNode.h"

// The shared header leaves the read pointer as void*; this view reads the same offset typed.
struct NiBinaryStreamReadSlot
{
	std::uint8_t pad[0x10];
	std::uint32_t (*readFn)(NiBinaryStream* a_this, void* a_buffer, std::uint32_t a_bytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents);
};

static inline NiBinaryStreamReadSlot* ReadSlot(NiBinaryStream* a_stream)
{
	return reinterpret_cast<NiBinaryStreamReadSlot*>(a_stream);
}

// RVA 0xeed530, 82 bytes.
bool NiSwitchNode::IsEqual(NiObject* a_object)
{
	if (!NiNodeIsEqual(this, a_object)) {
		return false;
	}
	NiSwitchNode* other = static_cast<NiSwitchNode*>(a_object);
	if (index != other->index) {
		return false;
	}
	if (((static_cast<std::uint8_t>(other->flags) ^ static_cast<std::uint8_t>(flags)) & 1) != 0) {
		return false;
	}
	return true;
}

// GetFlagBit: GUESS(low); a mask test of a 16-bit flag word, with the word and the mask both 16-bit
static inline bool GetFlagBit(std::uint16_t a_flags, std::uint16_t a_mask)
{
	return (a_flags & a_mask) != 0;
}

// SwitchTableClearAtGrow: GUESS(low); the switch table's set-at-grow with a zero element, as the
// image expands it in place: grow when the index reaches the capacity, then store the element.
static inline void SwitchTableClearAtGrow(NiTArray<std::uint32_t>& a_table, std::uint32_t a_idx)
{
	if (a_idx >= a_table._capacity) {
		SwitchTableGrow(&a_table, a_table._growthSize + a_idx);
	}
	if (a_idx >= a_table._freeIdx) {
		a_table._freeIdx = static_cast<std::uint16_t>(a_idx + 1);
	} else if (a_table._data[a_idx] != 0) {
		--a_table._size;
	}
	a_table._data[a_idx] = 0;
}

// SwitchTableAddZero: GUESS(low); appends a zero element at the free index, the same set-at-grow
// expanded in place in AttachChild.
static inline void SwitchTableAddZero(NiTArray<std::uint32_t>& a_table)
{
	std::uint32_t a_idx = a_table._freeIdx;
	if (a_idx >= a_table._capacity) {
		SwitchTableGrow(&a_table, a_table._growthSize + a_idx);
	}
	if (a_idx >= a_table._freeIdx) {
		a_table._freeIdx = static_cast<std::uint16_t>(a_idx + 1);
	} else if (a_table._data[a_idx] != 0) {
		--a_table._size;
	}
	a_table._data[a_idx] = 0;
}

// StreamBinaryRead, StreamRead: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted binary_read/read bodies.
static inline std::uint32_t StreamBinaryRead(NiBinaryStream* a_in, void* a_buffer, std::uint32_t a_totalBytes, std::uint32_t* a_componentSizes, std::uint32_t a_numComponents = 1)
{
	std::uint32_t bytesRead = ReadSlot(a_in)->readFn(a_in, a_buffer, a_totalBytes, a_componentSizes, a_numComponents);
	a_in->_absoluteCurrentPos += bytesRead;
	return bytesRead;
}

template <class T>
static inline bool StreamRead(NiBinaryStream* a_in, T* a_value, std::uint32_t a_count)
{
	std::uint32_t size = sizeof(T);
	std::uint32_t toRead = a_count * size;
	std::uint32_t bytesRead = StreamBinaryRead(a_in, a_value, toRead, &size);
	return bytesRead == toRead;
}

// RVA 0xeee380, 4 bytes.
NiSwitchNode* NiSwitchNode::AsSwitchNodeImpl()
{
	return static_cast<NiSwitchNode*>(this);
}

// RVA 0xeed3c0, 160 bytes.
void NiSwitchNode::LoadBinary(NiStream& a_stream)
{
	NiNodeLoadBinary(this, a_stream);
	StreamRead(a_stream.iStr, &flags, 1);
	StreamRead(a_stream.iStr, &index, 1);
	flags |= 2;
}

// RVA 0xeed490, 142 bytes.
void NiSwitchNode::SaveBinary(NiStream& a_stream)
{
	NiNodeSaveBinary(this, a_stream);
	a_stream.oStr->write(&flags, 1);
	a_stream.oStr->write(&index, 1);
}

// RVA 0xeed6e0, 143 bytes.
void NiSwitchNode::AttachChild(NiAVObject* a_child, bool a_firstAvail)
{
	NiNodeAttachChild(this, a_child, a_firstAvail);
	revID = 1;
	SwitchTableAddZero(childRevID);
}

// RVA 0xeedae0, 161 bytes.
void NiSwitchNode::SetAt1(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut)
{
	revID = 1;
	SwitchTableClearAtGrow(childRevID, a_idx);
	NiNodeSetAt1(this, a_idx, a_child, a_childOut);
}

// RVA 0xeee100, 170 bytes.
void NiSwitchNode::OnVisible(NiCullingProcess& a_process, std::int32_t)
{
	std::int32_t idx = index;
	if (idx >= 0) {
		NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
		if (child) {
			if (childRevID._data[static_cast<std::uint32_t>(idx)] != revID) {
				SwitchTableSet(&childRevID, idx, &revID);
				NiUpdateData data;
				data.time = savedTime;
				data.flags = GetFlagBit(flags, 2);
				child->UpdateDownwardPass(data, 0);
			}
			child->Cull(&a_process, -1);
		}
	}
}

// AssignPoint: GUESS(low); NiPoint3 assignment, component by component, as the NiPoint3 stand-in in
// NiAVObject.h defines its operator=; the NiPoint3 stand-in in NiNode.h declares no operator.
static inline void AssignPoint(NiPoint3& a_dst, const NiPoint3& a_src)
{
	a_dst.x = a_src.x;
	a_dst.y = a_src.y;
	a_dst.z = a_src.z;
}

// SetCenterAndRadius: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); the engine's NiBound
// setter (centre, then radius), written as a free function because the NiBound stand-in in
// NiNode.h declares no members.
static inline void SetCenterAndRadius(NiBound& a_bound, const NiPoint3& a_center, float a_radius)
{
	AssignPoint(a_bound.center, a_center);
	a_bound.radius = a_radius;
}

// UpdateControllerList: GUESS(low); runs each controller of this node's list on the update data.
static inline void UpdateControllerList(NiSwitchNode* a_node, NiUpdateData& a_data)
{
	for (NiTimeController* controller = a_node->controllers; controller; controller = controller->next) {
		controller->Update(a_data);
	}
}

// RVA 0xeee080, 110 bytes.
void NiSwitchNode::UpdateWorldBound()
{
	if (flags & 1) {
		std::int32_t idx = index;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				SetCenterAndRadius(worldBound, child->worldBound.center, child->worldBound.radius);
				return;
			}
		}
		worldBound.radius = 0.0f;
	} else {
		NiNode::UpdateWorldBound();
	}
}

// RVA 0xeedc40, 341 bytes.
void NiSwitchNode::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	if (static_cast<std::uint8_t>(a_data.flags) & 1) {
		flags |= 2;
	} else {
		flags &= ~2;
	}
	savedTime = a_data.time;
	if (flags & 1) {
		++revID;
		if (static_cast<std::uint8_t>(a_data.flags) & 1) {
			UpdateControllerList(this, a_data);
		}
		UpdateWorldData(&a_data);
		std::int32_t idx = index;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				child->UpdateDownwardPass(a_data, a_arg2);
				SwitchTableSet(&childRevID, index, &revID);
				SetCenterAndRadius(worldBound, child->worldBound.center, child->worldBound.radius);
			}
		}
	} else {
		NiNode::UpdateDownwardPass(a_data, a_arg2);
	}
}

// RVA 0xeedda0, 363 bytes.
void NiSwitchNode::UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	savedTime = a_data.time;
	if (flags & 1) {
		++revID;
		bool dirty = (static_cast<std::uint8_t>(a_data.flags) & 1) != 0;
		if (TestBit(FlagWord(), 3)) {
			a_data.flags |= 1;
		} else {
			a_data.flags &= ~1u;
		}
		if (a_data.flags & 1) {
			UpdateControllerList(this, a_data);
		}
		if (dirty) {
			a_data.flags |= 1;
		} else {
			a_data.flags &= ~1u;
		}
		UpdateWorldData(&a_data);
		std::int32_t idx = index;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				std::uint32_t childFlags = child->FlagWord();
				if (TestBit(childFlags, 1)) {
					NiChildSlots* slots = reinterpret_cast<NiChildSlots*>(child);
					if (TestBit(childFlags, 4)) {
						slots->UpdateRigidDownwardPass(a_data, a_arg2);
					} else {
						slots->UpdateSelectedDownwardPass(a_data, a_arg2);
					}
				}
				SwitchTableSet(&childRevID, index, &revID);
				SetCenterAndRadius(worldBound, child->worldBound.center, child->worldBound.radius);
			}
		}
	} else {
		NiNodeUpdateSelectedDownwardPass(this, a_data, a_arg2);
	}
}

// RVA 0xeedf20, 339 bytes.
void NiSwitchNode::UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	savedTime = a_data.time;
	if (flags & 1) {
		++revID;
		bool dirty = (static_cast<std::uint8_t>(a_data.flags) & 1) != 0;
		if (TestBit(FlagWord(), 3)) {
			a_data.flags |= 1;
		} else {
			a_data.flags &= ~1u;
		}
		if (a_data.flags & 1) {
			UpdateControllerList(this, a_data);
		}
		if (dirty) {
			a_data.flags |= 1;
		} else {
			a_data.flags &= ~1u;
		}
		UpdateWorldData(&a_data);
		std::int32_t idx = index;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				if (TestBit(child->FlagWord(), 1)) {
					reinterpret_cast<NiChildSlots*>(child)->UpdateRigidDownwardPass(a_data, a_arg2);
				}
				SwitchTableSet(&childRevID, index, &revID);
				SetCenterAndRadius(worldBound, child->worldBound.center, child->worldBound.radius);
			}
		}
	} else {
		NiNodeUpdateRigidDownwardPass(this, a_data, a_arg2);
	}
}
