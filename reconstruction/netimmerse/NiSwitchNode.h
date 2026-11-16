// NiSwitchNode declarations for build sse-steam-1-7-104.
//
// Labels: v2
// Task: p46-n-niswitchnode
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Started from a tools/skeleton.py skeleton: stand-ins carry only what the compared code needs, and
// community names are unverified.
// Base form: shared header NiNode.h (same folder) for NiNode.
// Code origin: declarations from the skeleton and the community headers named in the labels; the
// AsSwitchNodeImpl and NiUpdateData stand-ins were added by v-macrev, assisted by
// claude-opus-5-5, from a local listing of the contributor's own copy of the pinned image. No
// community or sibling body is adapted.
// NiSwitchNode: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// NiSwitchNode::IsEqual, NiSwitchNode::UpdateWorldBound, NiSwitchNode::SaveBinary, NiSwitchNode::AttachChild, NiSwitchNode::LoadBinary, NiSwitchNode::SetAt1, NiSwitchNode::OnVisible, NiSwitchNode::UpdateRigidDownwardPass, NiSwitchNode::UpdateDownwardPass, NiSwitchNode::UpdateSelectedDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiNode.h"

template <class T> class NiPointer;

// NiUpdateData: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); the shared header only declares it
// time, flags: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); flags is a plain word here, a flag set there
class NiUpdateData
{
public:
	float         time;   // 0
	std::uint32_t flags;  // 4
};
static_assert(sizeof(NiUpdateData) == 0x8, "NiUpdateData size");

// Stand-in helpers for the base-class bodies and the switch table; the image addresses are in
// bind-hints.json.
// NiNodeIsEqual, NiNodeSaveBinary, NiNodeLoadBinary, NiNodeAttachChild: GUESS(low); enclosing NiNode bodies
bool NiNodeIsEqual(NiNode* a_self, NiObject* a_object);
void NiNodeSaveBinary(NiNode* a_self, NiStream& a_stream);
void NiNodeLoadBinary(NiNode* a_self, NiStream& a_stream);
void NiNodeAttachChild(NiNode* a_self, NiAVObject* a_child, bool a_firstAvail);
// NiNodeSetAt1: GUESS(low); enclosing NiNode body
void NiNodeSetAt1(NiNode* a_self, std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut);
// SwitchTableSet, SwitchTableGrow: GUESS(low); out-of-line set-at-grow and resize of the child revision table
void SwitchTableSet(NiTArray<std::uint32_t>* a_table, std::uint32_t a_idx, std::uint32_t* a_value);
void SwitchTableGrow(NiTArray<std::uint32_t>* a_table, std::uint32_t a_size);

class NiSwitchNode : public NiNode
{
public:
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xeed530
    virtual void SaveBinary(NiStream& a_stream);  // compared: 0xeed490
    virtual void AttachChild(NiAVObject* a_child, bool a_firstAvail);  // compared: 0xeed6e0
    virtual void LoadBinary(NiStream& a_stream);  // compared: 0xeed3c0
    virtual void SetAt1(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut);  // compared: 0xeedae0
    virtual void OnVisible(NiCullingProcess& a_process, std::int32_t a_alphaGroupIndex);  // compared: 0xeee100

    // AsSwitchNodeImpl: STANDIN GUESS(low); body of the AsSwitchNode override (slot 4), which the shared
    // base header declares returning void, so the override cannot be written with its real return type
    NiSwitchNode* AsSwitchNodeImpl();  // compared: 0xeee380

    // flags, index, savedTime, revID, childRevID: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
    // childRevID: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); po3 declares NiTPrimitiveArray<std::uint32_t>, the shared header has NiTArray only
    std::uint16_t           flags;       // 128
    std::int32_t            index;       // 12C
    float                   savedTime;   // 130
    std::uint32_t           revID;       // 134
    NiTArray<std::uint32_t> childRevID;  // 138
};
static_assert(sizeof(NiSwitchNode) == 0x150, "NiSwitchNode size");
