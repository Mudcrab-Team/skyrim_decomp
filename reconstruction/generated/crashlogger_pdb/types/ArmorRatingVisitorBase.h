// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ArmorRatingVisitorBase; size 0x20
#pragma once

#include "IItemChangeVisitor.h"
struct Actor_b2630b95;
struct ArmorRatingVisitorBase {
    IItemChangeVisitor _base;
    Actor_b2630b95* actor;
    float armorSum;
    float armorPerks;
    float lightArmorRating;
    float heavyArmorRating;
};
static_assert(sizeof(ArmorRatingVisitorBase) == 32, "ArmorRatingVisitorBase layout differs from the PDB");
