// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// LockpickingMenu, LockpickingMenu::GetSkillUsage: CRASHLOGGER_PDB(59818@2026.10.24)
// gLockpickSkillUse0, gLockpickSkillUse1, gLockpickSkillUse2, gLockpickSkillUse3, gLockpickSkillUse4: GUESS
#pragma once

#include <cstdint>

extern float gLockpickSkillUse0;
extern float gLockpickSkillUse1;
extern float gLockpickSkillUse2;
extern float gLockpickSkillUse3;
extern float gLockpickSkillUse4;

class LockpickingMenu
{
  public:
    static float GetSkillUsage(std::uint32_t a_lockLevel);
};
