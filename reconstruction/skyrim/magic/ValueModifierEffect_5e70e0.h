// Source exposure: mixed (local target observations; community declarations; permitted sibling game code).
// Code origin: original declarations; sibling method name.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ValueModifierEffect::IsZeroDurationException: SIBLING(fo4-private@1b765c70, author-permission)
// ValueModifierEffect, ValueModifierEffect::spell, ValueModifierEffect::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicItem, MagicItem::GetSpellType, MagicItem::GetCastingType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicSystem, MagicSystem::SpellType, MagicSystem::CastingType, kDisease, kAbility, kConcentration: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00-unknown54, unknownPrefix, unknown48: GUESS(low) STANDIN; unused virtual slots and opaque storage.
#pragma once
#include <cstdint>
#include <cstddef>
namespace MagicSystem
{
    enum class SpellType { kDisease = 1, kAbility = 4 };
    enum class CastingType { kConcentration = 2 };
}
class MagicItem
{
public:
    virtual void unknown00();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown0a();
    virtual void unknown0b();
    virtual void unknown0c();
    virtual void unknown0d();
    virtual void unknown0e();
    virtual void unknown0f();
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
    virtual void unknown1a();
    virtual void unknown1b();
    virtual void unknown1c();
    virtual void unknown1d();
    virtual void unknown1e();
    virtual void unknown1f();
    virtual void unknown20();
    virtual void unknown21();
    virtual void unknown22();
    virtual void unknown23();
    virtual void unknown24();
    virtual void unknown25();
    virtual void unknown26();
    virtual void unknown27();
    virtual void unknown28();
    virtual void unknown29();
    virtual void unknown2a();
    virtual void unknown2b();
    virtual void unknown2c();
    virtual void unknown2d();
    virtual void unknown2e();
    virtual void unknown2f();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void unknown33();
    virtual void unknown34();
    virtual void unknown35();
    virtual void unknown36();
    virtual void unknown37();
    virtual void unknown38();
    virtual void unknown39();
    virtual void unknown3a();
    virtual void unknown3b();
    virtual void unknown3c();
    virtual void unknown3d();
    virtual void unknown3e();
    virtual void unknown3f();
    virtual void unknown40();
    virtual void unknown41();
    virtual void unknown42();
    virtual void unknown43();
    virtual void unknown44();
    virtual void unknown45();
    virtual void unknown46();
    virtual void unknown47();
    virtual void unknown48();
    virtual void unknown49();
    virtual void unknown4a();
    virtual void unknown4b();
    virtual void unknown4c();
    virtual void unknown4d();
    virtual void unknown4e();
    virtual void unknown4f();
    virtual void unknown50();
    virtual void unknown51();
    virtual void unknown52();
    virtual MagicSystem::SpellType GetSpellType() const;
    virtual void unknown54();
    virtual MagicSystem::CastingType GetCastingType() const;
};
class ValueModifierEffect
{
public:
    bool IsZeroDurationException() const;
    std::uint8_t unknownPrefix[0x40];
    MagicItem* spell;
    std::uint8_t unknown48[0x34];
    std::uint32_t flags;
};
static_assert(offsetof(ValueModifierEffect, spell) == 0x40, "spell offset");
static_assert(offsetof(ValueModifierEffect, flags) == 0x7c, "flags offset");
