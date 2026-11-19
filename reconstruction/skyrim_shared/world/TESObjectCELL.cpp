// Source exposure: mixed (pinned image listing and community declarations; a local decompile informed control flow and is not in the repo).
// Code origin: original reconstruction from the pinned listing and community declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: GPL-3.0-only (declarations adapted from powerof3/CommonLibSSE; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// The names CreateDuplicateForm and IsParentForm come from powerof3/CommonLibSSE 654e55f (GPL-3.0); that licence applies to those functions.
// 0x2bc790 TESObjectCELL::Function2bc790
// 0x2cbed0 TESObjectCELL::EnterReferenceListLock
// 0x2be9b0 TESObjectCELL::GetbhkWorld
// 0x2bc660 TESObjectCELL::GetCoordinates
// 0x2cbef0 TESObjectCELL::ExitReferenceListLock
// 0x2be700 TESObjectCELL::GetEncounterZone
// 0x2be530 TESObjectCELL::GetOwner
// 0x2bb180 TESObjectCELL::GetLocation
#include "TESObjectCELL.h"

void TESObjectCELL::EnterReferenceListLock()
{
    spinLock.Lock();
}

bhkWorld* TESObjectCELL::GetbhkWorld() const
{
    if (cellFlags & 1) {
        return extraList.GetbhkWorld();
    }
    return *gExteriorbhkWorld;
}

void TESObjectCELL::GetCoordinates(std::int32_t& a_x, std::int32_t& a_y)
{
    EXTERIOR_DATA* exterior = (cellFlags & 1) ? nullptr : cellData.exterior;
    if (exterior) {
        a_x = exterior->cellX;
        a_y = exterior->cellY;
        return;
    }
    a_x = 0;
    a_y = 0;
}

void TESObjectCELL::ExitReferenceListLock()
{
    spinLock.Unlock();
}

BGSEncounterZone* TESObjectCELL::GetEncounterZone() const
{
    if (loadedData) {
        return loadedData->encounterZone;
    }
    BGSEncounterZone* zone = extraList.GetEncounterZone();
    if (!zone && !(cellFlags & 1) && worldSpace) {
        zone = worldSpace->encounterZone;
    }
    return zone;
}

TESForm* TESObjectCELL::GetOwner()
{
    TESForm* owner = extraList.GetOwner();
    if (!owner) {
        BGSEncounterZone* zone = GetEncounterZone();
        if (zone && zone != gDefaultEncounterZone) {
            owner = zone->zoneOwner;
        }
    }
    return owner;
}

BGSLocation* TESObjectCELL::GetLocation() const
{
    BGSEncounterZone* zone = GetEncounterZone();
    zone = ResolveFormRef(this, zone);
    if (zone && zone != gDefaultEncounterZone) {
        BGSLocation* location = ResolveFormRef(zone, zone->location);
        if (location) {
            return location;
        }
    }
    BGSLocation* location = extraList.GetExtraLocation();
    if (!location && !(cellFlags & 1) && worldSpace) {
        return worldSpace->GetLocation();
    }
    return location;
}

// CreateDuplicateForm: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
TESForm* TESObjectCELL::CreateDuplicateForm(bool a_createEditorID, void* a_arg2)
{
    return nullptr;
}

// IsParentForm: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
bool TESObjectCELL::IsParentForm()
{
    return true;
}

// GetWorldSpaceOfExteriorCell: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
TESWorldSpace* TESObjectCELL::GetWorldSpaceOfExteriorCell()
{
    if (cellFlags & 1) {
        return nullptr;
    }
    return worldSpace;
}

// NiColor, red, green, blue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiColor {
public:
    float red;
    float green;
    float blue;
};
static_assert(sizeof(NiColor) == 0xC, "Color size");

// CellAmbientColors, values: GUESS(low)
struct CellAmbientColors {
    NiColor values[3][2];
};
static_assert(sizeof(CellAmbientColors) == 0x48, "Directional color size");

// CellLightingContext, lighting, lightingContext, defaultCellColor,
// packedColorScale, BlendLightingTemplate: GUESS(low)
// unknown00, unknown08, unknown10, unknown18, unknown20, unknown28, unknown30, unknown38: GUESS(low)
// unknown40, unknown48, unknown50, unknown58, unknown60, unknown68, unknown70, unknown78: GUESS(low)
// unknown80, unknown88, unknown90, unknown98, unknownA0, unknownA8, unknownB0, unknownB8: GUESS(low)
// unknownC0, unknownC8, unknownD0, unknownD8, unknownE0, unknownE8, unknownF0, unknownF8: GUESS(low)
struct CellLightingContext {
    std::uint64_t unknown00;
    std::uint64_t unknown08;
    std::uint64_t unknown10;
    std::uint64_t unknown18;
    std::uint64_t unknown20;
    std::uint64_t unknown28;
    std::uint64_t unknown30;
    std::uint64_t unknown38;
    std::uint64_t unknown40;
    std::uint64_t unknown48;
    std::uint64_t unknown50;
    std::uint64_t unknown58;
    std::uint64_t unknown60;
    std::uint64_t unknown68;
    std::uint64_t unknown70;
    std::uint64_t unknown78;
    std::uint64_t unknown80;
    std::uint64_t unknown88;
    std::uint64_t unknown90;
    std::uint64_t unknown98;
    std::uint64_t unknownA0;
    std::uint64_t unknownA8;
    std::uint64_t unknownB0;
    std::uint64_t unknownB8;
    std::uint64_t unknownC0;
    std::uint64_t unknownC8;
    std::uint64_t unknownD0;
    std::uint64_t unknownD8;
    std::uint64_t unknownE0;
    std::uint64_t unknownE8;
    std::uint64_t unknownF0;
    std::uint64_t unknownF8;
    void* lighting;
};
static_assert(offsetof(CellLightingContext, lighting) == 0x100, "Lighting context offset");

extern CellLightingContext* lightingContext;
extern const NiColor defaultCellColor;
extern const float packedColorScale;
void BlendLightingTemplate(void*, void*, void*, float, CellAmbientColors&, NiColor&, float&);

void TESObjectCELL::Function2bc790(CellAmbientColors& a_colors, NiColor& a_specular, float& a_fresnelPower) const
{
    const INTERIOR_DATA* interior;
    if (!(cellFlags & 1) || !(interior = cellData.interior)) {
        auto& colors = a_colors.values;
        colors[0][0] = colors[0][1] = colors[1][0] = colors[1][1] =
            colors[2][0] = colors[2][1] = defaultCellColor;
        a_specular = defaultCellColor;
        a_fresnelPower = 1.0f;
        return;
    }

    if ((static_cast<std::uint32_t>(interior->lightingTemplateInheritanceFlags) &
            static_cast<std::uint32_t>(INTERIOR_DATA::Inherit::kAmbientColor)) && lightingTemplate) {
        BlendLightingTemplate(lightingContext->lighting, lightingTemplate, nullptr, 0.0f,
            a_colors, a_specular, a_fresnelPower);
        return;
    }

    const auto& lighting = interior->directionalAmbientLightingColors;
    const float scale = packedColorScale;
    for (unsigned index = 0; index < 7; ++index) {
        const auto axis = static_cast<std::size_t>(index) >> 1;
        const auto direction = index & 1;
        NiColor& output = index == 6 ? a_specular : a_colors.values[axis][direction];
        const std::uint32_t color = lighting.colors[static_cast<int>(index)];
        output.red = static_cast<std::uint8_t>(color) * scale;
        output.green = static_cast<std::uint8_t>(static_cast<std::uint16_t>(color) >> 8) * scale;
        output.blue = static_cast<std::uint8_t>(color >> 16) * scale;
    }
    a_fresnelPower = lighting.fresnelPower;
}
