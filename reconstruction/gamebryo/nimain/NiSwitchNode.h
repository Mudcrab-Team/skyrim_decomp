// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: declarations from the skeleton and the community headers named in the labels; the AsSwitchNodeImpl, NiUpdateData, NiTimeController and NiChildSlots stand-ins were added by v-macrev, assisted by claude-opus-5-5, from a local listing of the contributor's own copy of the pinned image. No community or sibling body is adapted.
// NiSwitchNode: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// NiSwitchNode::IsEqual, NiSwitchNode::UpdateWorldBound, NiSwitchNode::SaveBinary, NiSwitchNode::AttachChild, NiSwitchNode::LoadBinary, NiSwitchNode::SetAt1, NiSwitchNode::OnVisible, NiSwitchNode::UpdateRigidDownwardPass, NiSwitchNode::UpdateDownwardPass, NiSwitchNode::UpdateSelectedDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiNode_ee1560.h"

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

// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slot and the link the update passes use
// unk00 through unk26: GUESS(low); slots the compared code does not call
class NiTimeController
{
public:
	virtual void unk00();
	virtual void unk01();
	virtual void unk02();
	virtual void unk03();
	virtual void unk04();
	virtual void unk05();
	virtual void unk06();
	virtual void unk07();
	virtual void unk08();
	virtual void unk09();
	virtual void unk0A();
	virtual void unk0B();
	virtual void unk0C();
	virtual void unk0D();
	virtual void unk0E();
	virtual void unk0F();
	virtual void unk10();
	virtual void unk11();
	virtual void unk12();
	virtual void unk13();
	virtual void unk14();
	virtual void unk15();
	virtual void unk16();
	virtual void unk17();
	virtual void unk18();
	virtual void unk19();
	virtual void unk1A();
	virtual void unk1B();
	virtual void unk1C();
	virtual void unk1D();
	virtual void unk1E();
	virtual void unk1F();
	virtual void unk20();
	virtual void unk21();
	virtual void unk22();
	virtual void unk23();
	virtual void unk24();
	virtual void unk25();
	virtual void unk26();
	// Update: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; slot 0x27, NG declares Update(float), the image passes the update data by address
	virtual void Update(NiUpdateData& a_data);  // 27

	// pad08: GUESS(low); members not used by the compared code
	std::uint8_t pad08[0x38];  // 08
	// next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiPointer there
	NiTimeController* next;  // 40
};

// NiChildSlots: STANDIN GUESS(low)
// The child slots the selected and rigid passes call with arguments, which the shared header declares
// without them. Slot numbers are the byte offset divided by 8; slots 0x00 to 0x2C are unnamed placeholders.
// unk00 through unk2C: GUESS(low)
class NiChildSlots
{
public:
	virtual void unk00();
	virtual void unk01();
	virtual void unk02();
	virtual void unk03();
	virtual void unk04();
	virtual void unk05();
	virtual void unk06();
	virtual void unk07();
	virtual void unk08();
	virtual void unk09();
	virtual void unk0A();
	virtual void unk0B();
	virtual void unk0C();
	virtual void unk0D();
	virtual void unk0E();
	virtual void unk0F();
	virtual void unk10();
	virtual void unk11();
	virtual void unk12();
	virtual void unk13();
	virtual void unk14();
	virtual void unk15();
	virtual void unk16();
	virtual void unk17();
	virtual void unk18();
	virtual void unk19();
	virtual void unk1A();
	virtual void unk1B();
	virtual void unk1C();
	virtual void unk1D();
	virtual void unk1E();
	virtual void unk1F();
	virtual void unk20();
	virtual void unk21();
	virtual void unk22();
	virtual void unk23();
	virtual void unk24();
	virtual void unk25();
	virtual void unk26();
	virtual void unk27();
	virtual void unk28();
	virtual void unk29();
	virtual void unk2A();
	virtual void unk2B();
	virtual void unk2C();
	// NiAVObject::UpdateSelectedDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); slot 0x2D (offset 0x168)
	virtual void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
	// NiAVObject::UpdateRigidDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); slot 0x2E (offset 0x170)
	virtual void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
};

// Stand-in helpers for the base-class bodies and the switch table; the image addresses are in
// bind-hints.json.
// NiNodeIsEqual, NiNodeSaveBinary, NiNodeLoadBinary, NiNodeAttachChild: GUESS(low); enclosing NiNode bodies
bool NiNodeIsEqual(NiNode* a_self, NiObject* a_object);
void NiNodeSaveBinary(NiNode* a_self, NiStream& a_stream);
void NiNodeLoadBinary(NiNode* a_self, NiStream& a_stream);
void NiNodeAttachChild(NiNode* a_self, NiAVObject* a_child, bool a_firstAvail);
// NiNodeSetAt1: GUESS(low); enclosing NiNode body
void NiNodeSetAt1(NiNode* a_self, std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_childOut);
// NiNodeUpdateSelectedDownwardPass, NiNodeUpdateRigidDownwardPass: GUESS(low); tail-called NiNode bodies, which the shared header declares without arguments
void NiNodeUpdateSelectedDownwardPass(NiNode* a_self, NiUpdateData& a_data, std::uint32_t a_arg2);
void NiNodeUpdateRigidDownwardPass(NiNode* a_self, NiUpdateData& a_data, std::uint32_t a_arg2);
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
    virtual void UpdateWorldBound();  // compared: 0xeee080
    virtual void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xeedc40
    virtual void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xeedda0
    virtual void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xeedf20

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
