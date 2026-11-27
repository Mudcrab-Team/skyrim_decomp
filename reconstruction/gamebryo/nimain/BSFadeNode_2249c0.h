// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: statement shape adapted from a sibling body, offsets and names checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFadeNode::SetControllerFloatFieldRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFadeNode, NiNode, NiRTTI, NiTimeController, NiTObjectArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); header-gap NiNode, NiObjectNET (children and controllers sit in padding of the declaration kit)
// NiRTTI::baseRTTI, NiTimeController::phase, NiTimeController::next, NiNode::controllers, NiNode::children, NiNode::GetRTTI, NiNode::DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTObjectArray::_data, NiTObjectArray::_capacity, NiTObjectArray::_freeIdx, NiTObjectArray::_size, NiTObjectArray::_growthSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRTTI_BSFadeNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the image address is bound by hint, the NG offset is for another build
// unknown08, unknown1c, unknown20: GUESS(low)
#pragma once

#include <cstdint>

class NiRTTI
{
public:
    const char* name;           // 00
    const NiRTTI* baseRTTI;     // 08
};
static_assert(sizeof(NiRTTI) == 0x10, "NiRTTI size");

class NiTimeController
{
public:
    virtual ~NiTimeController();  // 00

    std::uint8_t unknown08[0x10];  // 08
    float phase;                   // 18
    std::uint8_t unknown1c[0x24];  // 1C
    NiTimeController* next;        // 40
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");

template <class T>
class NiTObjectArray
{
public:
    virtual ~NiTObjectArray();  // 00

    T* _data;                    // 08
    std::uint16_t _capacity;     // 10
    std::uint16_t _freeIdx;      // 12
    std::uint16_t _size;         // 14
    std::uint16_t _growthSize;   // 16
};

class NiNode
{
public:
    virtual ~NiNode();                       // 00
    virtual void DeleteThis();               // 01
    virtual const NiRTTI* GetRTTI() const;   // 02

    std::uint8_t unknown08[0x10];            // 08
    NiTimeController* controllers;           // 18
    std::uint8_t unknown20[0xf0];            // 20
    NiTObjectArray<NiNode*> children;        // 110
};

extern const NiRTTI NiRTTI_BSFadeNode;

class BSFadeNode : public NiNode
{
public:
    static void SetControllerFloatFieldRecursive(NiNode* a_node, float a_value);
};
