// Source exposure: mixed (pinned image, project slot layout, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies from the pinned listings except the attributed virtual forwarders.
// Adapted bodies: Get3D and GetBiped follow CommonLibSSE-NG@b93280e src/RE/T/TESObjectREFR.cpp:102 and :163 (MIT).
// Adapted bodies: GetFaceNode and GetMustUpdate follow CommonLibSSE-NG@b93280e include/RE/T/TESObjectREFR.h:294 and :231 (MIT).
// 0x2e3a80 TESObjectREFR::Function2e3a80
// 0x2e3bf0 TESObjectREFR::Function2e3bf0
// 0x2e4950 TESObjectREFR::Function2e4950
// 0x2e4a20 TESObjectREFR::Function2e4a20
// 0x2e4b10 TESObjectREFR::Function2e4b10
// 0x2e6600 TESObjectREFR::Function2e6600
// 0x2e6a70 TESObjectREFR::Function2e6a70
// 0x2e7b40 TESObjectREFR::Function2e7b40
// 0x2f39c0 TESObjectREFR::Function2f39c0
// 0x2f9f50 TESObjectREFR::GetBiped
// 0x2f9f60 TESObjectREFR::Get3D
// 0x2f9fb0 TESObjectREFR::GetFaceNode
// 0x2fa0a0 TESObjectREFR::GetMustUpdate
// 0x2ffa40 TESObjectREFR::Function2ffa40
// 0x300250 TESObjectREFR::Function300250
// 0x300ed0 TESObjectREFR::Function300ed0
// 0x300ee0 TESObjectREFR::Function300ee0
// 0x301940 TESObjectREFR::Function301940
// 0x301bc0 TESObjectREFR::Function301bc0
// 0x302060 TESObjectREFR::Function302060
#include "TESObjectREFR_2df5b0.h"

// WorldLookup, worldLookup, Function1a2200: STANDIN GUESS(low)
class WorldLookup
{
public:
    TESWorldSpace* Function1a2200(TESObjectCELL* cell, const void* context);
};

extern WorldLookup* worldLookup;

bool TESObjectREFR::Function2e3a80(std::uint32_t type)
{
    constexpr auto first = static_cast<std::uint32_t>(FormType::Reference);
    constexpr auto last = static_cast<std::uint32_t>(FormType::PlacedHazard);
    return type - first <= last - first;
}

bool TESObjectREFR::Function2e3bf0() const
{
    if (data.objectReference->formType == FormType::Light) {
        return static_cast<std::uint8_t>(formFlags >> 16) & 1u;
    }
    return false;
}

bool TESObjectREFR::Function2e4950() const
{
    return (formFlags >> 29) & 1u;
}

bool TESObjectREFR::Function2e4a20() const
{
    return (formFlags >> 19) & 1u;
}

bool TESObjectREFR::Function2e4b10() const
{
    return (static_cast<std::uint8_t>(inGameFormFlags) >> 6) & 1u;
}

bool TESObjectREFR::Function2e6600() const
{
    const auto* actor = formType == FormType::ActorCharacter ? this : nullptr;
    return actor == nullptr;
}

void TESObjectREFR::Function2e6a70()
{
    auto* list = &extraList;
    if (list) {
        return list->Function172b80();
    }
}

TESObjectREFR* TESObjectREFR::Function2e7b40() const
{
    return extraList.Function170b50();
}

TESObjectREFR* TESObjectREFR::Function2f39c0()
{
    TESObjectREFR* reference = nullptr;
    if (const auto* base = data.objectReference) {
        reference = base->formType == FormType::Hazard ? this : nullptr;
    }
    return reference;
}

const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetBiped() const
{
    return GetBiped2();
}

NiAVObject* TESObjectREFR::Get3D() const
{
    return Get3D2();
}

BSFaceGenNiNode* TESObjectREFR::GetFaceNode()
{
    return GetFaceNodeSkinned();
}

bool TESObjectREFR::GetMustUpdate() const
{
    return data.objectReference->GetMustUpdate();
}

bool TESObjectREFR::Function2ffa40() const
{
    return data.objectReference && data.objectReference->formType == FormType::Furniture;
}

float TESObjectREFR::Function300250() const
{
    if (data.objectReference->formType == FormType::Light) {
        return extraList.Function16c9c0();
    }
    return 0.0f;
}

std::int32_t TESObjectREFR::Function300ed0() const
{
    return data.objectReference->GetGoldValue();
}

float TESObjectREFR::Function300ee0() const
{
    return data.objectReference->Function1f37b0();
}

bool TESObjectREFR::Function301940()
{
    Get3D2();
    return false;
}

void TESObjectREFR::Function301bc0()
{
    return extraList.Function16a8a0(false);
}

TESObjectREFR* TESObjectREFR::Function302060() const
{
    return extraList.Function1675c0();
}
