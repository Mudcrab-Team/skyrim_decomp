// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x421650 LockpickingMenu::ModifySweetSpotSize
#include "LockpickingMenu_421650.h"

// Computes the modified lockpicking sweet-spot size for skill, lock level, perks, and multiplier.
float LockpickingMenu::ModifySweetSpotSize(float a_skill, std::uint32_t a_lockLevel, std::uint32_t a_perkCount, float a_mult)
{
    const float base = (a_skill * gSweetSpotSkillMult + gSweetSpotBase) * a_mult;
    const float perkBonus = static_cast<float>(a_perkCount) * gSweetSpotPerkMult;
    float mult = 0.0f;
    switch (a_lockLevel)
    {
    case 0:
        mult = gSweetSpotLevel0;
        break;
    case 1:
        mult = gSweetSpotLevel1;
        break;
    case 2:
        mult = gSweetSpotLevel2;
        break;
    case 3:
        mult = gSweetSpotLevel3;
        break;
    case 4:
        mult = gSweetSpotLevel4;
        break;
    }
    return mult * base + perkBonus;
}
