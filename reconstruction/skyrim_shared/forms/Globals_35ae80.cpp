// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Cmd_GetPCExpelled_Execute.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:17570
// 0x35ae80 Cmd_GetPCExpelled_Execute
#include "Globals_35ae80.h"

bool Cmd_GetPCExpelled_Execute(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8) {
    void* temp4 = 0;
    if (!Script_ParseParameters(a1, a2, a8, a3, a4, a5, a6, &temp4)) {
        return false;
    }
    Script_GetPCExpelledConditionFunction(a3, temp4, 0, a7);
    return true;
}
