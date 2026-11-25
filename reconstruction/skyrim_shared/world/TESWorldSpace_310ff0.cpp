// 0x310ff0 TESWorldSpace::GetLocationFromPosition
// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: project-authored reconstruction restored from an archived draft.
// TESWorldSpace::GetLocationFromPosition: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Adapted bodies: none.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
#include "TESWorldSpace_310ff0.h"

extern BGSEncounterZone* gDefaultEncounterZone;

std::uint32_t* HashFormKey(std::uint32_t* a_out, std::uint32_t a_key);

BGSLocation* TESWorldSpace::GetLocationFromPosition(const NiPoint3& a_pos) const
{
    const std::uint32_t cellX = FloorToCell(a_pos.x);
    const std::uint32_t cellY = FloorToCell(a_pos.y);
    const std::uint32_t key = (cellX << 16) | (cellY & 0xFFFF);
    std::uint32_t scratch;
    HashFormKey(&scratch, key);
    BGSLocation* found;
    if (locationMap.Find(key, scratch, found) && found) {
        return found;
    }

    BGSLocation* result = location;
    if (!result && encounterZone) {
        BGSEncounterZone* zone = encounterZone;
        // The pointer holds a form id until the record flag says it was resolved.
        if (!TestBit(*reinterpret_cast<const std::uint32_t*>(&formFlags), 3)) {
            scratch = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(zone));
            TESForm::AddCompileIndex(scratch, GetFile(-1));
            zone = static_cast<BGSEncounterZone*>(TESForm::LookupByID(scratch));
        }
        if (zone && zone != gDefaultEncounterZone) {
            result = zone->location;
        }
    }
    return result;
}
