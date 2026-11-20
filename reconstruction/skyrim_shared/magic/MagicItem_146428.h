// Source exposure: mixed (pinned image listings and RTTI, project layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: partial declarations follow the cited class layouts and pinned RTTI.
// AlchemyItem, IngredientItem, ScrollItem, SpellItem, TESSoulGem: EXE_RTTI
// BaseFormComponent, TESForm, TESObject, TESBoundObject, TESObjectMISC, MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFullName, BGSKeywordForm, TESModel, TESModelTextureSwap, TESTexture, TESIcon: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSMessageIcon, TESWeightForm, BGSEquipType, BGSDestructibleObjectForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSPickupPutdownSounds, TESValueForm, BGSMenuDisplayObject, TESDescription: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Data, costOverride, flags, addictionItem, addictionChance, consumptionSound, pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// data, spellType, chargeTime, castingType, delivery, castDuration, range, castingPerk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetData1, GetDelivery, BGSPerk, BGSSoundDescriptorForm, QueuedFile, preloadedItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SOUL_LEVEL, MagicSystem::SpellType, MagicSystem::CastingType, MagicSystem::Delivery: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetSoulLevel: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// QueuedFile::unk0C: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Function1502a0, Function150db0, Function150dd0, FunctionSlot declarations, padding: STANDIN GUESS(low)

#pragma once

#include <cstdint>

class BGSPerk;
class BGSSoundDescriptorForm;
class SpellItem;

namespace MagicSystem
{
    enum class SpellType : std::int32_t;
    enum class CastingType : std::int32_t;
    enum class Delivery : std::int32_t { kSelf = 0 };
}

enum class SOUL_LEVEL : std::int32_t
{
    kPetty = 1,
    kLesser = 2,
    kCommon = 3,
    kGreater = 4,
    kGrand = 5
};

class QueuedFile
{
public:
    std::uint8_t padding[0xC];
    std::uint32_t unk0C;
};

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent();
};

class TESForm : public BaseFormComponent
{
public:
    ~TESForm() override;
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
    virtual void FunctionSlot20();  // 20
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

private:
    std::uint8_t padding[0x18];
};

class TESObject : public TESForm
{
public:
    ~TESObject() override;
};

class TESBoundObject : public TESObject
{
public:
    ~TESBoundObject() override;
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

private:
    std::uint8_t padding[0x10];
};
static_assert(sizeof(TESBoundObject) == 0x30, "bound object prefix size");

class TESFullName : public BaseFormComponent
{
public:
    ~TESFullName() override;

private:
    std::uint8_t padding[0x8];
};

class BGSKeywordForm : public BaseFormComponent
{
public:
    ~BGSKeywordForm() override;

private:
    std::uint8_t padding[0x10];
};

class TESModel : public BaseFormComponent
{
public:
    ~TESModel() override;

private:
    std::uint8_t padding[0x20];
};

class TESModelTextureSwap : public TESModel
{
public:
    ~TESModelTextureSwap() override;

private:
    std::uint8_t padding[0x10];
};

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;

private:
    std::uint8_t padding[0x8];
};

class TESIcon : public TESTexture
{
public:
    ~TESIcon() override;
};

class BGSMessageIcon : public BaseFormComponent
{
public:
    ~BGSMessageIcon() override;

private:
    std::uint8_t padding[0x10];
};

class TESWeightForm : public BaseFormComponent
{
public:
    ~TESWeightForm() override;

private:
    std::uint8_t padding[0x8];
};

class BGSEquipType : public BaseFormComponent
{
public:
    ~BGSEquipType() override;

private:
    std::uint8_t padding[0x8];
};

class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
    ~BGSDestructibleObjectForm() override;

private:
    std::uint8_t padding[0x8];
};

class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
    ~BGSPickupPutdownSounds() override;

private:
    std::uint8_t padding[0x10];
};

class TESValueForm : public BaseFormComponent
{
public:
    ~TESValueForm() override;

private:
    std::uint8_t padding[0x8];
};

class BGSMenuDisplayObject : public BaseFormComponent
{
public:
    ~BGSMenuDisplayObject() override;

private:
    std::uint8_t padding[0x8];
};

class TESDescription : public BaseFormComponent
{
public:
    ~TESDescription() override;

private:
    std::uint8_t padding[0x8];
};

class MagicItem :
    public TESBoundObject,
    public TESFullName,
    public BGSKeywordForm
{
public:
    struct Data
    {
        std::int32_t costOverride;
        std::uint32_t flags;
    };

    ~MagicItem() override;
    virtual void FunctionSlot53();  // 53
    virtual void FunctionSlot54();  // 54
    virtual void FunctionSlot55();  // 55
    virtual void FunctionSlot56();  // 56
    virtual MagicSystem::Delivery GetDelivery() const;  // 57
    virtual void FunctionSlot58();  // 58
    virtual void FunctionSlot59();  // 59
    virtual void FunctionSlot5A();  // 5A
    virtual void FunctionSlot5B();  // 5B
    virtual void FunctionSlot5C();  // 5C
    virtual void FunctionSlot5D();  // 5D
    virtual void FunctionSlot5E();  // 5E
    virtual void FunctionSlot5F();  // 5F
    virtual void FunctionSlot60();  // 60
    virtual void FunctionSlot61();  // 61
    virtual void FunctionSlot62();  // 62
    virtual void FunctionSlot63();  // 63
    virtual void FunctionSlot64();  // 64
    virtual void FunctionSlot65();  // 65
    virtual void FunctionSlot66();  // 66
    virtual void FunctionSlot67();  // 67
    virtual void FunctionSlot68();  // 68
    virtual void FunctionSlot69();  // 69
    virtual void FunctionSlot6A();  // 6A
    virtual void FunctionSlot6B();  // 6B
    virtual const Data* GetData1() const;  // 6C

protected:
    std::uint8_t padding[0x30];
    QueuedFile* preloadedItem;
};
static_assert(sizeof(MagicItem) == 0x90, "magic item prefix size");

class AlchemyItem :
    public MagicItem,
    public TESModelTextureSwap,
    public TESIcon,
    public BGSMessageIcon,
    public TESWeightForm,
    public BGSEquipType,
    public BGSDestructibleObjectForm,
    public BGSPickupPutdownSounds
{
public:
    AlchemyItem();
    ~AlchemyItem() override;
    const MagicItem::Data* GetData1() const override;

private:
    struct Data : MagicItem::Data
    {
        SpellItem* addictionItem;
        float addictionChance;
        std::uint32_t pad14;
        BGSSoundDescriptorForm* consumptionSound;
    };
    Data data;
};

class IngredientItem :
    public MagicItem,
    public TESModelTextureSwap,
    public TESIcon,
    public TESWeightForm,
    public BGSEquipType,
    public BGSDestructibleObjectForm,
    public BGSPickupPutdownSounds,
    public TESValueForm
{
public:
    IngredientItem();
    ~IngredientItem() override;
    const MagicItem::Data* GetData1() const override;

private:
    MagicItem::Data data;
};

class SpellItem :
    public MagicItem,
    public BGSEquipType,
    public BGSMenuDisplayObject,
    public TESDescription
{
public:
    SpellItem();
    ~SpellItem() override;
    const MagicItem::Data* GetData1() const override;
    bool Function1502a0() const;
    bool Function150db0() const;
    std::uint32_t Function150dd0() const;

private:
    struct Data : MagicItem::Data
    {
        MagicSystem::SpellType spellType;
        float chargeTime;
        MagicSystem::CastingType castingType;
        MagicSystem::Delivery delivery;
        float castDuration;
        float range;
        BGSPerk* castingPerk;
    };
    Data data;
};
static_assert(sizeof(SpellItem) == 0xE8, "spell item base size");

class ScrollItem :
    public SpellItem,
    public TESModelTextureSwap,
    public BGSDestructibleObjectForm,
    public BGSPickupPutdownSounds,
    public TESWeightForm,
    public TESValueForm
{
public:
    ScrollItem();
    ~ScrollItem() override;
};

class TESObjectMISC :
    public TESBoundObject,
    public TESFullName,
    public TESModelTextureSwap,
    public TESIcon,
    public TESValueForm,
    public TESWeightForm,
    public BGSDestructibleObjectForm,
    public BGSMessageIcon,
    public BGSPickupPutdownSounds,
    public BGSKeywordForm
{
public:
    ~TESObjectMISC() override;
};

class TESSoulGem : public TESObjectMISC
{
public:
    TESSoulGem();
    ~TESSoulGem() override;
    static SOUL_LEVEL GetSoulLevel(std::uint32_t actorLevel, bool useGrandSoul);
};
