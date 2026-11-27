// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x4215f0 LockpickingMenu::GetSkillUsage
#include "LockpickingMenu_4215f0.h"

// Returns the lockpicking skill usage value configured for the given lock level.
float LockpickingMenu::GetSkillUsage(std::uint32_t a_lockLevel)
{
    float result = 0.0f;
    switch (a_lockLevel)
    {
    case 0:
        result = gLockpickSkillUse0;
        break;
    case 1:
        result = gLockpickSkillUse1;
        break;
    case 2:
        result = gLockpickSkillUse2;
        break;
    case 3:
        result = gLockpickSkillUse3;
        break;
    case 4:
        result = gLockpickSkillUse4;
        break;
    }
    return result;
}
