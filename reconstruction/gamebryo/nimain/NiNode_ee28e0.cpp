// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: brown-room reconstruction from disassembly
// NiNode: EXE_RTTI
// NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiBound, NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTempNodeManager, BSNiNode, NodeInFrustum, BoundInFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode::UpdateUpwardPass: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); no data argument is passed on in the image
// NiNodeSlots, UpdateWorldBound, parent: GUESS(low); file-local view of the vtable slots 0x2F and 0x3D and the parent link at 0x30
// NiNodeBase, worldBound offset, unk00: GUESS(low)
// Function4182a0, UpdateFirst, UpdateSecond, Function152a290, Function14e7f80, Functionfde7a0, UpdateFloat, QueryFlag, UpdateNode, Function6e9a50, GetPackageThatIsRunning, GetSpecialPackage, GetRunningOverride, Function639890, ConvertPosition, CountPosition: GUESS(low)
// Adapted bodies: none
// 0xee28e0 NiNode::UpdateUpwardPass
#include "NiNode_ee28e0.h"
#include <cstdint>

// NiNodeSlots: GUESS(low); the padding virtuals keep the two called slots on their offsets.
class NiNodeSlots
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void UpdateWorldBound();  // 2F
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot3A();
    virtual void Slot3B();
    virtual void Slot3C();
    virtual void UpdateUpwardPass();  // 3D

    std::uint8_t unk08[0x28];  // 08
    NiNodeSlots* parent;       // 30
};

void NiNode::UpdateUpwardPass()
{
    NiNodeSlots* self = reinterpret_cast<NiNodeSlots*>(this);
    NiNodeSlots* above = self->parent;
    self->UpdateWorldBound();
    if (above) {
        above->UpdateUpwardPass();
    }
}
