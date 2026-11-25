// Source exposure: mixed (pinned image listings, CommonLibSSE-NG declarations, and project cell units).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the community cell and interior data layouts. Stamped as a twin of matched 0x2bcd60 (skyrim_shared/world/TESObjectCELL_2b9710): source copied, names replaced by placeholders.
// TESRegion, TESWorldSpace, TESForm, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NavMeshArray, INTERIOR_DATA, EXTERIOR_DATA, BGSLightingTemplate, BGSTerrainVisibilityData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraDataList, LOADED_CELL_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PackedColor, HandleList, kInterior: STANDIN GUESS(low)
// Functionf18fb0, Ownerf18fb0: GUESS(low) STANDIN
// PackGridKey32, PackGridKey8, IsPersistentCell, IsOffLimits, GetExteriorData, GetInteriorData, SetNearFogColor, SetFarFogColor, SetNearFogDistance, SetFarFogDistance, GetNearFogDistance, GetFarFogDistance, GetLightFadeStart, GetLightFadeEnd, GetDirectionalAmbientColor, GetCellX, GetCellY, GetWorldX, GetWorldY, GetWorldCoordinates, SetCellCoordinates, GetCell3D, GetInteriorRegion, HasTempData, HasSpinLockCount, GetTerrainVisibility, GetLoadedHandleList, GetCellForm, SetExteriorWorldSpace, IsCellChildType, GetQueuedRefCount, IncrementQueuedRefCount, GetCriticalQueuedRefCount, IncrementCriticalQueuedRefCount, formFlags, cellFlags, extraList, exterior, interior, navMeshes, unk0B0, worldSpace, loadedData, lightingTemplate: GUESS(low) STANDIN
#pragma once
#include "TESObjectCELL_2b9710.h"
#include <intrin.h>

class Ownerf18fb0
{
public:
    static std::uint32_t PackGridKey32(std::int32_t x, std::int32_t y);
    static std::uint32_t PackGridKey8(std::int32_t x, std::int32_t y);
    bool IsPersistentCell() const;
    EXTERIOR_DATA* GetExteriorData() const;
    INTERIOR_DATA* GetInteriorData() const;
    void SetNearFogColor(PackedColor value);
    void SetFarFogColor(PackedColor value);
    float GetNearFogDistance() const;
    void SetNearFogDistance(float value);
    float GetFarFogDistance() const;
    void SetFarFogDistance(float value);
    float GetLightFadeStart() const;
    float GetLightFadeEnd() const;
    std::int32_t GetCellX() const;
    std::int32_t GetCellY() const;
    float GetWorldX() const;
    float GetWorldY() const;
    void GetWorldCoordinates(float& x, float& y) const;
    void SetCellCoordinates(std::int32_t x, std::int32_t y);
    PackedColor GetDirectionalAmbientColor(std::int32_t index) const;
    NavMeshArray* Functionf18fb0() const;
    NiNode* GetCell3D() const;
    TESRegion* GetInteriorRegion();
    bool IsOffLimits() const;
    void SetExteriorWorldSpace(TESWorldSpace* value);
    static bool IsCellChildType(std::uint8_t type);
    bool HasTempData() const;
    bool HasSpinLockCount() const;
    long GetQueuedRefCount() const;
    void IncrementQueuedRefCount();
    long GetCriticalQueuedRefCount() const;
    void IncrementCriticalQueuedRefCount();
    BGSTerrainVisibilityData* GetTerrainVisibility() const;
    HandleList* GetLoadedHandleList() const;
    TESForm* GetCellForm() const;

private:
    // cellFlagsHigh, kUseSkyLightingHigh, lockCount: STANDIN GUESS(low)
    enum : std::uint8_t { kInterior = 1, kUseSkyLightingHigh = 1 };
    std::uint8_t padding00[0x10];
    std::uint32_t formFlags;
    std::uint8_t padding14[0x2C];
    std::uint8_t cellFlags;
    std::uint8_t cellFlagsHigh;
    std::uint8_t padding42[6];
    ExtraDataList extraList;
    union {
        EXTERIOR_DATA* exterior;
        INTERIOR_DATA* interior;
    };
    std::uint8_t padding70[0x10];
    NavMeshArray* navMeshes;
    std::uint8_t padding88[0x30];
    TESForm* unk0B0;
    std::uint8_t paddingC0[0x64];
    std::uint32_t lockCount;
    TESWorldSpace* worldSpace;
    LOADED_CELL_DATA* loadedData;
    BGSLightingTemplate* lightingTemplate;
};

