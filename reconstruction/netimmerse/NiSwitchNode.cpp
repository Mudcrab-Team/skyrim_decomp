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
// Code origin: IsEqual and its small accessor helpers retain the earlier project draft.
// StreamRead, StreamBinaryRead: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from
// include/RE/N/NiBinaryStream.h (read) and src/RE/N/NiBinaryStream.cpp (binary_read).
// Other bodies are original reconstructions by v-macrev, assisted by claude-opus-5-5,
// from a local listing of the contributor's own pinned image. Integration repair by
// awarebayes, assisted by gpt-6.1-sol, corrects provenance and defers four update bodies.
// Compared functions:
//   RVA 0xeed530, 82 bytes: NiSwitchNode::IsEqual
//   RVA 0xeee380, 4 bytes: NiSwitchNode::AsSwitchNode
//   RVA 0xeed490, 142 bytes: NiSwitchNode::SaveBinary
//   RVA 0xeed6e0, 143 bytes: NiSwitchNode::AttachChild
//   RVA 0xeed3c0, 160 bytes: NiSwitchNode::LoadBinary
//   RVA 0xeedae0, 161 bytes: NiSwitchNode::SetAt1
//   RVA 0xeee100, 170 bytes: NiSwitchNode::OnVisible
// CI hash: 0xeee380 ?AsSwitchNodeImpl@NiSwitchNode@@QEAAPEAV1@XZ
// CI hash: 0xeed490 ?SaveBinary@NiSwitchNode@@UEAAXAEAVNiStream@@@Z
// CI hash: 0xeed6e0 ?AttachChild@NiSwitchNode@@UEAAXPEAVNiAVObject@@_N@Z
// CI hash: 0xeed3c0 ?LoadBinary@NiSwitchNode@@UEAAXAEAVNiStream@@@Z
// CI hash: 0xeedae0 ?SetAt1@NiSwitchNode@@UEAAXIPEAVNiAVObject@@AEAV?$NiPointer@VNiAVObject@@@@@Z
// CI hash: 0xeee100 ?OnVisible@NiSwitchNode@@UEAAXAEAVNiCullingProcess@@H@Z
// Adapted bodies: StreamRead, StreamBinaryRead (CommonLibSSE-NG, cited above).
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
// CommonLibSSE-NG licence notice:
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
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
	return this;
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
