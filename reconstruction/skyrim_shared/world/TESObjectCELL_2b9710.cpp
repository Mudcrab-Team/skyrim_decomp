// Source exposure: mixed (pinned image listings, CommonLibSSE-NG declarations, and project cell units including a permitted sibling adaptation).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies from the listings using community field declarations.
// Adapted bodies: IsCellChildType follows the type switch in the project TESObjectCELL_2c4c20 unit.
// TESObjectCELL::IsCellChildType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectCELL.cpp:2801
// 0x2b9710 TESObjectCELL::PackGridKey32
// 0x2b9730 TESObjectCELL::PackGridKey8
// 0x2bb140 TESObjectCELL::IsPersistentCell
// 0x2bbc00 TESObjectCELL::GetExteriorData
// 0x2bbc20 TESObjectCELL::GetInteriorData
// 0x2bc2d0 TESObjectCELL::SetNearFogColor
// 0x2bc2f0 TESObjectCELL::SetFarFogColor
// 0x2bc310 TESObjectCELL::GetNearFogDistance
// 0x2bc350 TESObjectCELL::SetNearFogDistance
// 0x2bc380 TESObjectCELL::GetFarFogDistance
// 0x2bc3c0 TESObjectCELL::SetFarFogDistance
// 0x2bc540 TESObjectCELL::GetLightFadeStart
// 0x2bc5b0 TESObjectCELL::GetLightFadeEnd
// 0x2bc620 TESObjectCELL::GetCellX
// 0x2bc640 TESObjectCELL::GetCellY
// 0x2bc690 TESObjectCELL::GetWorldX
// 0x2bc6b0 TESObjectCELL::GetWorldY
// 0x2bc6d0 TESObjectCELL::GetWorldCoordinates
// 0x2bc710 TESObjectCELL::SetCellCoordinates
// 0x2bc750 TESObjectCELL::GetDirectionalAmbientColor
// 0x2bcd60 TESObjectCELL::GetNavMeshes
// 0x2be360 TESObjectCELL::GetCell3D
// 0x2bf310 TESObjectCELL::GetInteriorRegion
// 0x2bf6b0 TESObjectCELL::IsOffLimits
// 0x2c39b0 TESObjectCELL::SetExteriorWorldSpace
// 0x2c4c40 TESObjectCELL::IsCellChildType
// 0x2c5c60 TESObjectCELL::HasTempData
// 0x2c9600 TESObjectCELL::HasSpinLockCount
// 0x2c9700 TESObjectCELL::GetQueuedRefCount
// 0x2c9740 TESObjectCELL::IncrementQueuedRefCount
// 0x2c97a0 TESObjectCELL::GetCriticalQueuedRefCount
// 0x2c97e0 TESObjectCELL::IncrementCriticalQueuedRefCount
// 0x2cb250 TESObjectCELL::GetTerrainVisibility
// 0x2da3b0 TESObjectCELL::GetLoadedHandleList
// 0x2db270 TESObjectCELL::GetCellForm
#include "TESObjectCELL_2b9710.h"
#include <intrin.h>

// cellX, cellY, lodVisData, worldX, worldY: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fogColorNear, fogColorFar, fogNear, fogFar, lightFadeStart: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// lightFadeEnd, lightingTemplateInheritanceFlags, kFogNear, kFogFar, kLightFadeDistances: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kAmbientColor, cell3D, unk100, criticalQueuedRefCount, queuedRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// directionalColors: STANDIN GUESS(low)

struct EXTERIOR_DATA
{
    std::int32_t cellX;
    std::int32_t cellY;
    std::uint8_t padding08[8];
    BGSTerrainVisibilityData* lodVisData;
    float worldX;
    float worldY;
};

struct INTERIOR_DATA
{
    enum : std::uint32_t {
        kAmbientColor = 1, kFogNear = 8, kFogFar = 16, kLightFadeDistances = 1u << 10
    };
    std::uint8_t padding00[8];
    PackedColor fogColorNear;
    float fogNear;
    float fogFar;
    std::uint8_t padding14[0x14];
    PackedColor directionalColors[6];
    std::uint8_t padding40[8];
    PackedColor fogColorFar;
    float fogClamp;
    float lightFadeStart;
    float lightFadeEnd;
    std::uint32_t lightingTemplateInheritanceFlags;
};

struct BGSLightingTemplate
{
    float GetNearFogDistance() const;
    float GetFarFogDistance() const;
    float GetLightFadeStart() const;
    float GetLightFadeEnd() const;
    PackedColor GetDirectionalAmbientColor(std::int32_t index) const;
};

struct HandleList
{
    std::uint8_t storage[0x10];
};

struct LOADED_CELL_DATA
{
    std::uint8_t padding00[8];
    NiNode* cell3D;
    std::uint8_t padding10[0xF0];
    HandleList unk100;
    std::uint8_t padding110[0x5C];
    volatile long criticalQueuedRefCount;
    volatile long queuedRefCount;
};

std::uint32_t TESObjectCELL::PackGridKey32(std::int32_t x, std::int32_t y)
{
    const auto high = static_cast<std::int16_t>(x >> 5);
    const auto low = static_cast<std::uint16_t>(y >> 5);
    return (static_cast<std::uint32_t>(high) << 16) | low;
}

std::uint32_t TESObjectCELL::PackGridKey8(std::int32_t x, std::int32_t y)
{
    const auto high = static_cast<std::int16_t>(x >> 3);
    const auto low = static_cast<std::uint16_t>(y >> 3);
    return (static_cast<std::uint32_t>(high) << 16) | low;
}

bool TESObjectCELL::IsPersistentCell() const
{
    return (formFlags >> 10) & 1;
}

EXTERIOR_DATA* TESObjectCELL::GetExteriorData() const
{
    if (cellFlags & kInterior) {
        return nullptr;
    }
    return exterior;
}

INTERIOR_DATA* TESObjectCELL::GetInteriorData() const
{
    if (!(cellFlags & kInterior)) {
        return nullptr;
    }
    return interior;
}

void TESObjectCELL::SetNearFogColor(PackedColor value)
{
    if ((cellFlags & kInterior) && !(cellFlagsHigh & kUseSkyLightingHigh) && interior) {
        interior->fogColorNear = value;
    }
}

void TESObjectCELL::SetFarFogColor(PackedColor value)
{
    if ((cellFlags & kInterior) && !(cellFlagsHigh & kUseSkyLightingHigh) && interior) {
        interior->fogColorFar = value;
    }
}

float TESObjectCELL::GetNearFogDistance() const
{
    if (!(cellFlags & kInterior) || !interior) {
        return 0.0f;
    }
    if ((interior->lightingTemplateInheritanceFlags & INTERIOR_DATA::kFogNear) && lightingTemplate) {
        return lightingTemplate->GetNearFogDistance();
    }
    return interior->fogNear;
}

void TESObjectCELL::SetNearFogDistance(float value)
{
    if ((cellFlags & kInterior) && !(cellFlagsHigh & kUseSkyLightingHigh) && interior) {
        interior->fogNear = value;
    }
}

float TESObjectCELL::GetFarFogDistance() const
{
    if (!(cellFlags & kInterior) || !interior) {
        return 0.0f;
    }
    if ((interior->lightingTemplateInheritanceFlags & INTERIOR_DATA::kFogFar) && lightingTemplate) {
        return lightingTemplate->GetFarFogDistance();
    }
    return interior->fogFar;
}

void TESObjectCELL::SetFarFogDistance(float value)
{
    if ((cellFlags & kInterior) && !(cellFlagsHigh & kUseSkyLightingHigh) && interior) {
        interior->fogFar = value;
    }
}

float TESObjectCELL::GetLightFadeStart() const
{
    if (!(cellFlags & kInterior) || !interior) {
        return 0.0f;
    }
    if ((interior->lightingTemplateInheritanceFlags & INTERIOR_DATA::kLightFadeDistances) && lightingTemplate) {
        return lightingTemplate->GetLightFadeStart();
    }
    return interior->lightFadeStart;
}

float TESObjectCELL::GetLightFadeEnd() const
{
    if (!(cellFlags & kInterior) || !interior) {
        return 0.0f;
    }
    if ((interior->lightingTemplateInheritanceFlags & INTERIOR_DATA::kLightFadeDistances) && lightingTemplate) {
        return lightingTemplate->GetLightFadeEnd();
    }
    return interior->lightFadeEnd;
}

std::int32_t TESObjectCELL::GetCellX() const
{
    return !(cellFlags & kInterior) && exterior ? exterior->cellX : 0;
}

std::int32_t TESObjectCELL::GetCellY() const
{
    return !(cellFlags & kInterior) && exterior ? exterior->cellY : 0;
}

float TESObjectCELL::GetWorldX() const
{
    return !(cellFlags & kInterior) && exterior ? exterior->worldX : 0.0f;
}

float TESObjectCELL::GetWorldY() const
{
    return !(cellFlags & kInterior) && exterior ? exterior->worldY : 0.0f;
}

void TESObjectCELL::GetWorldCoordinates(float& x, float& y) const
{
    if (auto* data = GetExteriorData()) {
        x = data->worldX;
        y = data->worldY;
    } else {
        x = 0.0f;
        y = 0.0f;
    }
}

void TESObjectCELL::SetCellCoordinates(std::int32_t x, std::int32_t y)
{
    if (auto* data = GetExteriorData()) {
        data->cellX = x;
        data->cellY = y;
        data->worldX = static_cast<float>(static_cast<std::int32_t>(static_cast<std::uint32_t>(x) << 12));
        data->worldY = static_cast<float>(static_cast<std::int32_t>(static_cast<std::uint32_t>(y) << 12));
    }
}

PackedColor TESObjectCELL::GetDirectionalAmbientColor(std::int32_t index) const
{
    if (!(cellFlags & kInterior) || !interior) {
        return 0;
    }
    if ((interior->lightingTemplateInheritanceFlags & INTERIOR_DATA::kAmbientColor) && lightingTemplate) {
        return lightingTemplate->GetDirectionalAmbientColor(index);
    }
    return interior->directionalColors[index];
}

NavMeshArray* TESObjectCELL::GetNavMeshes() const
{
    return navMeshes;
}

NiNode* TESObjectCELL::GetCell3D() const
{
    return loadedData ? loadedData->cell3D : nullptr;
}

TESRegion* TESObjectCELL::GetInteriorRegion()
{
    return (cellFlags & kInterior) ? extraList.Function16f930() : nullptr;
}

bool TESObjectCELL::IsOffLimits() const
{
    return (formFlags >> 17) & 1;
}

void TESObjectCELL::SetExteriorWorldSpace(TESWorldSpace* value)
{
    if (!(cellFlags & kInterior)) {
        worldSpace = value;
    }
}

bool TESObjectCELL::IsCellChildType(std::uint8_t type)
{
    switch (type) {
    case 0x3D:
    case 0x3E:
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x48:
    case 0x49:
        return true;
    default:
        return false;
    }
}

bool TESObjectCELL::HasTempData() const
{
    return (cellFlags >> 4) & 1;
}

bool TESObjectCELL::HasSpinLockCount() const
{
    return lockCount != 0;
}

long TESObjectCELL::GetQueuedRefCount() const
{
    return loadedData ? loadedData->queuedRefCount : 0;
}

void TESObjectCELL::IncrementQueuedRefCount()
{
    // Multiple loading tasks update this counter.
    _InterlockedIncrement(&loadedData->queuedRefCount);
}

long TESObjectCELL::GetCriticalQueuedRefCount() const
{
    return loadedData ? loadedData->criticalQueuedRefCount : 0;
}

void TESObjectCELL::IncrementCriticalQueuedRefCount()
{
    // Multiple loading tasks update this counter.
    _InterlockedIncrement(&loadedData->criticalQueuedRefCount);
}

BGSTerrainVisibilityData* TESObjectCELL::GetTerrainVisibility() const
{
    return !(cellFlags & kInterior) ? exterior->lodVisData : nullptr;
}

HandleList* TESObjectCELL::GetLoadedHandleList() const
{
    if (loadedData) {
        return &loadedData->unk100;
    }
    return nullptr;
}

TESForm* TESObjectCELL::GetCellForm() const
{
    return unk0B0;
}
