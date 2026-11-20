// Code origin: declarations written by hand from the local listings and the community headers; the bodies are in the matching .cpp.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// unknown00, cost, flags, InitializeMagicData, RemoveAllEffects, ClearFormData: STANDIN GUESS(low)
// GetData2, IsMedicine, IsPoison, IsFood: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// GetData: GUESS(low); virtual slot 0x6C (byte offset 0x360), returns the record whose flags the three tests read
// Unk_61: GUESS(low); virtual slot 0x61 (byte offset 0x308), a bool test called by IsFood
// Unk_NN: GUESS(low); placeholders that only keep Unk_61 and GetData at the vtable offsets the image encodes
// AlchemyData: STANDIN GUESS(low); the first two members of the record at 0x138 (cost, flags)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
struct AlchemyData {
    std::int32_t  cost;   // 00
    std::uint32_t flags;  // 04
};
class AlchemyItem {
public:
    virtual void Unk_00();
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
    virtual bool Unk_61() const;
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
    virtual AlchemyData* GetData() const;  // 6C
    virtual AlchemyData* GetData2();
    virtual bool IsMedicine() const;
    virtual bool IsPoison() const;
    virtual bool IsFood() const;

    void InitializeData();
    void ClearData();
private:
    void InitializeMagicData();
    void RemoveAllEffects();
    void ClearFormData();
public:
    // flattened secondary bases at their CommonLibSSE-NG offsets (vptr slot plus fields)
    void*         sourceFiles;           // 08 TESForm
    std::uint32_t formFlags;             // 10
    std::uint32_t formID;                // 14
    std::uint16_t inGameFormFlags;       // 18
    std::uint8_t  formType;              // 1A
    std::uint8_t  pad1B;                 // 1B
    std::uint32_t pad1C;                 // 1C
    std::int16_t  boundData[6];          // 20 TESBoundObject OBND
    std::uint32_t pad2C;                 // 2C
    void*         vptrFullName;          // 30 TESFullName
    void*         fullName;              // 38
    void*         vptrKeywordForm;       // 40 BGSKeywordForm
    void**        keywords;              // 48
    std::uint32_t numKeywords;           // 50
    std::uint32_t pad54;                 // 54
    void*         effectsBegin;          // 58 MagicItem::effects (BSTArray)
    void*         effectsPad;            // 60
    std::uint64_t effectsSizeCapacity;   // 68
    std::int32_t  hostileCount;          // 70
    std::uint32_t pad74;                 // 74
    void*         avEffectSetting;       // 78
    std::uint32_t preloadCount;          // 80
    std::uint32_t pad84;                 // 84
    void*         preloadedItem;         // 88
    void*         vptrModel;             // 90 TESModelTextureSwap
    void*         model;                 // 98
    void*         textures;              // A0
    void*         addons;                // A8
    std::uint16_t numTextures;           // B0
    std::uint16_t numAddons;             // B2
    std::uint32_t pad24;                 // B4
    void*         alternateTextures;     // B8
    std::uint32_t numAlternateTextures;  // C0
    std::uint32_t pad34;                 // C4
    void*         vptrIcon;              // C8 TESIcon
    void*         textureName;           // D0
    void*         vptrMessageIcon;       // D8 BGSMessageIcon
    void*         vptrMsgIconIcon;       // E0 (icon TESIcon vptr)
    void*         msgIconTextureName;    // E8
    void*         vptrWeightForm;        // F0 TESWeightForm
    float         weight;                // F8
    std::uint32_t pad0C;                 // FC
    void*         vptrEquipType;         // 100 BGSEquipType
    void*         equipSlot;             // 108
    void*         vptrDestructible;      // 110 BGSDestructibleObjectForm
    void*         destructibleData;      // 118
    void*         vptrPickupPutdown;     // 120 BGSPickupPutdownSounds
    void*         pickupSound;           // 128
    void*         putdownSound;          // 130
    int cost;                            // 138 ENIT costOverride
    std::uint32_t flags;                 // 13C
    void* addictionItem;                 // 140
    float addictionChance;               // 148
    std::uint32_t pad14;                 // 14C
    void* consumptionSound;              // 150
    void*         vptrMessageIcon2;      // 158 messageIcon TESIcon
    void*         messageIconName;       // 160
};
static_assert(offsetof(AlchemyItem, cost) == 0x138, "cost at 0x138");
static_assert(offsetof(AlchemyItem, consumptionSound) == 0x150, "consumptionSound at 0x150");
static_assert(sizeof(AlchemyItem) == 0x168, "size");
