// Source exposure: mixed (pinned image listings, CommonLibSSE-NG declarations, and project cell units).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the community cell and interior data layouts.
// PackGridKey32, PackGridKey8, IsPersistentCell, IsOffLimits, GetExteriorData: GUESS(low)
// GetInteriorData, SetNearFogColor, SetFarFogColor, SetNearFogDistance, SetFarFogDistance: GUESS(low)
// GetNearFogDistance, GetFarFogDistance, GetLightFadeStart, GetLightFadeEnd, GetDirectionalAmbientColor: GUESS(low)
// GetCellX, GetCellY, GetWorldX, GetWorldY, GetWorldCoordinates: GUESS(low)
// SetCellCoordinates, GetNavMeshes, GetCell3D, GetInteriorRegion, HasTempData: GUESS(low)
// HasSpinLockCount, GetTerrainVisibility, GetLoadedHandleList, GetCellForm, SetExteriorWorldSpace: GUESS(low)
// IsCellChildType, GetQueuedRefCount, IncrementQueuedRefCount, GetCriticalQueuedRefCount, IncrementCriticalQueuedRefCount: GUESS(low)
// TESObjectCELL, TESRegion, TESWorldSpace, TESForm, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NavMeshArray, INTERIOR_DATA, EXTERIOR_DATA, BGSLightingTemplate, BGSTerrainVisibilityData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraDataList, LOADED_CELL_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PackedColor, HandleList, padding, kInterior, Function16f930: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class TESRegion;
class TESWorldSpace;
class TESForm;
class NiNode;
class NavMeshArray;
class BGSTerrainVisibilityData;
struct BGSLightingTemplate;
struct LOADED_CELL_DATA;
struct INTERIOR_DATA;
struct EXTERIOR_DATA;
struct HandleList;
using PackedColor = std::uint32_t;

struct ExtraDataList
{
    TESRegion* Function16f930();
    std::uint8_t padding[0x20];
};

class TESObjectCELL
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
    NavMeshArray* GetNavMeshes() const;
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
    // formFlags, cellFlags, extraList, exterior, interior: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // navMeshes, unk0B0, worldSpace, loadedData, lightingTemplate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // kUseSkyLighting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
