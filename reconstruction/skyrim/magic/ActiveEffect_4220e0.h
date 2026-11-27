// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// ActiveEffect, ActiveEffect::GetTaperedMagnitude: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class ActiveEffect
{
  public:
    static float GetTaperedMagnitude(float a_magnitude, float a_elapsed, float a_duration, float a_taperWeight, float a_taperCurve);
};
