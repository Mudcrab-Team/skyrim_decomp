// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// LockpickingMenu, LockpickingMenu::GetPartialPickSize: CRASHLOGGER_PDB(59818@2026.10.24)
// gPartialPickSkillMult, gPartialPickBase, gPartialPickLevel0, gPartialPickLevel1, gPartialPickLevel2, gPartialPickLevel3, gPartialPickLevel4: GUESS
#pragma once

#include <cstdint>

extern float gPartialPickSkillMult;
extern float gPartialPickBase;
extern float gPartialPickLevel0;
extern float gPartialPickLevel1;
extern float gPartialPickLevel2;
extern float gPartialPickLevel3;
extern float gPartialPickLevel4;

class LockpickingMenu
{
  public:
    static float GetPartialPickSize(float a_skill, std::uint32_t a_lockLevel);
};
