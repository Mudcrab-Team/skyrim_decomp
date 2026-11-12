// TESObjectREFR member functions, build sse-steam-1-7-104.
//
// Labels: v2
// Evidence: findings/third-batch-selection.md.
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local listings of the pinned image
// with types from the header beside this file.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Compared functions (RVA, size):
//   GetScale           RVA 0x2e6f30, 68 bytes
//   GetCurrentLocation RVA 0x2f3b70, 117 bytes
//   GetCalcLevel       RVA 0x300b90, 143 bytes
//   GetTransform       RVA 0x2eee20, 152 bytes
//   CanBeMoved         RVA 0x2e73a0, 84 bytes
//   HasQuestObject     RVA 0x2e5a60, 86 bytes
// CanBeMoved and HasQuestObject were finished by claude-opus-5-5 from the Drafter's near-misses.
// A byte match shows this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
#include "TESObjectREFR.h"


// Globals read by GetCalcLevel; the image keeps them at fixed addresses.
// gDefaultEncounterZone: GUESS(low); RVA 0x31a5728, compared against the reference's zone.
extern BGSEncounterZone* gDefaultEncounterZone;
// gCalcLevelCounter: GUESS(low); RVA 0x31df438, a running 16-bit counter.
extern std::uint16_t gCalcLevelCounter;
// gCalcLevelCounterMax: GUESS(low); RVA 0x207bce0, upper bound for the counter.
extern int gCalcLevelCounterMax;
// gCalcLevelCounterReset: GUESS(low); RVA 0x207bcc8, magnitude the counter restarts at (negated).
extern std::uint16_t gCalcLevelCounterReset;

float TESObjectREFR::GetScale() const
{
    float           scale = refScale * 0.01f;
    TESBoundObject* base  = data.objectReference;
    if (base && base->formType == FormType::NPC) {
        scale *= static_cast<TESNPC*>(base)->GetHeightScale();
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
        return cell->worldSpace->LookupLocation(data.location);
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
            level = zone->GetLevelFromData();
        }
    } else {
        level = PlayerCharacter::singleton->GetLevel();
    }
    if (a_adjustLevel) {
        // Counter cycles upward and wraps to a negative offset past its limit.
        ++gCalcLevelCounter;
        if (gCalcLevelCounter > gCalcLevelCounterMax) {
            gCalcLevelCounter = static_cast<std::uint16_t>(-gCalcLevelCounterReset);
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
    if (TESDataHandler::singleton->IsMovableFormID(formID)) {
        return true;
    }
    switch (GetBaseObject()->formType) {
    case FormType::Static: {
        TESBoundObject* base = GetBaseObject();
        if (base && base->Unk_42()) {
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
    InventoryChanges* changes = FindInventoryChanges(baseType);
    return changes && changes->HasQuestItem();
}
