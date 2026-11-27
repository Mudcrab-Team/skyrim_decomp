// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, FindReferenceFor3D, NiAVObject, BSFadeNode: CRASHLOGGER_PDB(59818@2026.10.24)
// TESBoundObject, PlayerCharacter, OBJ_REFR, FormType, Ammo, formType, objectReference, data, parent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AsFadeNode, userDataF8, Get3D1, gPlayerCharacter, Unk_01..Unk_6E, unknown000, unknown008, unknown038: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

enum class FormType : std::uint8_t
{
    Ammo = 0x2A,
};

class TESBoundObject
{
public:
    std::uint8_t unknown000[0x1A];  // 000
    FormType     formType;          // 01A
};
static_assert(offsetof(TESBoundObject, formType) == 0x1A, "formType offset");

struct OBJ_REFR
{
    TESBoundObject* objectReference;  // 00
};

class NiAVObject;
class BSFadeNode;

class TESObjectREFR
{
public:
    virtual ~TESObjectREFR();  // 00
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual NiAVObject* Get3D1(bool firstPerson) const;  // 6F (0x378)

    static TESObjectREFR* FindReferenceFor3D(NiAVObject* object);

    std::uint8_t unknown008[0x38];  // 008
    OBJ_REFR     data;              // 040
};
static_assert(offsetof(TESObjectREFR, data) == 0x40, "data offset");

class PlayerCharacter : public TESObjectREFR
{
};

extern PlayerCharacter* gPlayerCharacter;

class NiAVObject
{
public:
    virtual ~NiAVObject();         // 00
    virtual void        Unk_01();  // 01
    virtual void        Unk_02();  // 02
    virtual void        Unk_03();  // 03
    virtual void        Unk_04();  // 04
    virtual BSFadeNode* AsFadeNode();  // 05 (0x28)

    std::uint8_t unknown008[0x28];  // 008
    NiAVObject*  parent;            // 030
};
static_assert(offsetof(NiAVObject, parent) == 0x30, "parent offset");

class BSFadeNode : public NiAVObject
{
public:
    std::uint8_t   unknown038[0xC0];  // 038
    TESObjectREFR* userDataF8;        // 0F8
};
static_assert(offsetof(BSFadeNode, userDataF8) == 0xF8, "userDataF8 offset");
