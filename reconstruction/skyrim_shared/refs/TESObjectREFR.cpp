// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none in this change.
// 0x6bd530 TESObjectREFR::Function6bd530
// 0x22b2c0 TESObjectREFR::GetInventoryChanges
// Licence: uses the GetEncounterZone and BGSEncounterZone names from powerof3/CommonLibSSE (see the header), so this file is GPL-3.0.
// Existing bodies were drafted by claude-sonnet-5-5 from local listings and the accompanying header.
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
#include "TESObjectREFR.h"

#include <cmath>
#include <limits>

// playerActor, maximumFallSubmersion: GUESS(low); player identity and fall-damage water cutoff.
// playerMinimumFallHeight, playerFallMultiplier, playerFallExponent: GUESS(low); player fall-damage settings.
// npcMinimumFallHeight, npcFallMultiplier, npcFallExponent: GUESS(low); non-player fall-damage settings.
extern Actor* playerActor;
extern const float maximumFallSubmersion;
extern float playerMinimumFallHeight;
extern float playerFallMultiplier;
extern float playerFallExponent;
extern float npcMinimumFallHeight;
extern float npcFallMultiplier;
extern float npcFallExponent;

// BGSEntryPoint, kModFallingDamage, HandleEntryPoint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSEntryPoint {
public:
    // ENTRY_POINT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    enum class ENTRY_POINT : unsigned { kModFallingDamage = 58 };
    static void HandleEntryPoint(ENTRY_POINT a_entry, Actor* a_actor, float* a_value);
};

float TESObjectREFR::Function6bd530(float a_distance, float a_scale)
{
    float damage = 0.0f;
    if (a_distance > damage) {
        if (!(Function685c30(data.location.z, parentCell) >= maximumFallSubmersion)) {
            float minimum;
            float multiplier;
            float exponent;
            if (this == playerActor) {
                minimum = playerMinimumFallHeight;
                multiplier = playerFallMultiplier;
                exponent = playerFallExponent;
            } else {
                minimum = npcMinimumFallHeight;
                multiplier = npcFallMultiplier;
                exponent = npcFallExponent;
            }
            const float threshold = minimum * a_scale;
            if (a_distance > threshold) {
                damage = powf((a_distance - threshold) * multiplier, exponent);
                BGSEntryPoint::HandleEntryPoint(BGSEntryPoint::ENTRY_POINT::kModFallingDamage,
                                               static_cast<Actor*>(this), &damage);
            }
        }
    }
    return damage;
}


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

// RVA 0x22b2c0, 18 bytes. The pinned image guards a null reference and a null list before the delegating call.
// The null-this guard follows the pinned compiler behavior; a null member call is undefined in portable C++.
InventoryChanges* TESObjectREFR::GetInventoryChanges(FormType a_baseType) const
{
    if (this == nullptr) {
        return nullptr;
    }
    const ExtraDataList* list = &extraList;
    if (list == nullptr) {
        return nullptr;
    }
    return list->GetInventoryChanges(a_baseType);
}
