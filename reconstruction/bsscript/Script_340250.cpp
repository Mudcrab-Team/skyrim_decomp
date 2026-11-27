// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x340250 Script::ClearCachedValues
#include "Script_340250.h"

// Clears all cached global script evaluation values.
void Script::ClearCachedValues()
{
    gScriptCache0 = nullptr;
    gScriptCache1 = nullptr;
    gScriptCache2 = 0;
    gScriptCache3 = nullptr;
    gScriptCache4 = nullptr;
    gScriptCache5 = nullptr;
    gScriptCache6 = nullptr;
    gScriptCache7 = nullptr;
    gScriptCache8 = 0;
}
