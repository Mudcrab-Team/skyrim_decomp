// CombatInventoryItem: GUESS(low) STANDIN
/*
 * CombatInventoryItem: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x82ce60 33 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Stand-ins are unverified.
 */
#pragma once

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#include <cstdint>
// NiRefObject, NiRefObject::DeleteThis, CombatObject, CombatObject::GetObjectType, CombatObject::SaveGame, CombatObject::LoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatInventoryItem, CombatInventoryItem::GetMinRange, CombatInventoryItem::GetMaxRange, CombatInventoryItem::GetOptimalRange, CombatInventoryItem::GetEquipRange, CombatInventoryItem::GetType, CombatInventoryItem::GetEquipType, CombatInventoryItem::GetCategory, CombatInventoryItem::CalculateScore, CombatInventoryItem::Clone, CombatInventoryItem::CheckBusy, CombatInventoryItem::CheckShouldEquip, CombatInventoryItem::GetResource, CombatInventoryItem::Equip, CombatInventoryItem::Unequip, CombatInventoryItem::IsValid, CombatInventoryItem::GetDescription: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Setting, Setting::data, Setting::name, Setting::Unk_01: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatInventoryItem::Function82ce60, combatSettings: GUESS(low) STANDIN
// Setting: GUESS(low) STANDIN
class BGSSaveGameBuffer; class BGSLoadGameBuffer; class CombatController; class TESForm; class BGSEquipSlot; class CombatInventoryItemResource;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); volatile std::uint32_t _refCount; std::uint32_t _pad0C; };
class CombatObject : public NiRefObject { public: ~CombatObject() override; virtual std::uint32_t GetObjectType() = 0; virtual void SaveGame(BGSSaveGameBuffer*); virtual void LoadGame(BGSLoadGameBuffer*); };
class CombatInventoryItemSlot { public: BGSEquipSlot* equipSlot; std::uint32_t slot; };
class CombatInventoryItem : public CombatObject {
public:
    enum class TYPE { kNone, kMelee, kRanged, kShield, kOneHandedBlock = kShield, kMagic, kShout, kStaff, kPotion, kScroll, kTorch };
    enum class CATEGORY { kTotal = 7 };
    ~CombatInventoryItem() override;
    void SaveGame(BGSSaveGameBuffer*) override;
    void LoadGame(BGSLoadGameBuffer*) override;
    virtual float GetMinRange(); virtual float GetMaxRange(); virtual float GetOptimalRange(); virtual float GetEquipRange();
    virtual TYPE GetType(); virtual TYPE GetEquipType(BGSEquipSlot); virtual CATEGORY GetCategory() = 0;
    virtual float CalculateScore(CombatController*) = 0; virtual CombatInventoryItem* Clone() = 0;
    virtual bool CheckBusy(CombatController*); virtual bool CheckShouldEquip(CombatController*);
    virtual bool GetResource(CombatInventoryItemResource&); virtual void Equip(CombatController*);
    virtual void Unequip(CombatController*); virtual bool IsValid(); virtual void GetDescription(const char*, std::uint32_t);
    float Function82ce60();
    TESForm* item; float itemScore; std::uint32_t unk1C; CombatInventoryItemSlot itemSlot;
};
struct Color { std::uint8_t red, green, blue, alpha; };
class Setting { public: union Data { bool b; float f; std::int32_t i; Color r; char* s; std::uint32_t u; }; virtual ~Setting(); virtual bool Unk_01(); Data data; char* name; };
extern Setting* combatSettings[];

// NiRefObject::_refCount, NiRefObject::_pad0C, CombatInventoryItemSlot, CombatInventoryItemSlot::equipSlot, CombatInventoryItemSlot::slot, CombatInventoryItem::item, CombatInventoryItem::itemScore, CombatInventoryItem::unk1C, CombatInventoryItem::itemSlot: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Color, Color::red, Color::green, Color::blue, Color::alpha, Setting::Data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BGSSaveGameBuffer, BGSLoadGameBuffer, CombatController, TESForm, BGSEquipSlot, CombatInventoryItemResource: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombatInventoryItem::TYPE, CombatInventoryItem::CATEGORY, CombatInventoryItem::TYPE::kNone, CombatInventoryItem::TYPE::kMelee, CombatInventoryItem::TYPE::kRanged, CombatInventoryItem::TYPE::kShield, CombatInventoryItem::TYPE::kOneHandedBlock, CombatInventoryItem::TYPE::kMagic, CombatInventoryItem::TYPE::kShout, CombatInventoryItem::TYPE::kStaff, CombatInventoryItem::TYPE::kPotion, CombatInventoryItem::TYPE::kScroll, CombatInventoryItem::TYPE::kTorch, CombatInventoryItem::CATEGORY::kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Setting::Data::b, Setting::Data::f, Setting::Data::i, Setting::Data::r, Setting::Data::s, Setting::Data::u: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
