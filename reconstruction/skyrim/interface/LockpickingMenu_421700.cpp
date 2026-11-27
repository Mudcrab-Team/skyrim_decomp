// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x421700 LockpickingMenu::GetPartialPickSize
#include "LockpickingMenu_421700.h"

// Computes the partial pick zone width for the given lockpicking skill and lock level.
float LockpickingMenu::GetPartialPickSize(float a_skill, std::uint32_t a_lockLevel)
{
    const float base = a_skill * gPartialPickSkillMult + gPartialPickBase;
    float mult = 0.0f;
    switch (a_lockLevel)
    {
    case 0:
        mult = gPartialPickLevel0;
        break;
    case 1:
        mult = gPartialPickLevel1;
        break;
    case 2:
        mult = gPartialPickLevel2;
        break;
    case 3:
        mult = gPartialPickLevel3;
        break;
    case 4:
        mult = gPartialPickLevel4;
        break;
    }
    return mult * base;
}
