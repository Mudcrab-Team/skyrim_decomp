// Source exposure: mixed (community declarations; target observations).
// Code origin: original stand-in declarations using labelled names
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, UpdateDownwardPass: CRASHLOGGER_PDB(59818@2026.10.24)
// NiUpdateData, time, flags, NiTimeController, next, UpdateWorldData, UpdateWorldBound, controllers: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Update signature, Slot00 through Slot2E, unknown08: STANDIN OBSERVED
#pragma once
#include <cstdint>
struct NiUpdateData { float time; std::uint32_t flags; };
class NiTimeController
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
    virtual void Update(NiUpdateData& data);
    std::uint8_t unknown08[0x38];
    NiTimeController* next;
};
class NiAVObject
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
    virtual void UpdateWorldBound();
    virtual void UpdateWorldData(NiUpdateData* data);
    void UpdateDownwardPass(NiUpdateData& data, std::uint32_t flags);
    std::uint8_t unknown08[0x10];
    NiTimeController* controllers;
};
