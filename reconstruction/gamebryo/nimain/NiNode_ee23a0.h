// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: Stand-in declarations from the labelled sources and the pinned image layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiNode, NiNode::GetObjectByName, children, _data, _freeIdx: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode::GetObjectByName: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTObjectArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk10, unk14: GUESS(low)
#pragma once

#include <cstdint>
#include "declarations/NiAVObject.h"

template <class T>
class NiTObjectArray
{
public:
    T operator[](std::uint32_t index) const { return _data[index]; }
    std::uint16_t GetFreeIndex() const { return _freeIdx; }

private:
    // GetFreeIndex: GUESS(low); first unused slot in the existing sparse array.
    std::uint8_t unk00[8];
    T* _data;
    std::uint16_t unk10;
    std::uint16_t _freeIdx;
    std::uint32_t unk14;
};

class NiNode : public NiAVObject
{
public:
    NiAVObject* GetObjectByName(const BSFixedString& name) override;

private:
    NiTObjectArray<NiAVObject*> children;
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");
