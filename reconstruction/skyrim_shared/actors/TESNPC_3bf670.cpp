// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3bf670 TESNPC::GetHairColor
// Adapted bodies: none
#include "TESNPC_3bf670.h"

std::uint32_t TESNPC::GetHairColor() const
{
    ColorForm* hairColor = nullptr;
    if (headRelatedData) {
        hairColor = headRelatedData->hairColor;
    }
    if (!hairColor) {
        TESRace* npcRace = race;
        if (npcRace) {
            FaceRelatedData* face = npcRace->faceRelatedData[IsFemale()];
            if (face) {
                hairColor = face->defaultHairColor;
            }
        }
    }
    if (hairColor) {
        return hairColor->color;
    }
    return 0;
}
