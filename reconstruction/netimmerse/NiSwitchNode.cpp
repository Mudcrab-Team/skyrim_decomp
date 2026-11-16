// NiSwitchNode functions for build sse-steam-1-7-104.
//
// Labels: v2
// Task: p46-n-niswitchnode
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Evidence: findings/queue-normal-selection.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Drafted by Claude Haiku 5.5 (claude-haiku-5-5, worker haiku-202611122349-3), starting from
// a tools/skeleton.py skeleton.
// Source exposure: binary-analysis. Drafted by v-macrev, assisted by claude-opus-5-5.
// Code origin: IsEqual and the small accessor helpers above it come from the earlier project draft
// named in the Drafted by line; every other function and helper is an original implementation
// written by v-macrev, assisted by claude-opus-5-5, from a local listing of the contributor's own
// copy of the pinned image. Only names come from the community headers; no community or sibling
// body is adapted.
// Compared functions:
//   RVA 0xeed530, 82 bytes: NiSwitchNode::IsEqual
//   RVA 0xeee380, 4 bytes: NiSwitchNode::AsSwitchNode
//   RVA 0xeee080, 110 bytes: NiSwitchNode::UpdateWorldBound
//   RVA 0xeed490, 142 bytes: NiSwitchNode::SaveBinary
//   RVA 0xeed6e0, 143 bytes: NiSwitchNode::AttachChild
//   RVA 0xeed3c0, 160 bytes: NiSwitchNode::LoadBinary
//   RVA 0xeedae0, 161 bytes: NiSwitchNode::SetAt1
//   RVA 0xeee100, 170 bytes: NiSwitchNode::OnVisible
//   RVA 0xeedf20, 339 bytes: NiSwitchNode::UpdateRigidDownwardPass
//   RVA 0xeedc40, 341 bytes: NiSwitchNode::UpdateDownwardPass
//   RVA 0xeedda0, 363 bytes: NiSwitchNode::UpdateSelectedDownwardPass
// CI hash: 0xeee380 ?AsSwitchNodeImpl@NiSwitchNode@@QEAAPEAV1@XZ
// CI hash: 0xeee080 ?UpdateWorldBound@NiSwitchNode@@UEAAXXZ
// CI hash: 0xeed490 ?SaveBinary@NiSwitchNode@@UEAAXAEAVNiStream@@@Z
// CI hash: 0xeed6e0 ?AttachChild@NiSwitchNode@@UEAAXPEAVNiAVObject@@_N@Z
// CI hash: 0xeed3c0 ?LoadBinary@NiSwitchNode@@UEAAXAEAVNiStream@@@Z
// CI hash: 0xeedae0 ?SetAt1@NiSwitchNode@@UEAAXIPEAVNiAVObject@@AEAV?$NiPointer@VNiAVObject@@@@@Z
// CI hash: 0xeee100 ?OnVisible@NiSwitchNode@@UEAAXAEAVNiCullingProcess@@H@Z
// CI hash: 0xeedf20?UpdateRigidDownwardPass@NiSwitchNode@@UEAAXAEAVNiUpdateData@@I@Z
// CI hash: 0xeedc40 ?UpdateDownwardPass@NiSwitchNode@@UEAAXAEAVNiUpdateData@@I@Z
// CI hash: 0xeedda0 ?UpdateSelectedDownwardPass@NiSwitchNode@@UEAAXAEAVNiUpdateData@@I@Z
// Adapted bodies: none
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
#include "NiSwitchNode.h"

// Update-data record accessors: the first word is the time, the second word holds the flags.
static inline std::uint32_t& UpdateWord0(NiUpdateData& a_data)
{
	return *reinterpret_cast<std::uint32_t*>(&a_data);
}

static inline std::uint32_t& UpdateWord1(NiUpdateData& a_data)
{
	return *(reinterpret_cast<std::uint32_t*>(&a_data) + 1);
}

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

// The flags word is a bitfield struct in the shared header; the compared code tests it as one dword.
static inline std::uint32_t FlagsWordOf(const NiAVObject* a_object)
{
	return *reinterpret_cast<const std::uint32_t*>(&a_object->flags);
}

// Copies a child's bound in the order the image does: centre x, then the radius, then centre y and z,
// with the radius stored last. Centre words move as dwords.
// AssignPoint, SetCenterAndRadius: GUESS(low); member-wise point assignment and a bound setter that
// takes the radius by value, which is how the copy reaches the stores: the radius is loaded first
// and stored after the centre.
static inline void AssignPoint(NiPoint3& a_dst, const NiPoint3& a_src)
{
	a_dst.x = a_src.x;
	a_dst.y = a_src.y;
	a_dst.z = a_src.z;
}

static inline void SetCenterAndRadius(NiBound& a_bound, const NiPoint3& a_center, float a_radius)
{
	AssignPoint(a_bound.center, a_center);
	a_bound.radius = a_radius;
}

static inline void CopyBoundFromChild(NiBound& a_dst, const NiBound& a_src)
{
	SetCenterAndRadius(a_dst, a_src.center, a_src.radius);
}

// Bit 0 of the update flags, read as a byte as the image does.
static inline std::uint8_t UpdateByte1Bit0(NiUpdateData& a_data)
{
	return static_cast<std::uint8_t>(*(reinterpret_cast<std::uint8_t*>(&a_data) + 4) & 1);
}

// Child list head and link: the list head is at +0x18 of the node and the link at +0x40 of a child.
static inline NiChildSlots* ChildListHead(NiSwitchNode* a_self)
{
	return *reinterpret_cast<NiChildSlots**>(reinterpret_cast<std::uint8_t*>(a_self) + 0x18);
}

static inline NiChildSlots* ChildListNext(NiChildSlots* a_child)
{
	return *reinterpret_cast<NiChildSlots**>(reinterpret_cast<std::uint8_t*>(a_child) + 0x40);
}

// RVA 0xeed530, 82 bytes.
bool NiSwitchNode::IsEqual(NiObject* a_object)
{
	if (!NiNodeIsEqual(this, a_object)) {
		return false;
	}
	NiSwitchNode* other = static_cast<NiSwitchNode*>(a_object);
	if (activeIndex != other->activeIndex) {
		return false;
	}
	if (((static_cast<std::uint8_t>(other->flags128) ^ static_cast<std::uint8_t>(flags128)) & 1) != 0) {
		return false;
	}
	return true;
}

// GetFlagBit: GUESS(low); a mask test of a 16-bit flag word, with the word and the mask both 16-bit
static inline bool GetFlagBit(std::uint16_t a_flags, std::uint16_t a_mask)
{
	return (a_flags & a_mask) != 0;
}

// UpdateControllerList: GUESS(low); walks the controller list at +0x18 and updates each controller
// through its slot 0x27 with the update data.
static inline void UpdateControllerList(NiSwitchNode* a_self, NiUpdateData& a_data)
{
	for (NiChildSlots* controller = ChildListHead(a_self); controller; controller = ChildListNext(controller)) {
		controller->Slot27(a_data);
	}
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

// StreamBinaryRead, StreamRead: GUESS(low); the read path mirrored from the shared header's write
// path (binary_write, write): one raw read of a member through the input stream's read pointer.
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
	return this;
}

// RVA 0xeed3c0, 160 bytes.
void NiSwitchNode::LoadBinary(NiStream& a_stream)
{
	NiNodeLoadBinary(this, a_stream);
	StreamRead(a_stream.iStr, &flags128, 1);
	StreamRead(a_stream.iStr, &activeIndex, 1);
	flags128 |= 2;
}

// RVA 0xeed490, 142 bytes.
void NiSwitchNode::SaveBinary(NiStream& a_stream)
{
	NiNodeSaveBinary(this, a_stream);
	a_stream.oStr->write(&flags128, 1);
	a_stream.oStr->write(&activeIndex, 1);
}

// RVA 0xeed6e0, 143 bytes.
void NiSwitchNode::AttachChild(NiAVObject* a_child, bool a_firstAvail)
{
	NiNodeAttachChild(this, a_child, a_firstAvail);
	counter134 = 1;
	SwitchTableAddZero(flagsArr);
}

// RVA 0xeedae0, 161 bytes.
void NiSwitchNode::SetAt1(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut)
{
	counter134 = 1;
	SwitchTableClearAtGrow(flagsArr, a_idx);
	NiNodeSetAt1(this, a_idx, a_child, a_childOut);
}

// RVA 0xeedc40, 341 bytes.
void NiSwitchNode::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	flags128 = UpdateByte1Bit0(a_data) ? static_cast<std::uint16_t>(flags128 | 2) : static_cast<std::uint16_t>(flags128 & 0xFFFD);
	time130 = UpdateWord0(a_data);
	if (flags128 & 1) {
		++counter134;
		if (UpdateByte1Bit0(a_data)) {
			UpdateControllerList(this, a_data);
		}
		UpdateWorldData(&a_data);
		std::int32_t idx = activeIndex;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				child->UpdateDownwardPass(a_data, a_arg2);
				SwitchTableSet(&flagsArr, activeIndex, &counter134);
				CopyBoundFromChild(worldBound, child->worldBound);
			}
		}
	} else {
		NiNodeUpdateDownwardPass(this, a_data, a_arg2);
	}
}

// RVA 0xeedda0, 363 bytes.
void NiSwitchNode::UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	time130 = UpdateWord0(a_data);
	if (flags128 & 1) {
		++counter134;
		std::uint8_t updateControllers = UpdateByte1Bit0(a_data);
		std::uint32_t word = UpdateWord1(a_data);
		UpdateWord1(a_data) = TestBit(FlagsWordOf(this), 3) ? (word | 1) : (word & ~1u);
		if (UpdateWord1(a_data) & 1) {
			UpdateControllerList(this, a_data);
		}
		word = UpdateWord1(a_data);
		UpdateWord1(a_data) = updateControllers ? (word | 1) : (word & ~1u);
		UpdateWorldData(&a_data);
		std::int32_t idx = activeIndex;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				std::uint32_t childFlags = FlagsWordOf(child);
				if (TestBit(childFlags, 1)) {
					NiChildSlots* slots = reinterpret_cast<NiChildSlots*>(child);
					if (TestBit(childFlags, 4)) {
						slots->UpdateRigidDownwardPass(a_data, a_arg2);
					} else {
						slots->UpdateSelectedDownwardPass(a_data, a_arg2);
					}
				}
				SwitchTableSet(&flagsArr, activeIndex, &counter134);
				CopyBoundFromChild(worldBound, child->worldBound);
			}
		}
	} else {
		NiNodeUpdateSelectedDownwardPass(this, a_data, a_arg2);
	}
}

// RVA 0xeedf20, 339 bytes.
void NiSwitchNode::UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	time130 = UpdateWord0(a_data);
	if (flags128 & 1) {
		++counter134;
		std::uint8_t updateControllers = UpdateByte1Bit0(a_data);
		std::uint32_t word = UpdateWord1(a_data);
		UpdateWord1(a_data) = TestBit(FlagsWordOf(this), 3) ? (word | 1) : (word & ~1u);
		if (UpdateWord1(a_data) & 1) {
			UpdateControllerList(this, a_data);
		}
		word = UpdateWord1(a_data);
		UpdateWord1(a_data) = updateControllers ? (word | 1) : (word & ~1u);
		UpdateWorldData(&a_data);
		std::int32_t idx = activeIndex;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				if (TestBit(FlagsWordOf(child), 1)) {
					reinterpret_cast<NiChildSlots*>(child)->UpdateRigidDownwardPass(a_data, a_arg2);
				}
				SwitchTableSet(&flagsArr, activeIndex, &counter134);
				CopyBoundFromChild(worldBound, child->worldBound);
			}
		}
	} else {
		NiNodeUpdateRigidDownwardPass(this, a_data, a_arg2);
	}
}

// RVA 0xeee100, 170 bytes.
void NiSwitchNode::OnVisible(NiCullingProcess& a_process, std::int32_t)
{
	std::int32_t idx = activeIndex;
	if (idx >= 0) {
		NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
		if (child) {
			if (flagsArr._data[static_cast<std::uint32_t>(idx)] != static_cast<std::uint32_t>(counter134)) {
				SwitchTableSet(&flagsArr, idx, &counter134);
				SwitchUpdateInfo info;
				info.time = *reinterpret_cast<float*>(&time130);
				info.flag = GetFlagBit(flags128, 2);
				child->UpdateDownwardPass(*reinterpret_cast<NiUpdateData*>(&info), 0);
			}
			child->Cull(&a_process, -1);
		}
	}
}

// RVA 0xeee080, 110 bytes.
void NiSwitchNode::UpdateWorldBound()
{
	if (flags128 & 1) {
		std::int32_t idx = activeIndex;
		if (idx >= 0) {
			NiAVObject* child = children._data[static_cast<std::uint32_t>(idx)];
			if (child) {
				CopyBoundFromChild(worldBound, child->worldBound);
				return;
			}
		}
		worldBound.radius = 0.0f;
	} else {
		NiNodeUpdateWorldBound(this);
	}
}









