// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// LockpickingMenu, LockpickingMenu::ModifySweetSpotSize: CRASHLOGGER_PDB(59818@2026.10.24)
// gSweetSpotSkillMult, gSweetSpotBase, gSweetSpotPerkMult, gSweetSpotLevel0, gSweetSpotLevel1, gSweetSpotLevel2, gSweetSpotLevel3, gSweetSpotLevel4: GUESS
#pragma once

#include <cstdint>

extern float gSweetSpotSkillMult;
extern float gSweetSpotBase;
extern float gSweetSpotPerkMult;
extern float gSweetSpotLevel0;
extern float gSweetSpotLevel1;
extern float gSweetSpotLevel2;
extern float gSweetSpotLevel3;
extern float gSweetSpotLevel4;

class LockpickingMenu
{
  public:
    static float ModifySweetSpotSize(float a_skill, std::uint32_t a_lockLevel, std::uint32_t a_perkCount, float a_mult);
};
