// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original stand-in declarations with labelled names
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, SetControllerFieldRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, NiCollisionObject, NiTimeController, AsNode, controllers, collisionObject, children, phase, next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Slot00 through Slot02, unknown00, unknown1C, unknown08, unknown20, unknown48, unknown110, data, capacity, size, field offsets: STANDIN OBSERVED
#pragma once
#include <cstdint>
class NiNode;
class NiCollisionObject;
class NiTimeController {
public:
    std::uint8_t unknown00[0x18];
    float phase;
    std::uint8_t unknown1C[0x24];
    NiTimeController* next;
};
class NiAVObject {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual NiNode* AsNode();
    static void SetControllerFieldRecursive(NiAVObject* object, float value);
    std::uint8_t unknown08[0x10];
    NiTimeController* controllers;
    std::uint8_t unknown20[0x20];
    NiCollisionObject* collisionObject;
    std::uint8_t unknown48[0xC8];
};
class NiNode : public NiAVObject {
public:
    void* unknown110;
    NiAVObject** data;
    std::uint16_t capacity;
    std::uint16_t size;
};
