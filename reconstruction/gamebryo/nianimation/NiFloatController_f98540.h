// Source exposure: mixed (community declarations; community PDB names; pinned-image observations).
// Code origin: original; minimal stand-ins for the observed clone dispatch
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiTimeController, NiObject, NiCloningProcess, NiFloatData, NiTimeController::ProcessClone, NiObject::ProcessClone: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiFloatController::Functionf98540: GUESS(medium); inferred clone-processing override
// NiFloatController::data: GUESS(low); observed nullable pointer at offset 0x50
// NiObject::unknown01, NiObject::unknown02, NiObject::unknown03, NiObject::unknown04, NiObject::unknown05, NiObject::unknown06, NiObject::unknown07, NiObject::unknown08, NiObject::unknown09, NiObject::unknown0A, NiObject::unknown0B, NiObject::unknown0C, NiObject::unknown0D, NiObject::unknown0E, NiObject::unknown0F, NiObject::unknown10, NiObject::unknown11, NiObject::unknown12, NiObject::unknown13, NiObject::unknown14, NiObject::unknown15, NiObject::unknown16, NiObject::unknown17, NiObject::unknown18, NiObject::unknown19, NiObject::unknown1A, NiObject::unknown1B, NiObject::unknown1C: GUESS(low); unobserved virtual slots
#pragma once
#include <cstddef>
#include <cstdint>
class NiCloningProcess;
class NiObject
{
public:
    virtual ~NiObject();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown0A();
    virtual void unknown0B();
    virtual void unknown0C();
    virtual void unknown0D();
    virtual void unknown0E();
    virtual void unknown0F();
    virtual void unknown10();
    virtual void unknown11();
    virtual void unknown12();
    virtual void unknown13();
    virtual void unknown14();
    virtual void unknown15();
    virtual void unknown16();
    virtual void unknown17();
    virtual void unknown18();
    virtual void unknown19();
    virtual void unknown1A();
    virtual void unknown1B();
    virtual void unknown1C();
    virtual void ProcessClone(NiCloningProcess& cloning);
};
class NiFloatData : public NiObject {};
class NiTimeController
{
public:
    void ProcessClone(NiCloningProcess& cloning);
    std::uint8_t unobserved00[0x50];
};
class NiFloatController : public NiTimeController
{
public:
    void Functionf98540(NiCloningProcess& cloning);
    NiFloatData* data;
};
static_assert(offsetof(NiFloatController, data) == 0x50, "observed clone payload offset");
