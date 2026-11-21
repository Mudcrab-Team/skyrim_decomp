// Licence: uses the GetEncounterZone and BGSEncounterZone names from powerof3/CommonLibSSE (see the header), so this file is GPL-3.0.
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local listings of the pinned image
// with types from the header beside this file.
// Bodies adapted from community sources are listed above; tools/check_origin.py reports none other above its threshold at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// 0x2e6f30 TESObjectREFR::GetScale
// 0x2f3b70 TESObjectREFR::GetCurrentLocation
// 0x300b90 TESObjectREFR::GetCalcLevel
// 0x2eee20 TESObjectREFR::GetTransform
// 0x2e73a0 TESObjectREFR::CanBeMoved
// 0x2e5a60 TESObjectREFR::HasQuestObject
// 0x2f0b30 TESObjectREFR::GetReferenceName
// 0x301090 TESObjectREFR::GetTeleportData
// 0x2e8660 TESObjectREFR::GetContainer
// 0x2f3e00 TESObjectREFR::GetWorldSpace
// 0x2ebce0 TESObjectREFR::Get3D2
// 0x2f41e0 TESObjectREFR::GetDistanceBetweenSquared
// 0x2df5b0 TESObjectREFR::ForwardExtraList
// 0x2f6280 TESObjectREFR::QueryExtraList
// ForwardExtraList, QueryExtraList, ExtraDataList::Unk15eb00, ExtraDataList::Unk166af0: GUESS(low)
// Code origin: original; the listing, community declarations and CrashLogger PDB names only
// Adapted bodies: none
// 0x1e64c0 TESObjectREFR::SetRecordFlag13
// 0x2754c0 TESObjectREFR::ResetUnkScale
// 0x2e3c40 TESObjectREFR::UnkIsMovableStaticFlag9
// 0x2e4800 TESObjectREFR::IsDoorInaccessible
// 0x2e4920 TESObjectREFR::SetRecordFlag18
// 0x2e4990 TESObjectREFR::UnkBaseFlag15
// 0x2e49c0 TESObjectREFR::UnkFlag15OrBaseFlag15
// 0x2e49f0 TESObjectREFR::SetRecordFlag15
// 0x2e4a30 TESObjectREFR::SetRecordFlag19
// 0x2e4a60 TESObjectREFR::UnkCellQuery0
// 0x2e4a90 TESObjectREFR::UnkCellQuery1
// 0x2e4ae0 TESObjectREFR::GetTemporarilyPersistent
// 0x2e66b0 TESObjectREFR::IsDragonLandZoneMarker
// 0x2e66e0 TESObjectREFR::IsDragonCrashZoneMarker
// 0x2eeb40 TESObjectREFR::UnkNamedBlockHasName
// 0x2eeb70 TESObjectREFR::UnkNamedBlockQuery
// GetTemporarilyPersistent: CRASHLOGGER_PDB(59818@2026.10.24)
// SetRecordFlag13, SetRecordFlag15, SetRecordFlag18, SetRecordFlag19, ResetUnkScale, UnkIsMovableStaticFlag9, IsDoorInaccessible, UnkBaseFlag15, UnkFlag15OrBaseFlag15, UnkCellQuery0, UnkCellQuery1, UnkNamedBlockHasName, UnkNamedBlockQuery: GUESS(low)
// IsDragonLandZoneMarker, IsDragonCrashZoneMarker: GUESS(low)
#include "TESObjectREFR.h"

#include <limits>


// Globals read by GetCalcLevel; the image keeps them at fixed addresses.
// gDefaultEncounterZone: GUESS(low); RVA 0x31a5728, compared against the reference's zone. meh321 names
// this address gNoZoneZone (id 400884); the name is kept because the TESObjectCELL unit binds the same address under it.
extern BGSEncounterZone* gDefaultEncounterZone;
// gCalcLevelCounter: GUESS(low); RVA 0x31df438, a running 16-bit counter.
extern std::uint16_t gCalcLevelCounter;
// iCalcLevelAdjustUp: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) OBSERVED; RVA 0x207bce0 (id 360558), upper bound for the counter, read as an int
extern int iCalcLevelAdjustUp;
// iCalcLevelAdjustDown: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) OBSERVED; RVA 0x207bcc8 (id 360555), magnitude the counter restarts at (negated), read as 16 bits
extern std::uint16_t iCalcLevelAdjustDown;

float TESObjectREFR::GetScale() const
{
    float           scale = refScale * 0.01f;
    TESBoundObject* base  = data.objectReference;
    if (base && base->formType == FormType::NPC) {
        scale *= static_cast<TESNPC*>(base)->GetScale();
    }
    return scale;
}

BGSLocation* TESObjectREFR::GetCurrentLocation() const
{
    if (formID == 0x14) {
        return PlayerCharacter::singleton->currentLocation;
    }
    if (parentCell) {
        return parentCell->GetLocation();
    }
    TESObjectCELL* cell = GetSaveParentCell();
    if (cell && !(cell->cellFlags & 1) && cell->worldSpace) {
        return cell->worldSpace->GetLocationFromPosition(data.location);
    }
    return extraList.GetExtraLocation();
}

std::uint16_t TESObjectREFR::GetCalcLevel(bool a_adjustLevel) const
{
    BGSEncounterZone* zone = GetEncounterZone();
    std::uint16_t     level;
    if (zone && zone != gDefaultEncounterZone) {
        level = zone->unk44;
        if (level == 0) {
            level = zone->GetLevel();
        }
    } else {
        level = PlayerCharacter::singleton->GetLevel();
    }
    if (a_adjustLevel) {
        // Counter cycles upward and wraps to a negative offset past its limit.
        ++gCalcLevelCounter;
        if (gCalcLevelCounter > iCalcLevelAdjustUp) {
            gCalcLevelCounter = static_cast<std::uint16_t>(-iCalcLevelAdjustDown);
        }
        level += gCalcLevelCounter;
    }
    if (level < 1) {
        return 1;
    }
    return level;
}

void TESObjectREFR::GetTransform(NiTransform& a_transform) const
{
    const Actor* actor = As<Actor>();
    float        x     = actor ? 0.0f : data.angle.x;
    float        y     = actor ? 0.0f : data.angle.y;
    a_transform.rotate.SetEulerAngles(x, y, data.angle.z);
    a_transform.translate.x = data.location.x;
    a_transform.translate.y = data.location.y;
    a_transform.translate.z = data.location.z;
    a_transform.scale       = GetScale();
}

bool TESObjectREFR::CanBeMoved()
{
    if (TESDataHandler::singleton->IsTemporaryFormID(formID)) {
        return true;
    }
    switch (GetBaseObject()->formType) {
    case FormType::Static: {
        TESBoundObject* base = GetBaseObject();
        if (base && base->IsMarker()) {
            return true;
        }
        return false;
    }
    case FormType::StaticCollection:
    case FormType::Tree:
    case FormType::Flora:
    case FormType::Furniture:
        return false;
    default:
        return true;
    }
}

bool TESObjectREFR::HasQuestObject() const
{
    TESBoundObject* base = data.objectReference;
    if (!base) {
        return false;
    }
    const FormType baseType = base->formType;
    if (!GetContainer(base)) {
        return false;
    }
    InventoryChanges* changes = GetInventoryChanges(baseType);
    return changes && changes->HasQuestItem();
}

// tlsOverrideRef, tlsOverrideNode: GUESS(low); per-thread slots at TLS offsets 0x5f8 and 0x5f0 that
// Get3D2 consults before the loaded data: a reference and the node to answer with for it.
extern __declspec(thread) const TESObjectREFR* tlsOverrideRef;
extern __declspec(thread) NiAVObject*          tlsOverrideNode;

const char* TESObjectREFR::GetReferenceName() const
{
    return data.objectReference->GetFormName();
}

DoorTeleportData* TESObjectREFR::GetTeleportData() const
{
    return extraList.GetTeleportData();
}

TESContainer* TESObjectREFR::GetContainer() const
{
    TESBoundObject* base = data.objectReference;
    if (base) {
        switch (base->formType) {
        case FormType::NPC:
            return static_cast<TESNPC*>(static_cast<TESBoundAnimObject*>(base));
        case FormType::Container:
            return static_cast<TESObjectCONT*>(static_cast<TESBoundAnimObject*>(base));
        default:
            break;
        }
    }
    return nullptr;
}

TESWorldSpace* TESObjectREFR::GetWorldSpace() const
{
    TESObjectCELL* cell = parentCell;
    if (!cell) {
        cell = GetSaveParentCell();
        if (!cell) {
            return nullptr;
        }
    }
    if (cell->cellFlags & 1) {
        return nullptr;
    }
    return cell->worldSpace;
}

NiAVObject* TESObjectREFR::Get3D2() const
{
    if (this == tlsOverrideRef) {
        return tlsOverrideNode;
    }
    if (loadedData) {
        return loadedData->data3D;
    }
    return nullptr;
}

float TESObjectREFR::GetDistanceBetweenSquared(const TESObjectREFR* a_other, bool a_ignoreDisabled, bool a_ignoreWorldspace) const
{
    float distance = std::numeric_limits<float>::max();
    if (a_other && !(TestBit(a_other->formFlags, 11) && !a_ignoreDisabled) && !TestBit(a_other->formFlags, 5)) {
        if (a_ignoreWorldspace || SameWorldspace(a_other, true)) {
            const float dx = a_other->data.location.x - data.location.x;
            const float dy = a_other->data.location.y - data.location.y;
            const float dz = a_other->data.location.z - data.location.z;
            distance       = dx * dx + dy * dy + dz * dz;
        }
    }
    return distance;
}

bool TESObjectREFR::GetAllowPromoteToPersistent() const
{
    return true;
}


void TESObjectREFR::ForwardExtraList()
{
    extraList.Unk15eb00(this);
}

void* TESObjectREFR::QueryExtraList() const
{
    const ExtraDataList* list = &extraList;
    return list ? list->Unk166af0() : nullptr;
}

// UnkScaleBlock, UnkNamedBlock: STANDIN GUESS(low); the blocks the two callees return, with the members the bodies read.
struct UnkScaleBlock {
    std::uint8_t unk00[0x8];
    float        scale;  // 08
};

struct BSFixedString {
    bool HasValue() const;
};

struct UnkNamedBlock {
    virtual void  Unk_00();
    virtual void  Unk_01();
    virtual void  Unk_02();
    virtual void  Unk_03();
    virtual void* Unk_04();

    BSFixedString name;  // 08
};

// BGSDefaultObjectManager::GetDefaultObject: GUESS(low); the callee taking a default-object index; kDragonLandZoneMarker and kDragonCrashZoneMarker are its indices 29 and 30
class BGSDefaultObjectManager {
public:
    static TESForm* GetDefaultObject(std::uint32_t a_index);
};

// TES, gTES, TES::UnkCellQuery: STANDIN GUESS(low); the global at RVA 0x32303b8 and its callee at RVA 0x1a2200
class TES {
public:
    bool UnkCellQuery(TESObjectCELL* a_cell, bool a_flag);
};
extern TES* gTES;

void TESObjectREFR::SetRecordFlag13(bool a_set)
{
    if (a_set) {
        formFlags |= 1u << 13;
    } else {
        formFlags &= ~(1u << 13);
    }
}

void TESObjectREFR::ResetUnkScale()
{
    UnkScaleBlock* block = Unk2e7560();
    if (block) {
        block->scale = 1.0f;
    }
}

bool TESObjectREFR::UnkIsMovableStaticFlag9() const
{
    if (data.objectReference->formType == FormType::MovableStatic && (formFlags & (1u << 9))) {
        return true;
    }
    return false;
}

bool TESObjectREFR::IsDoorInaccessible() const
{
    bool result = false;
    if (data.objectReference->formType == FormType::Door) {
        if (formFlags & (1u << 8)) {
            result = true;
        }
    }
    return result;
}

void TESObjectREFR::SetRecordFlag18(bool a_set)
{
    if (a_set) {
        formFlags |= 1u << 18;
    } else {
        formFlags &= ~(1u << 18);
    }
}

bool TESObjectREFR::UnkBaseFlag15() const
{
    bool            result = false;
    TESBoundObject* base   = data.objectReference;
    if (base) {
        if (TestBit(base->formFlags, 15)) {
            result = true;
        }
    }
    return result;
}

bool TESObjectREFR::UnkFlag15OrBaseFlag15() const
{
    if (formFlags & (1u << 15)) {
        return true;
    }
    TESBoundObject* base = data.objectReference;
    if (base && TestBit(base->formFlags, 15)) {
        return true;
    }
    return false;
}

void TESObjectREFR::SetRecordFlag15(bool a_set)
{
    if (a_set) {
        formFlags |= 1u << 15;
    } else {
        formFlags &= ~(1u << 15);
    }
}

void TESObjectREFR::SetRecordFlag19(bool a_set)
{
    if (a_set) {
        formFlags |= 1u << 19;
    } else {
        formFlags &= ~(1u << 19);
    }
}

bool TESObjectREFR::UnkCellQuery0() const
{
    if (!parentCell) {
        return false;
    }
    return gTES->UnkCellQuery(parentCell, false);
}

bool TESObjectREFR::UnkCellQuery1() const
{
    if (!parentCell) {
        return false;
    }
    return gTES->UnkCellQuery(parentCell, true);
}

bool TESObjectREFR::GetTemporarilyPersistent() const
{
    if (TestBit(formFlags, 10) && !TestBit(inGameFormFlags, 6)) {
        return true;
    }
    return false;
}

bool TESObjectREFR::IsDragonLandZoneMarker() const
{
    TESBoundObject* base = data.objectReference;
    return base == BGSDefaultObjectManager::GetDefaultObject(29);
}

bool TESObjectREFR::IsDragonCrashZoneMarker() const
{
    TESBoundObject* base = data.objectReference;
    return base == BGSDefaultObjectManager::GetDefaultObject(30);
}

bool TESObjectREFR::UnkNamedBlockHasName()
{
    UnkNamedBlock* block = Unk2eebe0();
    if (block) {
        return block->name.HasValue();
    }
    return false;
}

void* TESObjectREFR::UnkNamedBlockQuery()
{
    UnkNamedBlock* block = Unk2eebe0();
    if (block) {
        return block->Unk_04();
    }
    return nullptr;
}