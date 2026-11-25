// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and community declarations).
// Code origin: original factory method and allocation model. Adapted bodies: none.
// Factory and product identities: EXE_RTTI
// Allocation sizes and constructor calls: OBSERVED
// CreateImpl, BGSFootstepSet::entries, BGSFootstep: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Heap helpers, product storage and its constructor symbol: GUESS(low) STANDIN
// Product fields, component types and extents: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "../../skyrim_shared/forms/ConcreteFormFactory.h"
#include "../../skyrim_shared/forms/TESForm.h"
#include <cstddef>

class EffectSetting;
class TESCombatStyle;
class TESObjectARMO;
class TESObjectWEAP;
class TESWaterForm;
class TESWeather;
class TESWorldSpace;
class BGSFootstepSet;
class BGSImpactDataSet;
class BGSTextureSet;
class Script;
class BGSBodyPartData;
class BGSRagdoll;
class TESNPC;
class TESQuest;
class TESRace;

namespace FormFactoryLayout
{
#include "../../generated/crashlogger_pdb/types/EffectSetting_86f4824b.h"
#include "../../generated/crashlogger_pdb/types/TESCombatStyle_cff5b770.h"
#include "../../generated/crashlogger_pdb/types/TESObjectARMO_295db33a.h"
#include "../../generated/crashlogger_pdb/types/TESObjectWEAP_335e104b.h"
#include "../../generated/crashlogger_pdb/types/TESWaterForm_2ffdeaeb.h"
#include "../../generated/crashlogger_pdb/types/TESWeather_4adb958d.h"
#include "../../generated/crashlogger_pdb/types/TESWorldSpace.h"
#include "../../generated/crashlogger_pdb/types/BGSImpactDataSet_e1a4fffc.h"
#include "../../generated/crashlogger_pdb/types/BGSTextureSet.h"
#include "../../generated/crashlogger_pdb/types/Script.h"
#include "../../generated/crashlogger_pdb/types/BGSBodyPartData_cf1a6e26.h"
#include "../../generated/crashlogger_pdb/types/BGSRagdoll_15ee38fc.h"
#include "../../generated/crashlogger_pdb/types/TESNPC.h"
#include "../../generated/crashlogger_pdb/types/TESQuest_fe66f8e1.h"
#include "../../generated/crashlogger_pdb/types/TESRace.h"
}

class BGSFootstep;

namespace FormFactoryAllocation
{
class MemoryManager
{
public:
    static MemoryManager instance;
    static unsigned initState;
    void EnsureInitialized(unsigned* state);
    void* Allocate(size_t bytes, int alignment, bool alignmentRequired);
};

// BSTArray's heap allocator owns the buffer and its capacity. The array stores its count.
struct FootstepAllocator
{
    BGSFootstep** data;
    unsigned int capacity;
};

struct FootstepArray
{
    FootstepAllocator allocator;
    unsigned int size;
};
static_assert(offsetof(FootstepArray, size) == 0x10, "footstep array count");
static_assert(sizeof(FootstepArray) == 0x18, "footstep array stride");

struct FootstepSetLayout
{
    FormFactoryLayout::TESForm _base;
    FootstepArray entries[5];
};

template<class T> struct ProductLayout;

template<> struct ProductLayout<::EffectSetting> { using Type = FormFactoryLayout::EffectSetting_86f4824b; };
template<> struct ProductLayout<::TESCombatStyle> { using Type = FormFactoryLayout::TESCombatStyle_cff5b770; };
template<> struct ProductLayout<::TESObjectARMO> { using Type = FormFactoryLayout::TESObjectARMO_295db33a; };
template<> struct ProductLayout<::TESObjectWEAP> { using Type = FormFactoryLayout::TESObjectWEAP_335e104b; };
template<> struct ProductLayout<::TESWaterForm> { using Type = FormFactoryLayout::TESWaterForm_2ffdeaeb; };
template<> struct ProductLayout<::TESWeather> { using Type = FormFactoryLayout::TESWeather_4adb958d; };
template<> struct ProductLayout<::TESWorldSpace> { using Type = FormFactoryLayout::TESWorldSpace; };
template<> struct ProductLayout<::BGSFootstepSet> { using Type = FootstepSetLayout; };
template<> struct ProductLayout<::BGSImpactDataSet> { using Type = FormFactoryLayout::BGSImpactDataSet_e1a4fffc; };
template<> struct ProductLayout<::BGSTextureSet> { using Type = FormFactoryLayout::BGSTextureSet; };
template<> struct ProductLayout<::Script> { using Type = FormFactoryLayout::Script; };
template<> struct ProductLayout<::BGSBodyPartData> { using Type = FormFactoryLayout::BGSBodyPartData_cf1a6e26; };
template<> struct ProductLayout<::BGSRagdoll> { using Type = FormFactoryLayout::BGSRagdoll_15ee38fc; };
template<> struct ProductLayout<::TESNPC> { using Type = FormFactoryLayout::TESNPC; };
template<> struct ProductLayout<::TESQuest> { using Type = FormFactoryLayout::TESQuest_fe66f8e1; };
template<> struct ProductLayout<::TESRace> { using Type = FormFactoryLayout::TESRace; };

// CrashLogger represents each primary base as a member. Walk the layout to the
// TESForm subobject and check its offset against the product's RTTI.
template<class Layout>
struct FormBaseOffset
{
    static constexpr size_t value = offsetof(Layout, _base) + FormBaseOffset<decltype(Layout::_base)>::value;
};

template<>
struct FormBaseOffset<FormFactoryLayout::TESForm>
{
    static constexpr size_t value = 0;
};
static_assert(sizeof(FormFactoryLayout::TESForm) == sizeof(TESForm), "TESForm size");
static_assert(alignof(FormFactoryLayout::TESForm) == alignof(TESForm), "TESForm alignment");

template<class T>
class FormFactoryProductStorage : public ProductLayout<T>::Type
{
public:
    static_assert(FormBaseOffset<typename ProductLayout<T>::Type>::value == 0, "primary TESForm offset");
    FormFactoryProductStorage();

    static void* operator new(size_t bytes)
    {
        if (MemoryManager::initState != 2) {
            MemoryManager::instance.EnsureInitialized(&MemoryManager::initState);
        }
        return MemoryManager::instance.Allocate(bytes, 0, false);
    }
};

static_assert(sizeof(FormFactoryProductStorage<::EffectSetting>) == 0x198, "EffectSetting allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESCombatStyle>) == 0xa0, "TESCombatStyle allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESObjectARMO>) == 0x228, "TESObjectARMO allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESObjectWEAP>) == 0x220, "TESObjectWEAP allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESWaterForm>) == 0x260, "TESWaterForm allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESWeather>) == 0x8d8, "TESWeather allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESWorldSpace>) == 0x358, "TESWorldSpace allocation");
static_assert(sizeof(FormFactoryProductStorage<::BGSFootstepSet>) == 0x98, "BGSFootstepSet allocation");
static_assert(sizeof(FormFactoryProductStorage<::BGSImpactDataSet>) == 0x58, "BGSImpactDataSet allocation");
static_assert(sizeof(FormFactoryProductStorage<::BGSTextureSet>) == 0x130, "BGSTextureSet allocation");
static_assert(sizeof(FormFactoryProductStorage<::Script>) == 0x80, "Script allocation");
static_assert(sizeof(FormFactoryProductStorage<::BGSBodyPartData>) == 0x88, "BGSBodyPartData allocation");
static_assert(sizeof(FormFactoryProductStorage<::BGSRagdoll>) == 0x1b8, "BGSRagdoll allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESNPC>) == 0x268, "TESNPC allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESQuest>) == 0x268, "TESQuest allocation");
static_assert(sizeof(FormFactoryProductStorage<::TESRace>) == 0x4b8, "TESRace allocation");
}
