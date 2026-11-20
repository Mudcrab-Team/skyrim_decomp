// Source exposure: mixed (pinned image, project slot layout, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layout follows the project TESObjectREFR header and the cited declarations.
// TESObjectREFR: EXE_RTTI
// TESForm, TESBoundObject, FormType, OBJ_REFR, NiPoint3, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryChanges, BGSDecalGroup, BipedAnim, NiAVObject, BSFaceGenNiNode, BSTSmartPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL, TESWorldSpace, formFlags, formID, inGameFormFlags, formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// objectReference, angle, location, data, parentCell, extraList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetGoldValue, Get3D, Get3D2, GetBiped, GetBiped2, GetFaceNode, GetFaceNodeSkinned, GetMustUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WorldLookup, worldLookup, padding, storage, FunctionSlot declarations: STANDIN GUESS(low)
// Function1f37b0, Function15eb00, Function172b80, Function170b50, Function1a2200: GUESS(low)
// Function166af0, Function16c9c0, Function16c9f0, Function16cb90, Function16a8a0, Function1675c0: GUESS(low)
// Function2df5b0, Function2e3a80, Function2e3bf0, Function2e4950, Function2e4a20, Function2e4b10: GUESS(low)
// Function2e6600, Function2e6a70, Function2e7b40, Function2ebcb0, Function2f39c0: GUESS(low)
// Function2f6280, Function2ffa40, Function300250, Function3002f0, Function300310, Function300ed0: GUESS(low)
// Function300ee0, Function301940, Function301bc0, Function302060: GUESS(low)

#pragma once

#include <cstdint>

class BGSDecalGroup;
class BipedAnim;
class BSFaceGenNiNode;
class InventoryChanges;
class NiAVObject;
class TESBoundObject;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;

template <class T> class BSTSmartPointer;

enum class FormType : std::uint8_t
{
    Light = 0x1F,
    Furniture = 0x28,
    Hazard = 0x33,
    Reference = 0x3D,
    ActorCharacter = 0x3E,
    PlacedHazard = 0x46
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct OBJ_REFR
{
    TESBoundObject* objectReference;
    NiPoint3 angle;
    NiPoint3 location;
};

class ExtraDataList
{
public:
    InventoryChanges* Function15eb00(TESObjectREFR* reference);
    void Function172b80();
    TESObjectREFR* Function170b50() const;
    BGSDecalGroup* Function166af0();
    float Function16c9c0() const;
    void Function16c9f0();
    bool Function16cb90() const;
    void Function16a8a0(bool value);
    TESObjectREFR* Function1675c0() const;

private:
    std::uint8_t storage[0x20];
};

class TESForm
{
public:
    virtual ~TESForm();
    virtual void FunctionSlot01();  // 01
    virtual void FunctionSlot02();  // 02
    virtual void FunctionSlot03();  // 03
    virtual void FunctionSlot04();  // 04
    virtual void FunctionSlot05();  // 05
    virtual void FunctionSlot06();  // 06
    virtual void FunctionSlot07();  // 07
    virtual void FunctionSlot08();  // 08
    virtual void FunctionSlot09();  // 09
    virtual void FunctionSlot0A();  // 0A
    virtual void FunctionSlot0B();  // 0B
    virtual void FunctionSlot0C();  // 0C
    virtual void FunctionSlot0D();  // 0D
    virtual void FunctionSlot0E();  // 0E
    virtual void FunctionSlot0F();  // 0F
    virtual void FunctionSlot10();  // 10
    virtual void FunctionSlot11();  // 11
    virtual void FunctionSlot12();  // 12
    virtual void FunctionSlot13();  // 13
    virtual void FunctionSlot14();  // 14
    virtual void FunctionSlot15();  // 15
    virtual void FunctionSlot16();  // 16
    virtual void FunctionSlot17();  // 17
    virtual void FunctionSlot18();  // 18
    virtual void FunctionSlot19();  // 19
    virtual void FunctionSlot1A();  // 1A
    virtual void FunctionSlot1B();  // 1B
    virtual void FunctionSlot1C();  // 1C
    virtual void FunctionSlot1D();  // 1D
    virtual void FunctionSlot1E();  // 1E
    virtual void FunctionSlot1F();  // 1F
    virtual bool GetMustUpdate() const;  // 20
    virtual void FunctionSlot21();  // 21
    virtual void FunctionSlot22();  // 22
    virtual void FunctionSlot23();  // 23
    virtual void FunctionSlot24();  // 24
    virtual void FunctionSlot25();  // 25
    virtual void FunctionSlot26();  // 26
    virtual void FunctionSlot27();  // 27
    virtual void FunctionSlot28();  // 28
    virtual void FunctionSlot29();  // 29
    virtual void FunctionSlot2A();  // 2A
    virtual void FunctionSlot2B();  // 2B
    virtual void FunctionSlot2C();  // 2C
    virtual void FunctionSlot2D();  // 2D
    virtual void FunctionSlot2E();  // 2E
    virtual void FunctionSlot2F();  // 2F
    virtual void FunctionSlot30();  // 30
    virtual void FunctionSlot31();  // 31
    virtual void FunctionSlot32();  // 32
    virtual void FunctionSlot33();  // 33
    virtual void FunctionSlot34();  // 34
    virtual void FunctionSlot35();  // 35
    virtual void FunctionSlot36();  // 36
    virtual void FunctionSlot37();  // 37
    virtual void FunctionSlot38();  // 38
    virtual void FunctionSlot39();  // 39
    virtual void FunctionSlot3A();  // 3A

    std::int32_t GetGoldValue() const;
    float Function1f37b0() const;

    std::uint8_t padding008[0x8];
    std::uint32_t formFlags;
    std::uint32_t formID;
    std::uint16_t inGameFormFlags;
    FormType formType;
    std::uint8_t padding01B[0x5];
};
static_assert(sizeof(TESForm) == 0x20, "form prefix size");

class TESBoundObject : public TESForm
{
};

class TESObjectREFR : public TESForm
{
public:
    bool GetMustUpdate() const override;
    virtual void FunctionSlot3B();  // 3B
    virtual void FunctionSlot3C();  // 3C
    virtual void FunctionSlot3D();  // 3D
    virtual void FunctionSlot3E();  // 3E
    virtual void FunctionSlot3F();  // 3F
    virtual void FunctionSlot40();  // 40
    virtual void FunctionSlot41();  // 41
    virtual void FunctionSlot42();  // 42
    virtual void FunctionSlot43();  // 43
    virtual void FunctionSlot44();  // 44
    virtual void FunctionSlot45();  // 45
    virtual void FunctionSlot46();  // 46
    virtual void FunctionSlot47();  // 47
    virtual void FunctionSlot48();  // 48
    virtual void FunctionSlot49();  // 49
    virtual void FunctionSlot4A();  // 4A
    virtual void FunctionSlot4B();  // 4B
    virtual void FunctionSlot4C();  // 4C
    virtual void FunctionSlot4D();  // 4D
    virtual void FunctionSlot4E();  // 4E
    virtual void FunctionSlot4F();  // 4F
    virtual void FunctionSlot50();  // 50
    virtual void FunctionSlot51();  // 51
    virtual void FunctionSlot52();  // 52
    virtual void FunctionSlot53();  // 53
    virtual void FunctionSlot54();  // 54
    virtual void FunctionSlot55();  // 55
    virtual void FunctionSlot56();  // 56
    virtual void FunctionSlot57();  // 57
    virtual void FunctionSlot58();  // 58
    virtual void FunctionSlot59();  // 59
    virtual void FunctionSlot5A();  // 5A
    virtual void FunctionSlot5B();  // 5B
    virtual void FunctionSlot5C();  // 5C
    virtual void FunctionSlot5D();  // 5D
    virtual void FunctionSlot5E();  // 5E
    virtual void FunctionSlot5F();  // 5F
    virtual void FunctionSlot60();  // 60
    virtual BSFaceGenNiNode* GetFaceNodeSkinned();  // 61
    virtual BSFaceGenNiNode* GetFaceNode();  // 62
    virtual void FunctionSlot63();  // 63
    virtual void FunctionSlot64();  // 64
    virtual void FunctionSlot65();  // 65
    virtual void FunctionSlot66();  // 66
    virtual void FunctionSlot67();  // 67
    virtual void FunctionSlot68();  // 68
    virtual void FunctionSlot69();  // 69
    virtual void FunctionSlot6A();  // 6A
    virtual void FunctionSlot6B();  // 6B
    virtual void FunctionSlot6C();  // 6C
    virtual void FunctionSlot6D();  // 6D
    virtual void FunctionSlot6E();  // 6E
    virtual void FunctionSlot6F();  // 6F
    virtual NiAVObject* Get3D2() const;  // 70
    virtual void FunctionSlot71();  // 71
    virtual void FunctionSlot72();  // 72
    virtual void FunctionSlot73();  // 73
    virtual void FunctionSlot74();  // 74
    virtual void FunctionSlot75();  // 75
    virtual void FunctionSlot76();  // 76
    virtual void FunctionSlot77();  // 77
    virtual void FunctionSlot78();  // 78
    virtual void FunctionSlot79();  // 79
    virtual void FunctionSlot7A();  // 7A
    virtual void FunctionSlot7B();  // 7B
    virtual void FunctionSlot7C();  // 7C
    virtual void FunctionSlot7D();  // 7D
    virtual void FunctionSlot7E();  // 7E
    virtual const BSTSmartPointer<BipedAnim>& GetBiped2() const;  // 7F

    InventoryChanges* Function2df5b0();
    static bool Function2e3a80(std::uint32_t type);
    bool Function2e3bf0() const;
    bool Function2e4950() const;
    bool Function2e4a20() const;
    bool Function2e4b10() const;
    bool Function2e6600() const;
    void Function2e6a70();
    TESObjectREFR* Function2e7b40() const;
    TESWorldSpace* Function2ebcb0() const;
    TESObjectREFR* Function2f39c0();
    BGSDecalGroup* Function2f6280();
    const BSTSmartPointer<BipedAnim>& GetBiped() const;
    NiAVObject* Get3D() const;
    bool Function2ffa40() const;
    float Function300250() const;
    void Function3002f0();
    bool Function300310() const;
    std::int32_t Function300ed0() const;
    float Function300ee0() const;
    bool Function301940();
    void Function301bc0();
    TESObjectREFR* Function302060() const;

private:
    std::uint8_t padding020[0x20];
    OBJ_REFR data;
    TESObjectCELL* parentCell;
    std::uint8_t padding068[0x8];
    ExtraDataList extraList;
};
