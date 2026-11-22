// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0x78db60 compared function
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// ActionInput, BGSActionData: STANDIN EXE_RTTI
// TESActionData::Unk_02: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// return type std::uint32_t of the slot: GUESS(low)
// ActionInput::~ActionInput, unknown08, unknown28: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// ActionTarget, member08, Slot00..Slot45: GUESS(low) STANDIN
class ActionTarget
{
public:
    virtual std::uint32_t Slot00();  // slot 0
    virtual std::uint32_t Slot01();  // slot 1
    virtual std::uint32_t Slot02();  // slot 2
    virtual std::uint32_t Slot03();  // slot 3
    virtual std::uint32_t Slot04();  // slot 4
    virtual std::uint32_t Slot05();  // slot 5
    virtual std::uint32_t Slot06();  // slot 6
    virtual std::uint32_t Slot07();  // slot 7
    virtual std::uint32_t Slot08();  // slot 8
    virtual std::uint32_t Slot09();  // slot 9
    virtual std::uint32_t Slot0A();  // slot 10
    virtual std::uint32_t Slot0B();  // slot 11
    virtual std::uint32_t Slot0C();  // slot 12
    virtual std::uint32_t Slot0D();  // slot 13
    virtual std::uint32_t Slot0E();  // slot 14
    virtual std::uint32_t Slot0F();  // slot 15
    virtual std::uint32_t Slot10();  // slot 16
    virtual std::uint32_t Slot11();  // slot 17
    virtual std::uint32_t Slot12();  // slot 18
    virtual std::uint32_t Slot13();  // slot 19
    virtual std::uint32_t Slot14();  // slot 20
    virtual std::uint32_t Slot15();  // slot 21
    virtual std::uint32_t Slot16();  // slot 22
    virtual std::uint32_t Slot17();  // slot 23
    virtual std::uint32_t Slot18();  // slot 24
    virtual std::uint32_t Slot19();  // slot 25
    virtual std::uint32_t Slot1A();  // slot 26
    virtual std::uint32_t Slot1B();  // slot 27
    virtual std::uint32_t Slot1C();  // slot 28
    virtual std::uint32_t Slot1D();  // slot 29
    virtual std::uint32_t Slot1E();  // slot 30
    virtual std::uint32_t Slot1F();  // slot 31
    virtual std::uint32_t Slot20();  // slot 32
    virtual std::uint32_t Slot21();  // slot 33
    virtual std::uint32_t Slot22();  // slot 34
    virtual std::uint32_t Slot23();  // slot 35
    virtual std::uint32_t Slot24();  // slot 36
    virtual std::uint32_t Slot25();  // slot 37
    virtual std::uint32_t Slot26();  // slot 38
    virtual std::uint32_t Slot27();  // slot 39
    virtual std::uint32_t Slot28();  // slot 40
    virtual std::uint32_t Slot29();  // slot 41
    virtual std::uint32_t Slot2A();  // slot 42
    virtual std::uint32_t Slot2B();  // slot 43
    virtual std::uint32_t Slot2C();  // slot 44
    virtual std::uint32_t Slot2D();  // slot 45
    virtual std::uint32_t Slot2E();  // slot 46
    virtual std::uint32_t Slot2F();  // slot 47
    virtual std::uint32_t Slot30();  // slot 48
    virtual std::uint32_t Slot31();  // slot 49
    virtual std::uint32_t Slot32();  // slot 50
    virtual std::uint32_t Slot33();  // slot 51
    virtual std::uint32_t Slot34();  // slot 52
    virtual std::uint32_t Slot35();  // slot 53
    virtual std::uint32_t Slot36();  // slot 54
    virtual std::uint32_t Slot37();  // slot 55
    virtual std::uint32_t Slot38();  // slot 56
    virtual std::uint32_t Slot39();  // slot 57
    virtual std::uint32_t Slot3A();  // slot 58
    virtual std::uint32_t Slot3B();  // slot 59
    virtual std::uint32_t Slot3C();  // slot 60
    virtual std::uint32_t Slot3D();  // slot 61
    virtual std::uint32_t Slot3E();  // slot 62
    virtual std::uint32_t Slot3F();  // slot 63
    virtual std::uint32_t Slot40();  // slot 64
    virtual std::uint32_t Slot41();  // slot 65
    virtual std::uint32_t Slot42();  // slot 66
    virtual std::uint32_t Slot43();  // slot 67
    virtual std::uint32_t Slot44();  // slot 68
    virtual std::uint32_t Slot45();  // slot 69
};

class ActionInput
{
public:
    virtual ~ActionInput() = default;
    ActionTarget* member08;  // 08
    std::uint8_t unknown10[0x18];  // 10 .. 27
};
static_assert(sizeof(ActionInput) == 0x28, "ActionInput size");

class BGSActionData : public ActionInput
{
public:
    std::uint8_t unknown28[0x38];  // 28
};
static_assert(sizeof(BGSActionData) == 0x60, "BGSActionData size");

class TESActionData : public BGSActionData
{
public:
    virtual std::uint32_t Unk_02();  // compared: 0x78db50
    std::uint32_t Function78db60();  // compared: 0x78db60
};
static_assert(sizeof(TESActionData) == 0x60, "TESActionData size");
