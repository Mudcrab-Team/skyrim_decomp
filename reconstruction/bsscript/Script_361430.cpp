// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x361430 Script::EvaluateSpellConditionsFunction
#include "Script_361430.h"

// Evaluates active spell conditions on a reference's MagicTarget if present.
bool Script::EvaluateSpellConditionsFunction(void* a_param1, void* a_param2, TESObjectREFR* a_thisObj)
{
    (void)a_param1;
    (void)a_param2;
    MagicTarget* target = a_thisObj->GetMagicTarget();
    if (target)
    {
        EvaluateMagicTargetConditions(target);
    }
    return true;
}
